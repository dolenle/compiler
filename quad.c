#include "quad.h"

int functionCount = 0;
int blockCount = 1;
int tempCount = 1;
block* currentBlock = NULL;

char* opcodeText[] = {
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
	b->name = malloc(10);
	sprintf(b->name, ".BB.%i.%i", b->funcID, b->blockID);
	return b;
}

block* bb_appendQuad(block* b, quad* q) {
	if(b->top && b->bottom) {
		quad* temp = b->bottom;
		temp->next = q;
		b->bottom = q;
	} else if(!b->top && !b->bottom) {
		b->top = q;
		b->bottom = q;
	} else {
		printf("Inconsistent Basic Block\n");
	}
}

qnode* qnode_new(qnodeType type) {
	qnode* q = malloc(sizeof(qnode));
	if(!q){
		fprintf(stderr, "Unable to allocate memory for quad node\n");
		return NULL;
	}
	q->type = type;
	q->name = malloc(256);
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

void function_block(node* body) {
	blockCount = 1;
	currentBlock = bb_newBlock(++functionCount, blockCount, currentBlock);
	block* tmp = currentBlock;
	stmt_list_parse(body);
	print_blocks(tmp);
}

void stmt_list_parse(node* list) {
	while(list) {
		if(list && list->type == LIST_NODE) {
			node* n = list->u.list.start;
			if(n->type == ASSIGN_NODE) {
				//printf("generating assignment quad...\n");
				gen_assign(n);
			} else if(n->type == BINOP_NODE) {
				gen_rvalue(n, NULL);
			} else if(n->type == UNOP_NODE) {
				gen_rvalue(n, NULL);
			} else if(n->type == IF_NODE || n->type == IFELSE_NODE) {
				gen_if(n);
			} else if(n->type == FOR_NODE) {
				gen_for(n);
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

qnode* gen_rvalue(node* node, qnode* target) {
	switch(node->type) {
		case IDENT_NODE: {
			qnode* q = qnode_new(Q_IDENT);
			q->name = node->u.ident.id;
			q->u.ast = node;
			if(node->next->type == SCALAR_NODE || node->next->type == POINTER_NODE) {			
				return q;
			} else if(node->next->type == ARRAY_NODE) {
				qnode* dest = new_temp();
				emit(O_LEA, dest, q, NULL);
				return dest;
			} else {
				printf("RVAL Unimplemented IDENT\n");
			}
			break;
		}
		case NUMBER_NODE: {
			//printf("RVAL-CONST\n");
			qnode* q = qnode_new(Q_CONSTANT);
			sprintf(q->name, "%lli", node->u.number.value);
			q->u.value = node->u.number.value;
			if(target && target->type == Q_IDENT) {
				if(target->u.ast->next->type == SCALAR_NODE) {
					emit(O_MOV, target, q, NULL);
				}
			}
			return q;
			break;
		}
		case UNOP_NODE: {
			switch(node->u.unop.type) {
				case DEREF_OP: {
					qnode* addr = gen_rvalue(node->u.unop.operand, NULL);
					if(!target) target = new_temp();
					emit(O_LOAD, target, addr, NULL);
					return target;
				}
				case POSTINC_OP: {
					qnode* q = gen_rvalue(node->u.unop.operand, NULL);
					if(!target) target = new_temp();
					emit(O_MOV, target, q, NULL);
					emit(O_INC, NULL, q, NULL);
					return target;
				}
				case POSTDEC_OP: {
					qnode* q = gen_rvalue(node->u.unop.operand, NULL);
					if(!target) target = new_temp();
					emit(O_MOV, target, q, NULL);
					emit(O_DEC, NULL, q, NULL);
					return target;
				}
				case PREINC_OP: {
					qnode* q = gen_rvalue(node->u.unop.operand, NULL);
					emit(O_INC, NULL, q, NULL);
					return q;
				}
				case PREDEC_OP: {
					qnode* q = gen_rvalue(node->u.unop.operand, NULL);
					emit(O_DEC, NULL, q, NULL);
					return q;
				}

				default:
					printf("RVAL Unimplemented UNOP\n");
			}
			break;
		}
		case BINOP_NODE: {
			//boolean expression
			if((node->u.binop.type >= LT_OP && node->u.binop.type <= NOTEQ_OP) || node->u.binop.type >= LOGOR_OP) {
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

				gen_cond(node, trueBlock, falseBlock); //evaluate expression
				currentBlock = bt; //true
				emit(O_MOV, target, one, NULL);
				emit(O_BR, NULL, nextBlock, NULL);
				currentBlock = bf; //false
				emit(O_MOV, target, zero, NULL);
				emit(O_BR, NULL, nextBlock, NULL);
				
				currentBlock = bn;
				return target;
			} else {
				qnode* left = gen_rvalue(node->u.binop.left, NULL);
				qnode* right = gen_rvalue(node->u.binop.right, NULL);
				if(node->u.binop.left->type == IDENT_NODE && node->u.binop.left->next->type == ARRAY_NODE) {
					qnode* temp = new_temp();
					qnode* size = qnode_new(Q_CONSTANT);
					int nextType = node->u.binop.left->next->next->type;
					if(nextType == SCALAR_NODE) {
						sprintf(size->name, "%li", sizeof(long long int));
						size->u.value = (long long) sizeof(long long int);
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
				emit(getBinop(node->u.binop.type), target, left, right);
				return target;
			}
		}
	}
	return NULL;
}

qnode* gen_lvalue(node* node, int* flag) {
	switch(node->type) {
		case IDENT_NODE:
			if(node->next->type == SCALAR_NODE) {
				qnode* q = qnode_new(Q_IDENT);
				q->name = node->u.ident.id;
				q->u.ast = node;
				*flag = 0; //direct assignment
				return q;
			} else {
				printf("LVAL Unimplemented IDENT");
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
				printf("LVAL Unimplemented UNOP");
			}
		}
	}
}

qnode* gen_assign(node* a) {
	if(a->type == ASSIGN_NODE) {
		node* right = a->u.assign.right;
		if(a->u.assign.type != EQ_OP) { //conver assignment
			node* b = ast_newNode(BINOP_NODE);
			b->u.binop.type = assignToBinop(a->u.assign.type);
			b->u.binop.left = a->u.assign.left;
			b->u.binop.right = right;
			right = b;
		}
		int flag;
		qnode* dest = gen_lvalue(a->u.assign.left, &flag);
		if(flag == 0) { //direct
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

void gen_if(node* start) {
	block* bt = bb_newBlock(functionCount, ++blockCount, currentBlock);
	block* bf = bb_newBlock(functionCount, ++blockCount, bt);
	block* bn;
	qnode* trueBlock = blockToQnode(bt);
	qnode* falseBlock = blockToQnode(bf);
	qnode* nextBlock;
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
	currentBlock = bt; //begin true block
	stmt_list_parse(start->u.if_stmt.if_block); //same for both if and ifelse
	emit(O_BR, NULL, nextBlock, NULL); //unconditional jump

	if(start->type == IFELSE_NODE) {
		currentBlock = bf; //false (else) block
		stmt_list_parse(start->u.ifelse_stmt.else_block);
		emit(O_BR, NULL, nextBlock, NULL);
	}
	currentBlock = bn;
}

void gen_for(node* start) {
	if(start->type == FOR_NODE) {
		block* init = bb_newBlock(functionCount, ++blockCount, currentBlock);
		block* body = bb_newBlock(functionCount, ++blockCount, init);
		block* after = bb_newBlock(functionCount, ++blockCount, body); 
		block* next = bb_newBlock(functionCount, ++blockCount, after);

		qnode* b = blockToQnode(body);
		qnode* a = blockToQnode(after);
		qnode* n = blockToQnode(next);

		currentBlock = init;
		stmt_list_parse(start->u.for_stmt.init);
		gen_cond(start->u.for_stmt.condition, b, n);

		currentBlock = body;
		stmt_list_parse(start->u.for_stmt.body);
		emit(O_BR, NULL, a, NULL);

		currentBlock = after;
		if(start->u.for_stmt.afterthought)
			stmt_list_parse(start->u.for_stmt.afterthought);
		gen_cond(start->u.for_stmt.condition, b, n);

		currentBlock = next;
	} else {
		printf("QUAD ERROR: Not a for loop\n");
	}
}

void gen_cond(node* expr, qnode* t, qnode* f) {
	if(expr->type == BINOP_NODE) {
		switch(expr->u.binop.type) {
			case LT_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRLT, NULL, t, f);
				break;
			case GT_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRGT, NULL, t, f);
				break;
			case LTEQ_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRLE, NULL, t, f);
				break;
			case GTEQ_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRGE, NULL, t, f);
				break;
			case EQEQ_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BREQ, NULL, t, f);
				break;
			case NOTEQ_OP:
				emit(O_CMP, NULL, gen_rvalue(expr->u.binop.left, NULL), gen_rvalue(expr->u.binop.right, NULL));
				emit(O_BRNE, NULL, t, f);
				break;
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
				break;
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
				break;
			}
			default: {
				qnode* val = gen_rvalue(expr, NULL);
				qnode* zero = qnode_new(Q_CONSTANT);
				zero->name = strdup("0");
				zero->u.value = 0;
				emit(O_CMP, NULL, val, zero);
				emit(O_BRNE, NULL, t, f);
			}
		}
	}
}

void print_blocks(block* b) {
	while(b) {
		printf("\n%s\n", b->name);
		quad* q = b->top;
		while(q) {
			printf("\t");
			if(q->dest) {
				printf("%s =\t", q->dest->name);
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
			//printf("%s = %s %s, %s\n", q->dest?q->dest->name:"NULL", opcodeText[q->op], q->source1?q->source1->name:"NULL", q->source2?q->source2->name:"NULL");
			if(q->next && q != b->bottom) {
				q = q->next;
			} else {
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

qnode* new_temp() {
	qnode* q = qnode_new(Q_TEMPORARY);
	sprintf(q->name, "%%T%i", tempCount);
	q->u.tempID = tempCount++;
	return q;
}

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
