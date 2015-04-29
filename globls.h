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
	S_FLOAT, S_DOUBLE, S_LONGDOUBLE,
	S_CHAR, S_SHORT, S_INT, S_LONG, S_LONGLONG,
	S_UCHAR, S_USHORT, S_UINT, S_ULONG, S_ULONGLONG
} scalarType;

typedef enum namespaceType {
		DEFAULT_SPACE,  //enum constants, typedef names, vars and funcs
        LABEL_SPACE,
        TAG_SPACE,		//struct, enum, union tags
        STRUCT_SPACE	//struct and union
} namespaceType;
#endif