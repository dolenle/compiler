#include "quad.h"

int functionCount = 0;
int blockCount = 1;
int tempCount = 1;
int stringCount = 1;

block* currentBlock = NULL;
qnode* loop_break = NULL;
qnode* loop_continue = NULL;

char* opcodeText[] = { //opcode strings used by print function
	"MOV",
	"LOAD",
	"LEA",
	"STOR",
	"CMP",
	"BR",
	"BRGT",
	"BRGE",
	"BRLT",
	"BRLE",
	"BREQ",
	"BRNE",
	"INC",
	"DEC",
	"MUL",
	"DIV",
	"MOD",
	"ADD",
	"SUB",
    "SHL",
    "SHR",
    "AND",
    "XOR",
    "IOR",
    "NOT",
    "LOGAND",
    "LOGOR",
    "LOGNOT",
    "CALL",
    "ARGNUM",
    "ARGDEF",
    "RETURN"
};

//create a new basic block
block* bb_newBlock(int funcID, int id, block* prev) {
	block* b = malloc(sizeof(block));
	if(!b) {
		fprintf(stderr, "Unable to allocate memory for basic block\n");
		return NULL;
	}
	b->prev = prev;
	if(prev) {
		prev->next = b;
	}
	b->funcID = funcID;
	b->blockID = id;
	b->top = NULL;
	b->bottom = NULL;
	b->branch1 = NULL;
	b->branch2 = NULL;
	b->br_type = BR_DEFAULT;
	b->name = malloc(10);
	sprintf(b->name, ".BB.%i.%i", b->funcID, b->blockID);
	return b;
}

//Add the quad to the specified basic block
block* bb_appendQuad(block* b, quad* q) {
	if(b->top && b->bottom) {
		quad* temp = b->bottom;
		temp->next = q;
		b->bottom = q;
	} else if(!b->top && !b->bottom) {
		b->top = q;
		b->bottom = q;
	} else {
		printf("Error (bb_append): Inconsistent Basic Block\n");
	}
}

//Create new quad node
qnode* qnode_new(qnodeType type) {
	qnode* q = malloc(sizeof(qnode));
	if(!q){
		fprintf(stderr, "Unable to allocate memory for quad node\n");
		return NULL;
	}
	q->type = type;
	q->name = malloc(256);
	q->pos = NULL; 
	return q;
}

quad* emit(opcode op, qnode* dest, qnode* src1, qnode* src2) {
	//printf("EMIT\n");
	quad *q = malloc(sizeof(quad));
	if(!q){
		fprintf(stderr, "Unable to allocate memory for quad\n");
		return NULL;
	}
	q->op = op;
	q->dest = dest;
	q->source1 = src1;
	q->source2 = src2;

	bb_appendQuad(currentBlock, q);

	return q;
}

block* function_block(node* body, int print) {
	blockCount = 1;
	currentBlock = bb_newBlock(++functionCount, blockCount, currentBlock);
	block* tmp = currentBlock;
	stmt_list_parse(body);
	if(!currentBlock->bottom || currentBlock->bottom->op != O_RETURN) { //default return
		emit(O_RETURN, NULL, NULL, NULL);
	}
	if(print)
		print_blocks(tmp);
	return tmp;
}

void stmt_list_parse(node* list) {
	while(list) {
		if(list && list->type == LIST_NODE) {
			node* n = list->u.list.start;
			if(n->type == ASSIGN_NODE) {
				//printf("generating assignment quad in BB %s\n", currentBlock->name);
				gen_assign(n);
			} else if(n->type == BINOP_NODE) {
				gen_rvalue(n, NULL);
			} else if(n->type == UNOP_NODE) {
				gen_rvalue(n, NULL);
			} else if(n->type == IF_NODE || n->type == IFELSE_NODE) {
				gen_if(n);
			} else if(n->type == FOR_NODE) {
				gen_for(n);
			} else if(n->type == WHILE_NODE) {
				gen_while(n);
			} else if(n->type == JUMP_NODE) {
				gen_jmp(n);
			} else if(n->type == CALL_NODE) { //Function Call
				int argnum = n->u.call.argnum;
				qnode* num = qnode_new(Q_CONSTANT);
				num->name = malloc(100);
				sprintf(num->name, "%i", argnum);
				num->u.value = argnum;
				emit(O_ARGNUM, NULL, num, NULL);
				if(argnum) { //Generate argument quad
					node* argptr = n->u.call.args;
					while(argptr) {
						emit(O_ARGDEF, NULL, gen_rvalue(argptr->u.list.start, NULL), NULL);
						if(argptr->next) {
							argptr = argptr->next;
						} else {
							break;
						}
					}
				}
				emit(O_CALL, NULL, gen_rvalue(n->u.call.function, NULL), NULL);
			} else if(n->type == IDENT_NODE || n->type == DEFAULT_NODE) {
				//do nothing
			} else {
				printf("QUAD ERROR: Unrecognized Node Type %i\n", n->type);
				exit(1);
			}
			if(list->next) {
				list = list->next;
			} else {
				break;
			}
		} else {
			printf("QUAD ERROR: Invalid Statement List\n");
			break;
		}
	}
}

qnode* gen_rvalue(node* n, qnode* target) {
	switch(n->type) {
		case IDENT_NODE: {
			qnode* q = qnode_new(Q_IDENT);
			q->name = n->u.ident.id;
			q->u.ast = n;
			q->pos = &(n->u.ident.pos);
			if(n->next->type == SCALAR_NODE || n->next->type == POINTER_NODE) {			
				if(target && target->type == Q_IDENT) {
					if(target->u.ast->next->type == SCALAR_NODE) {
						emit(O_MOV, target, q, NULL);
					}
				}
				return q;
			} else if(n->next->type == ARRAY_NODE) {
				qnode* dest = new_temp();
				emit(O_LEA, dest, q, NULL);
				return dest;
			} else if(n->next->type == FUNCTION_NODE) {
				return q;
			} else {
				printf("RVAL Unimplemented IDENT\n");
			}
			break;
		}
		case NUMBER_NODE: {
			qnode* q = qnode_new(Q_CONSTANT);
			sprintf(q->name, "%lli", n->u.number.value);
			q->u.value = n->u.number.value;
			if(target && target->type == Q_IDENT) {
				if(target->u.ast->next->type == SCALAR_NODE) {
					emit(O_MOV, target, q, NULL);
				}
			}
			return q;
			break;
		}
		case UNOP_NODE: {
			switch(n->u.unop.type) {
				case DEREF_OP: {
					if(n->u.unop.operand->type == ARRAY_NODE) {
						return gen_rvalue(n->u.unop.operand, target);
					}
					qnode* addr = gen_rvalue(n->u.unop.operand, NULL);
					if(!target) target = new_temp();
					emit(O_LOAD, target, addr, NULL);
					return target;
				}
				case POSTINC_OP: {
					qnode* q = gen_rvalue(n->u.unop.operand, NULL);
					if(!target) target = new_temp();
					emit(O_MOV, target, q, NULL);
					emit(O_INC, NULL, q, NULL);
					return target;
				}
				case POSTDEC_OP: {
					qnode* q = gen_rvalue(n->u.unop.operand, NULL);
					if(!target) target = new_temp();
					emit(O_MOV, target, q, NULL);
					emit(O_DEC, NULL, q, NULL);
					return target;
				}
				case PREINC_OP: {
					qnode* q = gen_rvalue(n->u.unop.operand, NULL);
					emit(O_INC, NULL, q, NULL);
					return q;
				}
				case PREDEC_OP: {
					qnode* q = gen_rvalue(n->u.unop.operand, NULL);
					emit(O_DEC, NULL, q, NULL);
					return q;
				}
				case LOGNOT_OP: {					
					block* bt = bb_newBlock(functionCount, ++blockCount, currentBlock);
					block* bf = bb_newBlock(functionCount, ++blockCount, bt);
					block* bn = bb_newBlock(functionCount, ++blockCount, bf);
					if(!target) target = new_temp();
					
					qnode* zero = qnode_new(Q_CONSTANT);
					zero->name = strdup("0");
					zero->u.value = 0;
					qnode* one = qnode_new(Q_CONSTANT);
					one->name = strdup("1");
					one->u.value = 1;
										
					gen_cond(n->u.unop.operand, blockToQnode(bt), blockToQnode(bf));
					currentBlock->next = bt; //reset next block in case it has changed
					bt->prev = currentBlock;
					currentBlock = bt;
					emit(O_MOV, target, zero, NULL);
					emit(O_BR, NULL, blockToQnode(bn), NULL);
					currentBlock = bf;
					emit(O_MOV, target, one, NULL);
					emit(O_BR, NULL, blockToQnode(bn), NULL);
					currentBlock = bn;
					return target;
				}
				case ADDR_OP: {
					if(!target) target = new_temp();
					emit(O_LEA, target, gen_rvalue(n->u.unop.operand, NULL), NULL);
					return target;
				}
				case NEG_OP: {
					if(!target) target = new_temp();
					qnode* val = gen_rvalue(n->u.unop.operand, NULL);
					qnode* one = qnode_new(Q_CONSTANT);
					one->name = strdup("-1");
					one->u.value = -1;
					emit(O_MUL, target, one, val);
					return target;
				}
				case POS_OP: {
					return gen_rvalue(n->u.unop.operand, NULL); //not much to do...
				}
				case SIZEOF_OP: {
					int size = 0;
					if(n->u.unop.operand->type == IDENT_NODE) {
						if(n->u.unop.operand->next->type == ARRAY_NODE) { //compute size
							node* a = n->u.unop.operand->next;
							size = a->u.array.length;
							while(a->next && a->next->type == ARRAY_NODE) {//multidimensional
								a = a->next;
								size *= a->u.array.length;
							}
							size *= sizeof(int);
						} else { //assume its an int or ptr (same size)
							size = sizeof(int);
						}
					} else if(n->u.unop.operand->type == POINTER_NODE) {
						size = sizeof(void*);
					} else if(n->u.unop.operand->type == SCALAR_NODE) {
						size = sizeof(int); //only supporting ints
					} else {
						printf("RVAL unimplemented SIZEOF (type %i)\n", n->u.unop.operand->type);
						exit(1);
					}
					qnode* q = qnode_new(Q_CONSTANT);
					sprintf(q->name, "%i", size);
					q->u.value = size;
					if(target && target->type == Q_IDENT) {
						if(target->u.ast->next->type == SCALAR_NODE) {
							emit(O_MOV, target, q, NULL);
						}
					}
					return q;
				}
				default:
					printf("RVAL Unimplemented UNOP %i\n", n->u.unop.type);
			}
			break;
		}
		case BINOP_NODE: {
			//boolean expression
			if((n->u.binop.type >= LT_OP && n->u.binop.type <= NOTEQ_OP) || n->u.binop.type >= LOGOR_OP) {
				if(!target) target = new_temp();
				block* temp = currentBlock;
				block* bt = bb_newBlock(functionCount, ++blockCount, currentBlock);
				block* bf = bb_newBlock(functionCount, ++blockCount, bt);
				block* bn = bb_newBlock(functionCount, ++blockCount, bf);
				
				//create qnodes for the above blocks
				qnode* trueBlock = blockToQnode(bt);
				qnode* falseBlock = blockToQnode(bf);
				qnode* nextBlock = blockToQnode(bn);

				//qnodes for zero and one
				qnode* zero = qnode_new(Q_CONSTANT);
				zero->name = strdup("0");
				zero->u.value = 0;
				qnode* one = qnode_new(Q_CONSTANT);
				one->name = strdup("1");
				one->u.value = 1;

				gen_cond(n, trueBlock, falseBlock); //evaluate expression
				currentBlock = bt; //true
				emit(O_MOV, target, one, NULL);
				emit(O_BR, NULL, nextBlock, NULL);
				currentBlock = bf; //false
				emit(O_MOV, target, zero, NULL);
				emit(O_BR, NULL, nextBlock, NULL);
				
				currentBlock = bn;
				return target;
			} else {
				qnode* left = gen_rvalue(n->u.binop.left, NULL);
				qnode* right = gen_rvalue(n->u.binop.right, NULL);
				if(n->u.binop.left->type == IDENT_NODE && n->u.binop.left->next->type == ARRAY_NODE) {
					qnode* temp = new_temp();
					qnode* size = qnode_new(Q_CONSTANT);
					int nextType = n->u.binop.left->next->next->type;
					if(nextType == SCALAR_NODE) {
						sprintf(size->name, "%li", sizeof(int));
						size->u.value = (long long) sizeof(int);
					} else if(nextType == POINTER_NODE || nextType == ARRAY_NODE) {
						sprintf(size->name, "%li", sizeof(int*));
						size->u.value = (long long) sizeof(int*);
					} else {
						printf("QUAD ERROR, unimplemented sizeof\n");
					}
					emit(O_MUL, temp, right, size);
					right = temp;
				}
				if(!target) target = new_temp();
				emit(getBinop(n->u.binop.type), target, left, right);
				return target;
			}
		}
		case CALL_NODE: {
			if(n->u.call.function) {
				int argnum = n->u.call.argnum;
				qnode* num = qnode_new(Q_CONSTANT);
				num->name = malloc(64);
				sprintf(num->name, "%i", argnum);
				num->u.value = argnum;
				emit(O_ARGNUM, NULL, num, NULL);
				if(argnum) { //Generate argument quad
					node* argptr = n->u.call.args;
					while(argptr) {
						emit(O_ARGDEF, NULL, gen_rvalue(argptr->u.list.start, NULL), NULL);
						if(argptr->next) {
							argptr = argptr->next;
						} else {
							break;
						}
					}
				}
				if(!target) target = new_temp();
				emit(O_CALL, target, gen_rvalue(n->u.call.function, NULL), NULL);
				return target;
			} else {
				printf("Error: Call Node RVALUE\n");
			}
			break;
		}
		case STRING_NODE: {
			qnode* str = qnode_new(Q_STRING);
			str->name = malloc(64);
			sprintf(str->name, ".S%i", stringCount++);
			str->u.ast = n;
			if(target && target->type == Q_IDENT) {
				if(target->u.ast->next->type == POINTER_NODE) {
					emit(O_MOV, target, str, NULL);
					return target;
				}
			} else {
				return str;
			}
		}
		default:
			printf("Error: Cannot generate RVALUE for AST node type %i\n", n->type);
			exit(1);
	}
	return NULL;
}

qnode* gen_lvalue(node* node, int* flag) {
	switch(node->type) {
		case IDENT_NODE:
			if(node->next->type == SCALAR_NODE || node->next->type == POINTER_NODE) {
				qnode* q = qnode_new(Q_IDENT);
				q->name = node->u.ident.id;
				q->u.ast = node;
				q->pos = &(node->u.ident.pos);
				*flag = 0; //direct assignment
				return q;
			} else {
				printf("LVAL Unimplemented IDENT->%i \n", node->next->type);
			}
			break;
		case NUMBER_NODE: {
			return NULL;
		}
		case UNOP_NODE: {
			if(node->u.unop.type == DEREF_OP) {
				*flag = 1; //indirect assignment via ptr
				return gen_rvalue(node->u.unop.operand, NULL);
			} else {
				printf("LVAL Unimplemented UNOP\n");
			}
		}
		default:
			printf("Error: Cannot generate LVALUE for AST node type %i\n", node->type);
			exit(1);
	}
}

//Generate quads for assignment
qnode* gen_assign(node* a) {
	if(a->type == ASSIGN_NODE) {
		node* right = a->u.assign.right;
		if(a->u.assign.type != EQ_OP) { //convert assignment
			node* b = ast_newNode(BINOP_NODE);
			b->u.binop.type = assignToBinop(a->u.assign.type);
			b->u.binop.left = a->u.assign.left;
			b->u.binop.right = right;
			right = b;
		}
		int flag;
		qnode* dest = gen_lvalue(a->u.assign.left, &flag);
		if(flag == 0) { //direct
			//printf("direct assign flag\n");
			return gen_rvalue(right, dest);
		} else if(flag == 1) { //indirect
			qnode* rval = gen_rvalue(right, NULL);
			emit(O_STOR, NULL, rval, dest);
			return dest;
		}
	} else {
		printf("QUAD ERROR: Expected assignment node\n");
	}
}

//Generate quads for IF statement
void gen_if(node* start) {
	//printf("%s\n", "processing IF NODE");
	block* bt = bb_newBlock(functionCount, ++blockCount, currentBlock); //true bb
	block* bf = bb_newBlock(functionCount, ++blockCount, bt); //false bb
	block* bn; //next bb
	qnode* trueBlock = blockToQnode(bt);
	qnode* falseBlock = blockToQnode(bf);
	qnode* nextBlock;
	block* temp = currentBlock;
	if(start->type == IF_NODE) {
		bn = bf;
		gen_cond(start->u.if_stmt.condition, trueBlock, falseBlock);
	} else if(start->type == IFELSE_NODE) {
		bn = bb_newBlock(functionCount, ++blockCount, bf);
		gen_cond(start->u.ifelse_stmt.condition, trueBlock, falseBlock);
	} else {
		printf("QUAD ERROR: Not an If/else node\n");
		return;
	}
	nextBlock = blockToQnode(bn);
	if(currentBlock != temp) {
		currentBlock->next = bt;
	}
	currentBlock = bt; //begin true block
	stmt_list_parse(start->u.if_stmt.if_block); //same for both if and ifelse
	emit(O_BR, NULL, nextBlock, NULL); //unconditional jump
	
	if(start->type == IFELSE_NODE) {
		if(currentBlock != bt) { //additional blocks were added
			currentBlock->next = bf;
		}
		
		currentBlock = bf; //false (else) block
		stmt_list_parse(start->u.ifelse_stmt.else_block);
		emit(O_BR, NULL, nextBlock, NULL);
		
		if(currentBlock != bf) { //additional blocks were added
			currentBlock->next = bn;
		}
	} if(currentBlock != bt) { //additional blocks were added
		currentBlock->next = bn;
	}
	
	//printf("current block %s, setting to bn (%s)\n", currentBlock->name, bn->name);
	currentBlock = bn;
}

//Generate quads for WHILE and DO-WHILE loop
void gen_while(node* start) {
	//printf("processing WHILE\n");
	if(start->type == WHILE_NODE) {
		block *cond, *body, *next;
		if(start->u.while_stmt.do_stmt) { //do-while loop
			body = bb_newBlock(functionCount, ++blockCount, currentBlock);
			cond = bb_newBlock(functionCount, ++blockCount, body);
			next = bb_newBlock(functionCount, ++blockCount, cond);
		} else { //regular while loop
			cond = bb_newBlock(functionCount, ++blockCount, currentBlock);
			body = bb_newBlock(functionCount, ++blockCount, cond);
			next = bb_newBlock(functionCount, ++blockCount, body);
		}
		
		qnode* b = blockToQnode(body);
		qnode* c = blockToQnode(cond);
		qnode* n = blockToQnode(next);
		qnode* last_break = loop_break;
		loop_break = n;
		
		currentBlock = cond;
		gen_cond(start->u.while_stmt.condition, b, n);
		if(currentBlock != cond) { //reset block pts if more blocks were added
			if(start->u.while_stmt.do_stmt) { //do-while loop
				currentBlock->next = next;
				next->prev = currentBlock;
			} else {
				currentBlock->next = body; //while loop
				body->prev = currentBlock;
			}
		}
		
		currentBlock = body;
		stmt_list_parse(start->u.while_stmt.body);
		if(currentBlock != body) { //more blocks were added
			if(start->u.while_stmt.do_stmt) { //do-while loop
				currentBlock->next = cond;
			} else {
				currentBlock->next = next; //while loop
			}
		}
		emit(O_BR, NULL, c, NULL);
		
		currentBlock = next;
		loop_break = last_break;
		
	} else {
		printf("QUAD ERROR: Not a while loop\n");
	}
}

//Generate quads for FOR loop
void gen_for(node* start) {
	if(start->type == FOR_NODE) {
		block* init = bb_newBlock(functionCount, ++blockCount, currentBlock);
		block* body = bb_newBlock(functionCount, ++blockCount, init);
		block* after = bb_newBlock(functionCount, ++blockCount, body); 
		block* next = bb_newBlock(functionCount, ++blockCount, after);

		qnode* b = blockToQnode(body);
		qnode* a = blockToQnode(after);
		qnode* n = blockToQnode(next);
		qnode* last_break = loop_break;
		loop_break = n;

		currentBlock = init;
		stmt_list_parse(start->u.for_stmt.init);
		gen_cond(start->u.for_stmt.condition, b, n);
		if(currentBlock != init) { //additional blocks added
			currentBlock->next = body;
		}

		currentBlock = body;
		stmt_list_parse(start->u.for_stmt.body);
		emit(O_BR, NULL, a, NULL);
		if(currentBlock != body) { //additional blocks added
			currentBlock->next = after;
		}

		currentBlock = after;
		if(start->u.for_stmt.afterthought)
			stmt_list_parse(start->u.for_stmt.afterthought);
		gen_cond(start->u.for_stmt.condition, b, n);
		if(currentBlock != after) { //additional blocks added
			currentBlock->next = next;
		}

		currentBlock = next;
		loop_break = last_break;
	} else {
		printf("QUAD ERROR: Not a for loop\n");
	}
}

//Generate compare and branch quads
void gen_cond(node* expr, qnode* t, qnode* f) {
	//printf("Processing conditional\n");
	if(expr->type == BINOP_NODE) {
		switch(expr->u.binop.type) {
			case LT_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRLT, NULL, t, f);
				return;
			case GT_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRGT, NULL, t, f);
				return;
			case LTEQ_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRLE, NULL, t, f);
				return;
			case GTEQ_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRGE, NULL, t, f);
				return;
			case EQEQ_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BREQ, NULL, t, f);
				return;
			case NOTEQ_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRNE, NULL, t, f);
				return;
			case LOGOR_OP: { //short circuit OR
				block* temp = currentBlock;
				block* bi = bb_newBlock(functionCount, ++blockCount, currentBlock); //intermediate block
				currentBlock->next = bi;
				t->u.block->prev = bi;
				bi->next = t->u.block;
				bi->prev = currentBlock;
				gen_cond(expr->u.binop.left, t, blockToQnode(bi)); //test left expr
				currentBlock = bi;
				gen_cond(expr->u.binop.right, t, f); //test right expr
				currentBlock = temp;
				return;
			}
			case LOGAND_OP: { //short circuit AND
				block* temp = currentBlock;
				block* bi = bb_newBlock(functionCount, ++blockCount, currentBlock); //intermediate block
				currentBlock->next = bi;
				t->u.block->prev = bi;
				bi->next = t->u.block;
				bi->prev = currentBlock;
				gen_cond(expr->u.binop.left, blockToQnode(bi), f); //test left expr
				currentBlock = bi;
				gen_cond(expr->u.binop.right, t, f); //test right expr
				currentBlock = temp;
				return;
			}
			default: {
				break;
			}
		}
	}
	//gen_cond for non-conditional expr
	qnode* val = gen_rvalue(expr, NULL);
	qnode* zero = qnode_new(Q_CONSTANT);
	zero->name = strdup("0");
	zero->u.value = 0;
	emit(O_CMP, NULL, val, zero);
	emit(O_BRNE, NULL, t, f);
}

void gen_jmp(node* start) {
	if(start->type == JUMP_NODE) {
		if(start->u.jump.type == RETURN_JP) {
			qnode* val = NULL;
			if(start->u.jump.target) {
				val = gen_rvalue(start->u.jump.target, NULL);
			}
			emit(O_RETURN, NULL, val, NULL); //emit return quad
		} else if(start->u.jump.type == BREAK_JP) {
			if(loop_break) {
				emit(O_BR, NULL, loop_break, NULL);
			} else {
				printf("Unexpected BREAK\n");
			}
		} else {
			printf("GOTO and CONTINUE not currently implemented...\n");
		}
	} else {
		printf("QUAD ERROR: Not a jump statement\n");
	}
}

//Traverse BB linked list and print
void print_blocks(block* b) {
	while(b) {
		printf("\n%s\n", b->name);
		quad* q = b->top;
		while(q) {
			printf("\t");
			if(q->dest) {
				printf("%s", q->dest->name);
				if(q->dest->type == Q_IDENT) {
					if(q->dest->u.ast->type == IDENT_NODE) {
						if(q->dest->u.ast->u.ident.stor == SG_STATIC) {
							printf("<gl>");
						} else if(q->dest->u.ast->u.ident.stor == SG_AUTO) {
							printf("<at>");
						}
					} else {
						printf("IDENT quad not linked to IDENT NODE!\n");
					}
				}
				printf(" =\t");
			} else {
				printf("\t");
			}
			printf("%s\t", opcodeText[q->op]);
			if(q->source1) {
				printf("%s\t", q->source1->name);
			} else {
				printf("\t");
			}
			if(q->source2) {
				printf("%s\n", q->source2->name);
			} else {
				printf("\n");
			}
			if(q->next && q != b->bottom) {
				q = q->next;
			} else {
				//printf("end of BB %s\n", b->name);
				break;
			}
		}
		if(b->next) {
			b = b->next;
		} else {
			break;
		}
	}
}

//New temporary register qnode
qnode* new_temp() {
	qnode* q = qnode_new(Q_TEMPORARY);
	sprintf(q->name, "%%T%i", tempCount);
	q->u.tempID = tempCount++;
	q->pos = malloc(sizeof(int));
	*(q->pos) = -1;
	return q;
}

//Convert basic block to quad node
qnode* blockToQnode(block* b) {
	qnode* q = qnode_new(Q_LABEL);
	q->name = strdup(b->name);
	q->u.block = b;
	return q;
}

opcode getBinop(binopType binop) {
	switch(binop) {
		case MULT_OP:
			return O_MUL;
		case DIV_OP:
			return O_DIV;
		case MOD_OP:
			return O_MOD;
		case PLUS_OP:
			return O_ADD;
		case MINUS_OP:
			return O_SUB;
		case SHL_OP:
			return O_SHL;
		case SHR_OP:
			return O_SHR;
		case AND_OP:
			return O_AND;
		case XOR_OP:
			return O_XOR;
		case IOR_OP:
			return O_IOR;
		case LOGOR_OP:
			return O_LOGOR;
		case LOGAND_OP:
			return O_LOGAND;
	}
}

opcode assignToBinop(assignType assign) {
	switch(assign) {
		case TIMESEQ_OP:
			return MULT_OP;
		case DIVEQ_OP:
			return DIV_OP;
		case MODEQ_OP:
			return MOD_OP;
		case PLUSEQ_OP:
			return PLUS_OP;
		case MINUSEQ_OP:
			return MINUS_OP;
		case SHLEQ_OP:
			return SHL_OP;
		case SHREQ_OP:
			return SHR_OP;
		case ANDEQ_OP:
			return AND_OP;
		case OREQ_OP:
			return IOR_OP;
		case XOREQ_OP:
			return O_XOR;
	}
}

// int main() {

// }
