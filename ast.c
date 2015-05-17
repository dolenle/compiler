#include "ast.h"

node* ast_newNode(nodeType type) {
	node* newNode;
	if(!(newNode=malloc(sizeof(node)))) {
		fprintf(stderr, "Error: Cannot allocate AST node memory.\n");
		return NULL;
	}
	newNode->type = type;
	return newNode;
}

void initAST(struct ast *a) {
	a->topNode = NULL;
	a->botNode = NULL;
	a->errorFlag = 0;
}

struct ast prependNode(struct ast a, node* t) {
	node* currentTop = a.topNode;
	t->next = currentTop;
	a.topNode = t;
	if(!a.botNode) {
		a.botNode = t;
	}
	return a;
}

struct ast appendNode(struct ast a, node* t) {
	if(a.botNode) {
		node* currentBot = a.botNode;
		currentBot->next = t;
	}
	a.botNode = t;
	if(!a.topNode) {
		a.topNode = t;
	}
	return a;
}

struct ast prependAST(struct ast a, struct ast b) {
	a = prependNode(a, b.botNode);
	a.topNode = b.topNode;
	return a;
}

struct ast appendAST(struct ast a, struct ast b) {
	a = appendNode(a, b.topNode);
	a.botNode = b.botNode;
	return a;
}