#include "globls.h"
#include "quad.h"
#include "ast.h"
#include "asm.h"

#define ASM_LENGTH 128

int lSize = sizeof(long);
int nextOffset = 0;
char asmBuffer[ASM_LENGTH];
arg_list* fn_call_args;

asm_list* asm_ptr = NULL;
asm_list* function_start;

//generate the address of the quad argument, allocating memory as necessary
//for IDENT, offset value is stored in the AST union
//for TEMP, offset value is stored independently
char* format_operand(qnode* qn) {
	switch(qn->type) {
		case Q_IDENT: {
			if(qn->u.ast->type == IDENT_NODE) {
				if(qn->u.ast->u.ident.stor == SG_STATIC) {
					return qn->u.ast->u.ident.id;
				} else if(qn->u.ast->u.ident.stor == SG_AUTO) {
					char* s = malloc(ASM_LENGTH);
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
			char* s = malloc(ASM_LENGTH);
			if(*(qn->pos) == -1) { //allocate space in stack frame
				printf("\t\t# Allocating offset %i to %%T%i\n", nextOffset, qn->u.tempID);
				*(qn->pos) = nextOffset;
				nextOffset += lSize;
			}
			sprintf(s, "-%i(%%ebp)", *(qn->pos));
			return s;
		}
		case Q_CONSTANT: {
			char* s = malloc(ASM_LENGTH);
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
		case FUNCTION_NODE: {
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
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
			break;
		}
		case O_LOAD: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			// printf("\tmovl (%%eax), %%edx\n");
			// printf("\tmovl %%edx, %s\n", format_operand(q->dest));
            push_asm("movl", format_operand(q->source1), "%eax", NULL);
            push_asm("movl", "(%eax)", "%edx", NULL);
            push_asm("movl", "%edx", format_operand(q->dest), NULL);
            break;
		}
		case O_LEA: { //load effective address
			// printf("\tleal %s, %%edx\n", format_operand(q->source1));
			// printf("\tmovl %%edx, %s\n", format_operand(q->dest));
			push_asm("leal", format_operand(q->source1), "%edx", NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_STOR: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source2));
			// printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			// printf("\tmovl %%edx, (%%eax)\n");

			push_asm("movl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", format_operand(q->source1), "%edx", NULL);
			push_asm("movl", "%edx", "(%eax)", NULL);

			break;
		}
		case O_CMP: { //compare by subtraction and check flags to branch
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			// printf("\tcmpl %s, %%eax\n", format_operand(q->source2));

			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("cmpl", format_operand(q->source2), "%eax", NULL);
			break;
		}
		case O_BR: { //unconditional branch
			// printf("\tjmp %s\n", format_operand(q->source1));

			push_asm("jmp", format_operand(q->source1), NULL, NULL);
			break;
		}
		case O_BRGT: { //branch if greater than
			// printf("\tjg %s\n", format_operand(q->source1));
			// printf("\tjmp %s\n", format_operand(q->source2));

			push_asm("jg", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BRGE: { //branch if less than
			// printf("\tjge %s\n", format_operand(q->source1));
			// printf("\tjmp %s\n", format_operand(q->source2));

			push_asm("jge", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BRLT: { 
			// printf("\tjl %s\n", format_operand(q->source1));
			// printf("\tjmp %s\n", format_operand(q->source2));

			push_asm("jl", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BRLE: {
			// printf("\tjle %s\n", format_operand(q->source1));
			// printf("\tjmp %s\n", format_operand(q->source2));

			push_asm("jle", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BREQ: { //check ZF flag set by cmpl
			// printf("\tje %s\n", format_operand(q->source1));
			// printf("\tjmp %s\n", format_operand(q->source2));

			push_asm("je", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BRNE: {
			// printf("\tjg %s\n", format_operand(q->source1));
			// printf("\tjmp %s\n", format_operand(q->source2));

			push_asm("jg", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_INC: {
			// printf("\tincl %s\n", format_operand(q->source1));

			push_asm("incl", format_operand(q->source1), NULL, NULL);
			break;
		}
		case O_DEC: {
			printf("\tdecl %s\n", format_operand(q->source1));

			push_asm("decl", format_operand(q->source1), NULL, NULL);
			break;
		}
		case O_MUL: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source2));
			// printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			// printf("\timull %%edx\n");
			// printf("\tmovl %%eax, %s\n", format_operand(q->dest));

			push_asm("movl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", format_operand(q->source1), "%edx", NULL);
			push_asm("imull", "%edx", NULL, NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
			break;
		}
		case O_DIV: {
			// printf("\tmovl $0, %%edx\n");
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			// printf("\tmovl %s, %%ecx\n", format_operand(q->source2));
			// printf("\tidivl %%ecx\n");
			// printf("\tmovl %%eax, %s\n", format_operand(q->dest));

			push_asm("movl", "$0", "%edx", NULL);
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("movl", format_operand(q->source2), "%ecx", NULL);
			push_asm("idivl", "%ecx", NULL, NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
			break;
		}
		case O_MOD: {
			// printf("\tmovl $0, %%edx\n");           //most significant 4 bytes
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));       //least sig 4 bytes
			// printf("\tmovl %s, %%ecx\n", format_operand(q->source2));       //least sig 4 bytes
			// printf("\tidivl %%ecx\n");
			// printf("\tmovl %%edx, %s\n", format_operand(q->dest));    //result

			push_asm("movl", "$0", "%edx", NULL);
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("movl", format_operand(q->source2), "%ecx", NULL);
			push_asm("idivl", "%ecx", NULL, NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_ADD: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source2));
			// printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			// printf("\taddl %%eax, %%edx\n");
			// printf("\tmovl %%edx, %s\n", format_operand(q->dest));

			push_asm("movl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", format_operand(q->source1), "%edx", NULL);
			push_asm("addl", "%eax", "%edx", NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_SUB: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source2));
			// printf("\tmovl %s, %%edx\n", format_operand(q->source1));
			// printf("\tsubl %%eax, %%edx\n");
			// printf("\tmovl %%edx, %s\n", format_operand(q->dest));

			push_asm("movl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", format_operand(q->source1), "%edx", NULL);
			push_asm("subl", "%eax", "%edx", NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_SHL: {
			// printf("\tmovl %%ebx, %%edx\n");
			// printf("\tmovl %s, %%ebx\n", format_operand(q->source1));
			// printf("\tmovl %s, %%ecx\n", format_operand(q->source2));
			// printf("\tsall %%cl, %%ebx\n");
			// printf("\tmovl %%ebx, %s\n", format_operand(q->dest));
			// printf("\tmovl %%edx, %%ebx\n");

			push_asm("movl", "%ebx", "%edx", NULL);
			push_asm("movl", format_operand(q->source1), "%ebx", NULL);
			push_asm("movl", format_operand(q->source2), "%ecx", NULL);
			push_asm("sall", "%cl", "%ebx", NULL);
			push_asm("movl", "%ebx", format_operand(q->dest), NULL);
			push_asm("movl", "%edx", "%ebx", NULL);
			break;
		}
		case O_SHR: {
			// printf("\tmovl %%ebx, %%edx\n");
			// printf("\tmovl %s, %%ebx\n", format_operand(q->source1));
			// printf("\tmovl %s, %%ecx\n", format_operand(q->source2));
			// printf("\tsarl %%cl, %%ebx\n");
			// printf("\tmovl %%ebx, %s\n", format_operand(q->dest));
			// printf("\tmovl %%edx, %%ebx\n");

			push_asm("movl", "%ebx", "%edx", NULL);
			push_asm("movl", format_operand(q->source1), "%ebx", NULL);
			push_asm("movl", format_operand(q->source2), "%ecx", NULL);
			push_asm("sarl", "%cl", "%ebx", NULL);
			push_asm("movl", "%ebx", format_operand(q->dest), NULL);
			push_asm("movl", "%edx", "%ebx", NULL);
			break;
		}
		case O_AND: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			// printf("\tandl %s, %%eax\n", format_operand(q->source2));
			// printf("\tmovl %%eax, %s\n", format_operand(q->dest));

			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("andl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
	    	break;
		}
		case O_XOR: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			// printf("\txorl %s, %%eax\n", format_operand(q->source2));
			// printf("\tmovl %%eax, %s\n", format_operand(q->dest));

			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("xorl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
	    	break;
		}
		case O_IOR: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			// printf("\torl %s, %%eax\n", format_operand(q->source2));
			// printf("\tmovl %%eax, %s\n", format_operand(q->dest));

			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("orl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
	    	break;
		}
		case O_NOT: { //bitwise not
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			// printf("\tnotl %%eax\n");
			// printf("\tmovl %%eax, %s\n", format_operand(q->dest));

			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("notl", "%eax", NULL, NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
			break;
		}
		case O_LOGAND: {
			printf("LOGAND should not be used...\n");
			break;
		}
		case O_LOGOR: {
			printf("LOGOR should not be used...\n");
			break;
		}
		case O_LOGNOT: {
			// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
			// printf("\ttestl %%eax, %%eax\n");
			// printf("\tsete %%al\n");
			// printf("\tmovzbl %%al, %%eax\n");
			// printf("\tmovl %%eax, %s\n", format_operand(q->dest));

			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("testl", "%eax", "%eax", NULL);
			push_asm("sete", "%al", NULL, NULL);
			push_asm("movzbl", "%al", "%eax", NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
			break;
		}
		case O_CALL: {
			//push args in reverse above esp
			int argCounter = 0;
			while(1) {
				// printf("\tmovl %s, %%eax\n", format_operand(fn_call_args->arg->source1));
				// printf("\tmovl %%eax, %d(%%esp)\n", argCounter * lSize);

				char* temp = malloc(64);
				sprintf(temp, "%i(%%esp)", argCounter * lSize);
				push_asm("movl", format_operand(fn_call_args->arg->source1), "%eax", NULL);
				push_asm("movl", "%eax", temp, NULL);
				if(fn_call_args->prev) {
					fn_call_args = fn_call_args->prev;
				} else {
					break;
				}
			}
			break;
		}
		case O_ARGNUM: {
			fn_call_args = NULL;
			// printf("\tsubl $%li, %%esp\n", (q->source1->u.value+1)*lSize);
			
			char* temp = malloc(64);
			sprintf(temp, "%li(%%esp)", (q->source1->u.value+1)*lSize);
			push_asm("subl", temp, "%esp", NULL);
			break;
		}
		case O_ARGDEF: {
			push_arg(q);
			break;
	    }
	    case O_RETURN: {
			if (q->source1) {
				// printf("\tmovl %s, %%eax\n", format_operand(q->source1));
				
				push_asm("movl", format_operand(q->source1), "%eax", NULL);
			}
			// printf("\tmovl %%ebp, %%esp\n");
			// printf("\tpopl %%ebp\n");
			// printf("\tret\n");

			push_asm("movl", "%ebp", "%esp", NULL);
			push_asm("popl", "%ebp", NULL, NULL);
			push_asm("ret", NULL, NULL, NULL);
	    	break;
	    }
	    default: {
	    	printf("ASM Error: Unrecognized quad operation\n");
	    	exit(1);
	    }
	}
}

void asmTestPrint(asm_list* i) {
	while(1) {
		printf("%s\n", i->text);
		if(i->next) {
			i = i->next;
		} else {
			break;
		}
	}
}

void translate_function(char* name, block* b) {
	nextOffset = 0; //reset variable offset
	// printf("\t.text\n");
	// printf("\t.globl\t%s\n", name);

	// printf("%s:\n", name);
	// printf("\tpushl %%ebp\n");
	// printf("\tmovl %%esp, %%ebp\n");
	// printf("\tsubl $%d, %%esp\n", qf->local_variables_size);

    function_start = push_asm(".text", 0,0,0);
    push_asm(".globl", name, 0,0);
    sprintf(asmBuffer, "%s:", name);
    push_text(asmBuffer);
    push_asm("pushl", "%ebp", NULL, NULL);
    push_asm("movl", "%esp", "%ebp", NULL);

    asm_list* espPtr = push_text("#ESP PLACEHOLDER");
	
	while(b) {
		//printf("%s:\n", b->name);
		sprintf(asmBuffer, "%s:", b->name);
		push_text(asmBuffer);
		
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
	sprintf(asmBuffer, "\tsubl $%i, %%esp", nextOffset);
	espPtr->text = strndup(asmBuffer, ASM_LENGTH-1);
	sprintf(asmBuffer, "\t.size %s,.-%s", name, name);
	push_text(asmBuffer);

	asmTestPrint(function_start);
}

asm_list* push_asm(char* instruction, char* addr1, char* addr2, char* addr3) {
	if(instruction) {
		if(addr1) {
			if(addr2) {
				if(addr3) {
					sprintf(asmBuffer, "\t%s %s, %s, %s", instruction, addr1, addr2, addr3);
				} else {
					sprintf(asmBuffer, "\t%s %s, %s", instruction, addr1, addr2);
				}
			} else {
				sprintf(asmBuffer, "\t%s %s", instruction, addr1);
			}
		} else {
			sprintf(asmBuffer, "\t%s", instruction);
		}

		asm_list* i = malloc(sizeof(asm_list));
		if(!i){
			fprintf(stderr, "ASM Error: Unable to allocate memory for instruction list\n");
			exit(1);
		}
		i->text = strndup(asmBuffer, ASM_LENGTH-1);
		i->next = NULL;
		i->prev = NULL;
		if(asm_ptr == NULL) {
			asm_ptr = i;
		} else {
			asm_ptr->next = i;
			i->prev = asm_ptr;
			asm_ptr = i;
		}
		return i;
	} else {
		printf("ASM Error: NULL instruction!\n");
	}
}

asm_list* push_text(char* text) {
	asm_list* i = malloc(sizeof(asm_list));
	if(!i){
		fprintf(stderr, "ASM Error: Unable to allocate memory for instruction list\n");
		exit(1);
	}
	i->text = strndup(text, ASM_LENGTH-1);
	i->next = NULL;
	i->prev = NULL;
	if(asm_ptr == NULL) {
		asm_ptr = i;
	} else {
		asm_ptr->next = i;
		i->prev = asm_ptr;
		asm_ptr = i;
	}
	return i;
}

void push_arg(quad* arg) {
	arg_list* l = malloc(sizeof(arg_list));
	if(!l){
		fprintf(stderr, "ASM Error: Unable to allocate memory for argument list\n");
		exit(1);
	}
	l->arg = arg;
	l->next = NULL;
	l->prev = NULL;
	if(!fn_call_args) { //empty list
		fn_call_args = l;
	} else { //push argument
		l->prev = fn_call_args;
		fn_call_args->next = l;
		fn_call_args = l; 
	}
}