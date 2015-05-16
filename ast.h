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
	STORAGE_NODE,
	POINTER_NODE,
	ARRAY_NODE,
	FUNCTION_NODE,
	NUMBER_NODE,
	BINOP_NODE,
	UNOP_NODE,
	ASSIGN_NODE,
	IF_NODE,
	IFELSE_NODE,
	FOR_NODE,
	WHILE_NODE,
	LIST_NODE
} nodeType;

//Define structs for the various node types

typedef struct node_ident {
	namespaceType ns;
	int line;
	char* id;
	storageType stor;
	node* next;
} node_ident;

typedef struct node_scalar {
	enum scalarType type;
	int size;
} node_scalar;

typedef struct node_storage {
	enum storageType type;
} node_storage;

typedef struct node_ptr {
	struct node* next;
} node_ptr;

typedef struct node_array {
	int length;
} node_array;

typedef struct node_func {
	struct node* params_top;
	struct node* params_bot;
} node_func;

typedef struct node_num {
	long long value;
	numType typeFlag;
	signType signFlag;
} node_num;

typedef struct node_binop {
	node* lvalue;
	node* rvalue;
	binopType type;
} node_binop;

typedef struct node_unop {
	node* operand;
	unopType type;
} node_unop;

typedef struct node_assign {
	node* left;
	node* right;
	assignType type;
} node_assign;

typedef struct node_if {
	node* condition;
	node* if_block;
} node_if;

typedef struct node_ifelse {
	node* condition;
	node* if_block;
	node* else_block;
} node_ifelse;

typedef struct node_list {
	node* start;
} node_list;

struct node {
	nodeType type;
	struct node* next;
	union {
		node_ident ident;
		node_scalar scalar;
		node_storage storage;
		node_ptr pointer;
		node_array array;
		node_func function;
		node_num number;
		node_binop binop;
		node_unop unop;
		node_assign assign;
		node_if if_stmt;
		node_ifelse ifelse_stmt;
		node_list list;
	} u;
};

//Creates a new AST node of the specified type, with no associations.
node* ast_newNode(nodeType type);

#endif