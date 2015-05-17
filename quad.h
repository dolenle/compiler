#ifndef _QUAD_H
#define _QUAD_H

#include "globls.h"
#include "ast.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct quad quad;
typedef struct block block;

extern int functionCount;
extern int blockCount;
extern int tempCount;
extern block* currentBlock;

typedef enum opcode {
	O_MOV,
	O_LOAD,
	O_LEA, //load effective address
	O_STOR,
	O_CMP, //compare
	O_BR, //unconditional branch
	O_BRGT, //branch if greater than
	O_BRGE, //branch if less than
	O_BRLT,
	O_BRLE,
	O_BREQ, //10
	O_BRNE,
	O_INC,
	O_DEC,
	O_MUL,
	O_DIV,
	O_MOD,
	O_ADD,
	O_SUB,
    O_SHL,
    O_SHR,
    O_AND,
    O_XOR,
    O_IOR,
    O_NOT, //bitwise not
    O_LOGAND,
    O_LOGOR,
    O_LOGNOT,
    O_CALL,
    O_ARGNUM,
    O_ARGDEF,
    O_RETURN
} opcode;

typedef enum qnodeType {
	Q_IDENT,
	Q_TEMPORARY,
	Q_CONSTANT
} qnodeType;

typedef struct qnode {
	qnodeType type;
	char* name;
	union {
		node* ast;
		int tempID;
		long int value;
	} u;
} qnode;

struct quad {
	opcode op;
	qnode* dest;
	qnode* source1;
	qnode* source2;
	quad* next;
};

struct block {
	quad* top;
	quad* bottom;
	block* prev;
	block* next;
	int funcID;
	int blockID;
	char* name;
};

quad* emit(opcode op, qnode* dest, qnode* src1, qnode* src2);
block* bb_begin(int funcID, int id, block* prev);
block* bb_appendQuad(block* b, quad* q);
qnode* qnode_new(qnodeType type);
qnode* gen_rvalue(node* node, qnode* target);
qnode* gen_lvalue(node* node, int* flag);
qnode* gen_assign(node* node);
opcode getBinop(binopType binop);
qnode* new_temp();


#endif