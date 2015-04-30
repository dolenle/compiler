#ifndef _AST_H
#define _AST_H

#include "globls.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef enum nodeType {
	DEFAULT_NODE=0,
	IDENT_NODE,
	SCALAR_NODE,
	FUNCTION_NODE
} nodeType;

//Define structs for the various node types

typedef struct node_ident {
	struct node* next;
	namespaceType ns;
	int line;
} node_ident;

typedef struct node_scalar {
	enum scalarType type;
	int size;
} node_scalar;

typedef struct node_func {
	enum numType typeFlag;
	int isInline;
	int isDefined;
} node_func;

struct node {
	nodeType type;
	union {
		node_ident ident;
		node_scalar scalar;
		node_func function;
	} u;
};

//Creates a new AST node of the specified type, with no associations.
node* ast_newNode(nodeType type);

#endif