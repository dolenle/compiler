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
	S_CHAR=5, S_SHORT=6, S_INT=7, S_LONG=8, S_LONGLONG=9,
	S_UCHAR=10, S_USHORT=12, S_UINT=14, S_ULONG=16, S_ULONGLONG=18,
	S_SIGNED=100, S_UNSIGNED=101
} scalarType;

typedef enum namespaceType {
		DEFAULT_SPACE,  //enum constants, typedef names, vars and funcs
        LABEL_SPACE,
        TAG_SPACE,		//struct, enum, union tags
        STRUCT_SPACE	//struct and union
} namespaceType;

typedef struct node node; //some forward declaration

struct ast {
	node* topNode;
	node* botNode;
	int errorFlag;
};
#endif