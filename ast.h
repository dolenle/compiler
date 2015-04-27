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
	SCALR_NODE,
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

typedef struct node {
	nodeType type;
	struct node* left;
	struct node* right;
	struct node* next;
	struct node* cond;
	struct node* body;
	struct attr {
		char filename[128];
		int linestart;
		char identifier[128];
		char str[2048];
	        
		int yynum; 
	} attr;
} node;

node* createNode(int type);

struct ast_node * ast_reverse_tree(struct ast_node *root, int dir);

struct ast_node * ast_push_back(struct ast_node *root, struct ast_node *new_node, int dir);

int ast_list_size(struct ast_node *root, int dir);

void ast_dump(struct ast_node *root, char *fn_name);

void ast_print_node(struct ast_node *root);

void ast_print_tree(struct ast_node *root);

#endif