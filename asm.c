#include "globls.h"
#include "quad.h"
#include "ast.h"
#include "asm.h"

int lSize = sizeof(long);
int nextOffset = 0;

char* format_operand(qnode* qn) {
	switch(qn->type) {
		case Q_IDENT: {
			if(qn->u.ast->type == IDENT_NODE) {
				if(qn->u.ast->u.ident.stor == SG_STATIC) {
					return qn->u.ast->u.ident.id;
				} else if(qn->u.ast->u.ident.stor == SG_AUTO) {
					char* s = malloc(128);
					if(qn->pos == -1) {
						sprintf(s, "-%i(%%ebp)", nextOffset);
						qn->pos = nextOffset;
						//if(qn->u.ast->u.)
					} else {
						sprintf(s, "-%i(%%ebp)", qn->pos);
					}
					return s;
				}
			} else {
				printf("IDENT quad not linked to IDENT NODE!\n");
				exit(0);
			}
			break;
		}
		case Q_TEMPORARY: {
			char* s = malloc(128);
			if(qn->pos == -1) { //allocate
				sprintf(s, "-%i(%%ebp)", nextOffset);
				qn->pos = nextOffset;
				nextOffset += lSize;
			} else { //already allocated
				sprintf(s, "-%i(%%ebp)", qn->pos);
			}
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

void* translate_quad(quad* q) {
	switch(q->op) {
		case O_MOV: {
			printf("\tmovl %s, %%eax\n", format_operand(q->source1));
            printf("\tmovl %%eax, %s\n", format_operand(q->dest));
            break;
		}
		case O_LOAD: {
			printf("\tmovl %s, %%eax\n", format_operand(q->source1));
            printf("\tmovl (%%eax), %%edx\n");
            printf("\tmovl %%edx, %s\n", format_operand(q->dest));
            break;
		}
		case O_LEA: { //load effective address
		
		}
		case O_STOR: {
		
		}
		case O_CMP: { //compare
		
		}
		case O_BR: { //unconditional branch
		
		}
		case O_BRGT: { //branch if greater than
		
		}
		case O_BRGE: { //branch if less than
		
		}
		case O_BRLT: {
		
		}
		case O_BRLE: {
		
		}
		case O_BREQ: { //10
		
		}
		case O_BRNE: {
		
		}
		case O_INC: {
		
		}
		case O_DEC: {
		
		}
		case O_MUL: {
		
		}
		case O_DIV: {
		
		}
		case O_MOD: {
		
		}
		case O_ADD: {
		
		}
		case O_SUB: {
	    
		}
		case O_SHL: {
	    
		}
		case O_SHR: {
	    
		}
		case O_AND: {
	    
		}
		case O_XOR: {
	    
		}
		case O_IOR: {
	    
		}
		case O_NOT: { //bitwise not
	    
		}
		case O_LOGAND: {
	    
		}
		case O_LOGOR: {
	    
		}
		case O_LOGNOT: {
	    
		}
		case O_CALL: {
	    
		}
		case O_ARGNUM: {
	    
		}
		case O_ARGDEF: {
	    
	    }
	    case O_RETURN: {

	    }
	}
}

int main() {

}