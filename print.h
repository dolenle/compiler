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
	"BINARY OP",
	"UNARY OP",
	"ASSIGN",
	"IF",
	"IF-ELSE",
	"FOR",
	"WHILE",
	"FUNCTION CALL",
	"JUMP",
	"LIST ITEM",
	"STRING"
};

char* scalarText[] = {
	"void",
	"float", "double", "long double",
	"signed", "unsigned",
	"char", "short", "int", "long", "long long",0,
	"unsigned char",0, "unsigned short",0, "unsigned int",0, "unsigned long",0, "unsigned long long"
};

char* binopText[] = {
	"MULT_OP",
	"DIV_OP",
	"MOD_OP",
	"PLUS_OP",
	"MINUS_OP",
	"SHL_OP",
	"SHR_OP",
	"LT_OP",
	"GT_OP",
	"LTEQ_OP",
	"GTEQ_OP",
	"EQEQ_OP",
	"NOTEQ_OP",
	"AND_OP",
	"XOR_OP",
	"IOR_OP",
	"LOGOR_OP",
	"LOGAND_OP"
};

char* unopText[] = {
	"PREINC_OP",
	"POSTINC_OP",
	"PREDEC_OP",
	"POSTDEC_OP",
	"ADDR_OP",
	"DEREF_OP",
	"POS_OP",
	"NEG_OP",
	"NOT_OP",
	"LOGNOT_OP",
	"SIZEOF_OP"
};

char* assignText[] = {
	"EQ_OP",
	"TIMESEQ_OP",
	"DIVEQ_OP",
	"MODEQ_OP",
	"PLUSEQ_OP",
	"MINUSEQ_OP",
	"SHLEQ_OP",
	"SHREQ_OP",
	"ANDEQ_OP",
	"OREQ_OP",
	"XOREQ_OP"
};

char* storageText[] = {
	"TYPEDEF",
	"EXTERN",
	"AUTO",
	"STATIC",
	"REGISTER"
};

#endif