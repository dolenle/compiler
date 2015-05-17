#include "quad.h"

int functionCount = 1;
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

	printf("%s = %s %s, %s\n", dest?dest->name:"NULL", opcodeText[op], src1?src1->name:"NULL", src2?src2->name:"NULL");
	return q;
}

void function_block(node* list) {
	blockCount = 1;
	currentBlock = bb_newBlock(functionCount++, blockCount, currentBlock);
	while(list) {
		if(list && list->type == LIST_NODE) {
			node* n = list->u.list.start;
			if(n->type == ASSIGN_NODE) {
				printf("generating assignment quad...\n");
				gen_assign(n);
			} else if(n->type == BINOP_NODE) {
				gen_rvalue(n, NULL);
			}
			if(list->next) {
				list = list->next;
			} else {
				break;
			}
		} else {
			printf("ERROR: Invalid Function Body");
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
				printf("RVAL Unimplemented IDENT");
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
			if(node->u.unop.type == DEREF_OP) {
				qnode* addr = gen_rvalue(node->u.unop.operand, NULL);
				if(!target) {
					target = new_temp();
				}
				emit(O_LOAD, target, addr, NULL);
				return target;
			} else {
				printf("RVAL Unimplemented UNOP");
			}
			break;
		}
		case BINOP_NODE: {
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
					sprintf(size->name, "%li", sizeof(long long int*));
					size->u.value = (long long) sizeof(long long int*);
				} else {
					printf("Error, unimplemented sizeof\n");
				}
				emit(O_MUL, temp, right, size);
				right = temp;
			}
				if(!target) {
					target = new_temp();
				}
				emit(getBinop(node->u.binop.type), target, left, right);
				return target;
			
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

qnode* gen_assign(node* node) {
	if(node->type == ASSIGN_NODE) {
		int flag;
		qnode* dest = gen_lvalue(node->u.assign.left, &flag);
		if(flag == 0) { //direct
			printf("direct assign\n");
			return gen_rvalue(node->u.assign.right, dest);
		} else if(flag == 1) { //indirect
			qnode* right = gen_rvalue(node->u.assign.right, NULL);
			emit(O_STOR, NULL, right, dest);
			return dest;
		}
	} else {
		printf("ERROR: Expected assignment node\n");
	}
}

qnode* new_temp() {
	qnode* q = qnode_new(Q_TEMPORARY);
	sprintf(q->name, "%%T%i", tempCount);
	q->u.tempID = tempCount++;
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

// int main() {

// }
