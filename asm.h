#ifndef _ASM_H
#define _ASM_H

#include "globls.h"
#include "quad.h"

char* format_operand(qnode* qn);
void translate_quad(quad* q);
void translate_function(char* name, block* start);

#endif