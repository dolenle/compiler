#ifndef _PRINT_H
#define _PRINT_H

char* nodeText[] = {
	"DEFAULT",
	"IDENT",
	"SCALAR",
	"STORAGE",
	"POINTER",
	"ARRAY",
	"FUNCTION",
	"NUMBER",
	"BINOP",
	"UNOP",
	"ASSIGN",
	"IF",
	"FOR",
	"WHILE",
	"LIST"
};

char* scalarText[] = {
	"void",
	"float", "double", "long double",
	"signed", "unsigned",
	"char", "short", "int", "long", "long long",0,
	"unsigned char",0, "unsigned short",0, "unsigned int",0, "unsigned long",0, "unsigned long long"
};

char* storageText[] = {
	"TYPEDEF",
	"EXTERN",
	"AUTO",
	"STATIC",
	"REGISTER"
};

#endif