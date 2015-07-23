#include "globls.h"
#include "quad.h"
#include "ast.h"
#include "asm.h"

int lSize = sizeof(long);
int nextOffset = 0;

//generate the address of the quad argument, allocating memory as necessary
//for IDENT, offset is stored in the AST union
//for TEMP, offset is stored independently
char* format_operand(qnode* qn) {
	switch(qn->type) {
		case Q_IDENT: {
			if(qn->u.ast->type == IDENT_NODE) {
				if(qn->u.ast->u.ident.stor == SG_STATIC) {
					return qn->u.ast->u.ident.id;
				} else if(qn->u.ast->u.ident.stor == SG_AUTO) {
					char* s = malloc(128);
					if(*(qn->pos) == -1) {
						printf("\t\t# Allocating offset %i to IDENT %s\n", nextOffset, qn->u.ast->u.ident.id);
						*(qn->pos) = nextOffset;
						node* n = qn->u.ast->next;
						nextOffset += get_ident_offset(n);
					}
					sprintf(s, "-%i(%%ebp)", *(qn->pos));
					return s;
				} else {
					printf("ASM Error: Unimplemented storage class\n");
				}
			} else {
				printf("IDENT quad not linked to IDENT NODE!\n");
				exit(0);
			}
			break;
		}
		case Q_TEMPORARY: {
			char* s = malloc(128);
			if(*(qn->pos) == -1) { //allocate space in stack frame
				printf("\t\t# Allocating offset %i to %%T%i\n", nextOffset, qn->u.tempID);
				*(qn->pos) = nextOffset;
				nextOffset += lSize;
			}
			sprintf(s, "-%i(%%ebp)", *(qn->pos));
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

int get_ident_offset(node* n) {
	switch(n->type) { //determine size of the variable
		case SCALAR_NODE: {
			if(n->u.scalar.type == S_INT || n->u.scalar.type == S_LONG) {
				return lSize;
			} else {
				printf("Come on. We've been over this. Integer types only. This ain't called C-- for nothing.\n");
			}
			break;
		}
		case POINTER_NODE: {
			return sizeof(int*);
			break;
		}
		case ARRAY_NODE: {
			return n->u.array.length * get_ident_offset(n->next); //tricky tricky
			break;
		}
		default: {
			printf("Error: cannot get offset for node type %i\n", n->type);
		}
	}
}

void translate_quad(quad* q) {
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
			printf("\tleal %s, %%edx\n", format_operand(q->source1));
			printf("\tmovl %%edx, %s\n", format_operand(q->dest));
			break;
		}
		case O_STOR: {
			printf("\tmovl %s, %%eax\n", format_operand(q->source2));
			printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			printf("\tmovl %%edx, (%%eax)\n");
			break;
		}
		case O_CMP: { //compare
			printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			printf("\tcmpl %s, %%eax\n", format_operand(q->source2));
			break;
		}
		case O_BR: { //unconditional branch
			printf("\tjmp %s\n", format_operand(q->source1));
			break;
		}
		case O_BRGT: { //branch if greater than
			printf("\tjg %s\n", format_operand(q->source1));
			printf("\tjmp %s\n", format_operand(q->source2));
			break;
		}
		case O_BRGE: { //branch if less than
			printf("\tjge %s\n", format_operand(q->source1));
			printf("\tjmp %s\n", format_operand(q->source2));
			break;
		}
		case O_BRLT: {
			printf("\tjl %s\n", format_operand(q->source1));
			printf("\tjmp %s\n", format_operand(q->source2));
			break;
		}
		case O_BRLE: {
			printf("\tjle %s\n", format_operand(q->source1));
			printf("\tjmp %s\n", format_operand(q->source2));
			break;
		}
		case O_BREQ: { //10
			printf("\tje %s\n", format_operand(q->source1));
			printf("\tjmp %s\n", format_operand(q->source2));
			break;
		}
		case O_BRNE: {
			printf("\tjg %s\n", format_operand(q->source1));
			printf("\tjmp %s\n", format_operand(q->source2));
			break;
		}
		case O_INC: {
			printf("\tincl %s\n", format_operand(q->source1));
			break;
		}
		case O_DEC: {
			printf("\tdecl %s\n", format_operand(q->source1));
			break;
		}
		case O_MUL: {
			printf("\tmovl %s, %%eax\n", format_operand(q->source2));
			printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			printf("\timull %%edx\n");
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));
			break;
		}
		case O_DIV: {
			printf("\tmovl $0, %%edx\n");           //most significant 4 bytes
			printf("\tmovl %s, %%eax\n", format_operand(q->source1));       //least sig 4 bytes
			printf("\tmovl %s, %%ecx\n", format_operand(q->source2));       //least sig 4 bytes
			printf("\tidivl %%ecx\n");
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));    //result
			break;
		}
		case O_MOD: {
			printf("\tmovl $0, %%edx\n");           //most significant 4 bytes
			printf("\tmovl %s, %%eax\n", format_operand(q->source1));       //least sig 4 bytes
			printf("\tmovl %s, %%ecx\n", format_operand(q->source2));       //least sig 4 bytes
			printf("\tidivl %%ecx\n");
			printf("\tmovl %%edx, %s\n", format_operand(q->dest));    //result
			break;
		}
		case O_ADD: {
			printf("\tmovl %s, %%eax\n", format_operand(q->source2));
			printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			printf("\taddl %%eax, %%edx\n");
			printf("\tmovl %%edx, %s\n", format_operand(q->dest));
			break;
		
		}
		case O_SUB: {
	    	printf("\tmovl %s, %%eax\n", format_operand(q->source2));
			printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			printf("\tsubl %%eax, %%edx\n");
			printf("\tmovl %%edx, %s\n", format_operand(q->dest));
			break;
		}
		case O_SHL: {
			printf("\tmovl %%ebx, %%edx\n");
			printf("\tmovl %s, %%ebx\n", format_operand(q->source1));
			printf("\tmovl %s, %%ecx\n", format_operand(q->source2));
			printf("\tsall %%cl, %%ebx\n");
			printf("\tmovl %%ebx, %s\n", format_operand(q->dest));
			printf("\tmovl %%edx, %%ebx\n");
			break;
		}
		case O_SHR: {
	    	printf("\tmovl %%ebx, %%edx\n");
			printf("\tmovl %s, %%ebx\n", format_operand(q->source1));
			printf("\tmovl %s, %%ecx\n", format_operand(q->source2));
			printf("\tsarl %%cl, %%ebx\n");
			printf("\tmovl %%ebx, %s\n", format_operand(q->dest));
			printf("\tmovl %%edx, %%ebx\n");
			break;
		}
		case O_AND: {
			printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			printf("\tandl %s, %%eax\n", format_operand(q->source2));
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));
	    	break;
		}
		case O_XOR: {
	    	printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			printf("\txorl %s, %%eax\n", format_operand(q->source2));
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));
	    	break;
		}
		case O_IOR: {
	    	printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			printf("\torl %s, %%eax\n", format_operand(q->source2));
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));
	    	break;
		}
		case O_NOT: { //bitwise not
			printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			printf("\tnotl %%eax\n");
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));
			break;
		}
		case O_LOGAND: {
			printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			printf("\tmovl %s, %%ecx\n", format_operand(q->source2));
			printf("\ttestl %%edx, %%edx\n");
			printf("\tsetne %%al\n");               //al = 0 if Z = 0
			printf("\txorl %%edx, %%edx\n");        //edx = 0
			printf("\ttestl %%ecx, %%ecx\n");       //is ecx nonzero
			printf("\tsetne %%dl\n");               //dl = 1 if Z = 0
			printf("\tandl %%edx, %%eax\n");
			printf("\tandl $1, %%eax\n");
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));
			break;
		}
		case O_LOGOR: {
			printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			printf("\tmovl %s, %%ecx\n", format_operand(q->source2));
			printf("\ttestl %%edx, %%edx\n");
			printf("\tsetne %%al\n");               //al = 0 if Z = 0
			printf("\txorl %%edx, %%edx\n");        //edx = 0
			printf("\ttestl %%ecx, %%ecx\n");       //is ecx nonzero
			printf("\tsetne %%dl\n");               //dl = 1 if Z = 0
			printf("\torl %%edx, %%eax\n");
			printf("\tandl $1, %%eax\n");
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));
			break;
		}
		case O_LOGNOT: {
			printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			printf("\ttestl %%eax, %%eax\n");
			printf("\tsete %%al\n");
			printf("\tmovzbl %%al, %%eax\n");
			printf("\tmovl %%eax, %s\n", format_operand(q->dest));
			break;
		}
		case O_CALL: {
			printf("CALL PLACEHOLDER\n");
			break;
		}
		case O_ARGNUM: {
			printf("ARGNUM PLACEHOLDER\n");
			break;
		}
		case O_ARGDEF: {
			printf("ARGDEF PLACEHOLDER\n");
			break;
	    }
	    case O_RETURN: {
	    	printf("RETURN PLACEHOLDER\n");
	    	break;
	    }
	    default: {
	    	printf("ASM Error: Unrecognized quad operation\n");
	    	exit(1);
	    }
	}
}

void translate_function(char* name, block* b) {
	nextOffset = 0; //reset variable offset
	printf(".text\n");
    printf(".globl\t%s\n", name);

    printf("%s:\n", name);
    printf("\tpushl %%ebp\n");
    printf("\tmovl %%esp, %%ebp\n");
    //printf("\tsubl $%d, %%esp\n", qf->local_variables_size);
	
	while(b) {
		printf("%s:\n", b->name);
		quad* q = b->top;
		while(q) {
			translate_quad(q);
			if(q->next && q != b->bottom) {
				q = q->next;
			} else {
				break;
			}
		}
		if(b->next) {
			b = b->next;
		} else {
			break;
		}
	}
}