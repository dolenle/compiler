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
	CALL_NODE,
	JUMP_NODE,
	LIST_NODE,
	STRING_NODE
} nodeType;

//Define structs for the various node types

typedef struct node_ident {
	namespaceType ns;
	int line;
	char* id;
	storageType stor;
	node* next;
	int pos;
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
	node* params_top;
	node* params_bot;
	node* body;
} node_func;

typedef struct node_num {
	long long value;
	numType typeFlag;
	signType signFlag;
} node_num;

typedef struct node_binop {
	node* left;
	node* right;
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

typedef struct node_for {
	node* init;
	node* condition;
	node* afterthought;
	node* body;
} node_for;

typedef struct node_while {
	node* condition;
	node* body;
	char do_stmt; //0 if while, 1 if do-while
} node_while;

typedef struct node_call {
	node* function;
	node* args;
	int argnum;
} node_call;

typedef struct node_jump {
	jumpType type;
	node* target;
} node_jump;

typedef struct node_list {
	node* start;
} node_list;

typedef struct node_string {
	char* value;
} node_string;

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
		node_for for_stmt;
		node_while while_stmt;
		node_call call;
		node_jump jump;
		node_list list;
		node_string string;
	} u;
};

//Creates a new AST node of the specified type, with no associations.
node* ast_newNode(nodeType type);

void initAST(struct ast *a);
struct ast prependNode(struct ast a, node* t);
struct ast appendNode(struct ast a, node* t);
struct ast prependAST(struct ast a, struct ast b);
struct ast appendAST(struct ast a, struct ast b);

#endif