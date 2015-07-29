#include "globls.h"
#include "quad.h"
#include "ast.h"
#include "asm.h"

#define ASM_LENGTH 128

int lSize = sizeof(long);
unsigned int lastOffset = 0;
unsigned int argCounter = 0;
unsigned int globalCounter = 0;
unsigned int stringCounter = 0;
unsigned int stringCounter2 = 0;
char asmBuffer[ASM_LENGTH];
arg_list* fn_call_args;

asm_list* asm_ptr = NULL;
asm_list* function_start;

static_list* static_vars = NULL;
static_list* static_vars_start = NULL;

asm_list* strings = NULL;
asm_list* strings_start = NULL;

//generate the address of the quad argument, allocating memory as necessary
//for IDENT, offset value is stored in the AST union
//for TEMP, offset value is stored independently
char* format_operand(qnode* qn) {
	switch(qn->type) {
		case Q_IDENT: {
			if(qn->u.ast->type == IDENT_NODE) {
				if(qn->u.ast->u.ident.stor == SG_STATIC) {
					if(*(qn->pos) == -1 ) { //add static variable to static_vars list
						char* staticID = malloc(strlen(qn->u.ast->u.ident.id)+10); //arbitrary
						sprintf(staticID, "%s.%i", qn->u.ast->u.ident.id, globalCounter++);
						free(qn->u.ast->u.ident.id);
						qn->u.ast->u.ident.id = staticID; //append unique id to all bss vars
						push_global(qn->u.ast);
						*(qn->pos) = -2; //set visited flag
					}
					return qn->u.ast->u.ident.id;
				} else if(qn->u.ast->u.ident.stor == SG_AUTO) {
					char* s = malloc(ASM_LENGTH);
					if(*(qn->pos) == -1) {
						lastOffset += get_ident_offset(qn->u.ast->next);
						printf("# Allocated offset %i to IDENT %s\n", lastOffset, qn->u.ast->u.ident.id);
						*(qn->pos) = lastOffset;
					}
					sprintf(s, "-%i(%%ebp)", *(qn->pos));
					return s;
				} else if(qn->u.ast->u.ident.stor == SG_EXTERN) {
					return qn->u.ast->u.ident.id;
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
				lastOffset += lSize;
				*(qn->pos) = lastOffset;
				printf("# Allocated offset %i to %%T%i\n", lastOffset, qn->u.tempID);
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
		case Q_STRING: {
			//Add string to list
			asm_list* s = malloc(sizeof(asm_list));
			if(!s){
				fprintf(stderr, "ASM Error: Unable to allocate memory for string list\n");
				exit(1);
			}
			s->text = qn->u.ast->u.string.value;
			if(!strings) { //empty list
				strings = s;
				strings_start = s; //save first item
			} else { //push string
				strings->next = s;
				strings = s; 
			}
			char* temp = malloc(32);
			sprintf(temp, "$.S%i", stringCounter);
			stringCounter++;
			return temp;
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
			if(q->source1->type != Q_CONSTANT) {
				push_asm("movl", format_operand(q->source1), "%eax", NULL);
				push_asm("movl", "%eax", format_operand(q->dest), NULL);
			} else {
				push_asm("movl", format_operand(q->source1), format_operand(q->dest), NULL);
			}
			break;
		}
		case O_LOAD: {
            push_asm("movl", format_operand(q->source1), "%eax", NULL);
            push_asm("movl", "(%eax)", "%edx", NULL);
            push_asm("movl", "%edx", format_operand(q->dest), NULL);
            break;
		}
		case O_LEA: { //load effective address
			push_asm("leal", format_operand(q->source1), "%edx", NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_STOR: {
			push_asm("movl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", format_operand(q->source1), "%edx", NULL);
			push_asm("movl", "%edx", "(%eax)", NULL);
			break;
		}
		case O_CMP: { //compare by subtraction and check flags to branch
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("cmpl", format_operand(q->source2), "%eax", NULL);
			break;
		}
		case O_BR: { //unconditional branch
			push_asm("jmp", format_operand(q->source1), NULL, NULL);
			break;
		}
		case O_BRGT: { //branch if greater than
			push_asm("jg", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BRGE: { //branch if less than
			push_asm("jge", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BRLT: { 
			push_asm("jl", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BRLE: {
			push_asm("jle", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BREQ: { //check ZF flag set by cmpl
			push_asm("je", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_BRNE: {
			push_asm("jne", format_operand(q->source1), NULL, NULL);
			push_asm("jmp", format_operand(q->source2), NULL, NULL);
			break;
		}
		case O_INC: {
			push_asm("incl", format_operand(q->source1), NULL, NULL);
			break;
		}
		case O_DEC: {
			push_asm("decl", format_operand(q->source1), NULL, NULL);
			break;
		}
		case O_MUL: {
			push_asm("movl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", format_operand(q->source1), "%edx", NULL);
			push_asm("imull", "%eax", "%edx", NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_DIV: {
			push_asm("movl", "$0", "%edx", NULL);
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("movl", format_operand(q->source2), "%ecx", NULL);
			push_asm("idivl", "%ecx", NULL, NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
			break;
		}
		case O_MOD: {
			push_asm("movl", "$0", "%edx", NULL);
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("movl", format_operand(q->source2), "%ecx", NULL);
			push_asm("idivl", "%ecx", NULL, NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_ADD: {
			push_asm("movl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", format_operand(q->source1), "%edx", NULL);
			push_asm("addl", "%eax", "%edx", NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_SUB: {
			push_asm("movl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", format_operand(q->source1), "%edx", NULL);
			push_asm("subl", "%eax", "%edx", NULL);
			push_asm("movl", "%edx", format_operand(q->dest), NULL);
			break;
		}
		case O_SHL: {
			push_asm("movl", "%ebx", "%edx", NULL);
			push_asm("movl", format_operand(q->source1), "%ebx", NULL);
			push_asm("movl", format_operand(q->source2), "%ecx", NULL);
			push_asm("sall", "%cl", "%ebx", NULL);
			push_asm("movl", "%ebx", format_operand(q->dest), NULL);
			push_asm("movl", "%edx", "%ebx", NULL);
			break;
		}
		case O_SHR: {
			push_asm("movl", "%ebx", "%edx", NULL);
			push_asm("movl", format_operand(q->source1), "%ebx", NULL);
			push_asm("movl", format_operand(q->source2), "%ecx", NULL);
			push_asm("sarl", "%cl", "%ebx", NULL);
			push_asm("movl", "%ebx", format_operand(q->dest), NULL);
			push_asm("movl", "%edx", "%ebx", NULL);
			break;
		}
		case O_AND: {
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("andl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
	    	break;
		}
		case O_XOR: {
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("xorl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
	    	break;
		}
		case O_IOR: {
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("orl", format_operand(q->source2), "%eax", NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
	    	break;
		}
		case O_NOT: { //bitwise not
			push_asm("movl", format_operand(q->source1), "%eax", NULL);
			push_asm("notl", "%eax", NULL, NULL);
			push_asm("movl", "%eax", format_operand(q->dest), NULL);
			break;
		}
		case O_CALL: {
			//push args in reverse above esp
			while(fn_call_args) {
				char* temp = malloc(64);
				sprintf(temp, "%i(%%esp)", --argCounter * lSize);
				push_asm("movl", format_operand(fn_call_args->arg->source1), "%eax", NULL);
				push_asm("movl", "%eax", temp, NULL);
				if(fn_call_args->prev) {
					fn_call_args = fn_call_args->prev;
				} else {
					break;
				}
			}
			push_asm("call", format_operand(q->source1), NULL, NULL);
			if(q->dest != NULL) { //save result
				push_asm("movl", "%eax", format_operand(q->dest), NULL);
			}
			break;
		}
		case O_ARGNUM: {
			fn_call_args = NULL;
			argCounter = 0;
			char* temp = malloc(64);
			sprintf(temp, "$%li", (q->source1->u.value+1)*lSize);
			push_asm("subl", temp, "%esp", NULL);
			break;
		}
		case O_ARGDEF: {
			push_arg(q);
			argCounter++;
			break;
	    }
	    case O_RETURN: {
			if (q->source1) {				
				push_asm("movl", format_operand(q->source1), "%eax", NULL);
			}
			push_asm("leave", NULL, NULL, NULL);
			push_asm("ret", NULL, NULL, NULL);
	    	break;
	    }
	    default: {
	    	printf("ASM Error: Unrecognized quad operation\n");
	    	exit(1);
	    }
	}
}

void asmPrint(asm_list* i) {
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
	static_vars = NULL; //reset global vars list
	lastOffset = 0;//sizeof(void*); //reset variable offset, leaving space for ebp

    //Generate function prologue
    function_start = push_asm(".text", 0,0,0);
    push_asm(".globl", name, 0,0);
    sprintf(asmBuffer, "%s:", name);
    push_text(asmBuffer);
    push_asm("pushl", "%ebp", NULL, NULL);
    push_asm("movl", "%esp", "%ebp", NULL);

    asm_list* espPtr = push_text("#ESP PLACEHOLDER");
	
	while(b) {
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

	//Now that we know the size of the function, finish the prologue
	sprintf(asmBuffer, "\tsubl $%i, %%esp", lastOffset+sizeof(void*));
	espPtr->text = strndup(asmBuffer, ASM_LENGTH-1);
	sprintf(asmBuffer, "\t.size %s,.-%s", name, name);
	push_text(asmBuffer);

	while(static_vars_start) {
		sprintf(asmBuffer, "\t.comm %s, %i, %i", static_vars_start->name, static_vars_start->size, static_vars_start->alignment);
		push_text(asmBuffer);
		if(static_vars_start->next) {
			static_vars_start=static_vars_start->next;
		} else {
			break;
		}
	}

	//add strings used in the function
	if(strings_start) {
		push_text("\t.section .rodata");
	}
	while(strings_start) {
		sprintf(asmBuffer, ".S%i:\n\t.string \"%s\"", stringCounter2++, strings_start->text);
		push_text(asmBuffer);
		if(strings_start->next) {
			asm_list* temp = strings_start;
			strings_start=strings_start->next;
			strings_start->prev=NULL;
			free(temp);
		} else {
			free(strings_start);
			strings = strings_start = NULL;
			break;
		}
	}

	asmPrint(function_start);
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

void push_global(node* n) {
	static_list* s = malloc(sizeof(static_list));
	if(!s){
		fprintf(stderr, "ASM Error: Unable to allocate memory for static var list\n");
		exit(1);
	}
	s->name = n->u.ident.id;
	s->alignment = 4; //x86
	if(n->next) {
		s->size = get_ident_offset(n->next);
	} else { //default, assume int
		s->size = sizeof(int);
	}
	if(!static_vars) { //empty list
		static_vars = s;
		static_vars_start = s; //save first item
	} else { //push var
		static_vars->next = s;
		static_vars = s; 
	}
}