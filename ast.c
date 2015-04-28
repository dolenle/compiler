#include "ast.h"
#include "myParser.tab.h"

node* newASTNode(nodeType type) {
	node* newNode;
	if(!(newNode=malloc(sizeof(node)))) {
		fprintf(stderr, "Error: Cannot allocate AST node memory.\n");
		return NULL;
	}
	newNode->type = type;
	return newNode;
}

node* newASTChild(nodeType type, node* parent, nodeBranch branch) {
	node* newNode = newASTNode(type);
	// if(branch == LEFT) {
		// parent->left = newNode;
	// } else if(branch == RIGHT) {
		// parent->right = newNode;
	// }
	// newNode->parent = parent;
	return newNode;
}

int main() {

	return 0;
}