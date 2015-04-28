//Linked List

#ifndef _SYM_TABLE_H
#define _SYM_TABLE_H

#include "hash.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_STRING_LENGTH 4096 
#define HT_SIZE 30

typedef enum scopeType {
	GLOBAL_SCOPE,
	FUNCTION_SCOPE,
	BLOCK_SCOPE,
	PROTOTYPE_SCOPE
} scopeType;

typedef struct symbolTable {
	hashTable* mainTable;
	hashTable* labelTable;
	hashTable* tagTable;
	int line;
	char* filename;
	struct symbolTable* parent;
	scopeType scope;
} symbolTable;

symbolTable* enterScope(scopeType scope, int line, char* filename, symbolTable* parent);

symbolTable* leaveScope(symbolTable* table, int free);

int installSymbol(symbolTable* table, char* ident, char *filename, int linenumber, symType type);

int setSymbolValue(symbolTable* table, char* ident, long long val);

long long getSymbolValue(symbolTable* table, char* ident);

int containsSymbol(symbolTable* table, char* ident); //return 1 if found, 0 if not

int searchSymbol(symbolTable* table, char* ident); //search through all parent scopes

#endif