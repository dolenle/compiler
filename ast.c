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