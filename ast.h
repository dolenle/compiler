#ifndef _AST_H
#define _AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef enum nodeType {
	VAR_NODE=0,	
	FUNC_NODE,
	STOR_NODE,
	SCALAR_NODE,
	NUM_NODE,
	STRNG_NODE,
	CHAR_NODE,
	PTR_NODE,
	ARRY_NODE,
	BIOP_NODE,
	UOP_NODE,
	EQUALS_NODE,
	CALL_NODE,
	IF_NODE,
	DO_NODE,
	WHILE_NODE,
	FOR_NODE,
	SWITCH_NODE
} nodeType;

typedef enum nodeBranch {
	LEFT_NODE=0,
	RIGHT_NODE,
	NEXT_NODE,
	CONDITION_NODE,
	BODY_NODE
} nodeBranch;

//Define structs for the various node types
typedef struct node_var {
	int type;
	long long int intVal;
	long double realVal;
	int size;
	char* ident;
} node_var;

typedef struct node_func {
	
} node_func;

typedef struct node_stor {
	
} node_stor;

typedef struct node_scalar {
	
} node_scalar;

typedef struct node_number {
	
} node_number;

typedef struct node {
	nodeType type;
	union {
		node_var var;
		node_func func;
		node_stor stor;
		node_scalar scalar;
		node_number number;
	} attr;
} node;

//Creates a new AST node of the specified type, with no associations.
node* newASTNode(nodeType type);

//Creates a new AST node and attaches it to the specified parent
node* newASTChild(nodeType type, node* parent, nodeBranch branch);

#endif