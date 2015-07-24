#ifndef _ASM_H
#define _ASM_H

#include "globls.h"
#include "quad.h"

typedef struct asm_list asm_list;
typedef struct arg_list arg_list;

struct asm_list {
	char* text;
	asm_list* next;
	asm_list* prev;
};

struct arg_list {
	quad* arg;
	arg_list* next;
	arg_list* prev;
};

//push assembly instruction to linked list
asm_list* push_asm(char* instruction, char* addr1, char* addr2, char* addr3);

//push unformatted text
asm_list* push_text(char* text);

//Generate address for quad node
char* format_operand(qnode* qn);

//translate single quad to asm
void translate_quad(quad* q);

//translate function
void translate_function(char* name, block* start);

//push ARGDEF quad to argument list
void push_arg(quad* arg);

#endif