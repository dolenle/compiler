#ifndef _GLOBAL_H
#define _GLOBAL_H

typedef enum numType {
	INT_T,
	LONG_T,
	LONGLONG_T,
	FLOAT_T,
	DOUBLE_T,
	LONGDOUBLE_T
} numType;

typedef enum signType {
	SIGNED_T,
	UNSIGNED_T
} signType;

typedef enum scalarType {
	S_VOID=0,
	S_FLOAT=1, S_DOUBLE=2, S_LONGDOUBLE=3,
	S_SIGNED=4, S_UNSIGNED=5,
	S_CHAR=6, S_SHORT=7, S_INT=8, S_LONG=9, S_LONGLONG=10,
	S_UCHAR=12, S_USHORT=14, S_UINT=16, S_ULONG=18, S_ULONGLONG=20
} scalarType;

typedef enum storageType {
	SG_TYPEDEF,
	SG_EXTERN,
	SG_AUTO,
	SG_STATIC,
	SG_REGISTER
} storageType;

typedef enum namespaceType {
	DEFAULT_SPACE,  //enum constants, typedef names, vars and funcs
	LABEL_SPACE,
	TAG_SPACE,		//struct, enum, union tags
	STRUCT_SPACE	//struct and union
} namespaceType;

typedef enum binopType {
	MULT_OP,
	DIV_OP,
	MOD_OP,
	PLUS_OP,
	MINUS_OP,
	SHL_OP,
	SHR_OP,
	LT_OP,
	GT_OP,
	LTEQ_OP,
	GTEQ_OP,
	EQEQ_OP,
	NOTEQ_OP,
	AND_OP,
	XOR_OP,
	IOR_OP,
	LOGOR_OP,
	LOGAND_OP
} binopType;

typedef enum unopType {
	PREINC_OP,
	POSTINC_OP,
	PREDEC_OP,
	POSTDEC_OP,
	ADDR_OP,
	DEREF_OP,
	POS_OP,
	NEG_OP,
	NOT_OP,
	LOGNOT_OP,
	SIZEOF_OP
} unopType;

typedef enum assignType {
	EQ_OP,
	TIMESEQ_OP,
	DIVEQ_OP,
	MODEQ_OP,
	PLUSEQ_OP,
	MINUSEQ_OP,
	SHLEQ_OP,
	SHREQ_OP,
	ANDEQ_OP,
	OREQ_OP,
	XOREQ_OP
} assignType;

typedef struct node node; //some forward declaration

struct ast {
	node* topNode;
	node* botNode;
	int errorFlag;
};

#endif