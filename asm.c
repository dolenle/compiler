#include "globls.h"
#include "quad.h"
#include "asm.h"

char* format_operand(qnode* qn) {
	switch(qn->type) {
		case Q_IDENT: {
			break;
		}
		case Q_TEMPORARY: {
			char* s = malloc(128);
			sprintf(s, "-%i(%%ebp)", 4*qn->u.tempID);
			return s;
		}
		case Q_CONSTANT: {
			char* s = malloc(128);
			sprintf(s, "$%li", qn->u.value);
			return s;
		}
		case Q_LABEL: { //just return basic block name
			return qn->u.block->name;
		}
		default: {
			printf("ASM Error: could not resolve QNODE type\n");
		}
	}
}

int main() {

}