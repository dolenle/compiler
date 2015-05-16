//Linked List of Hash Tables

#ifndef _SYM_TABLE_H
#define _SYM_TABLE_H

#include "hash.h"
#include "ast.h"
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
	int line; //line number where scope entered
	char* filename; //file containing scope
	struct symbolTable* parent;
	scopeType scope;
} symbolTable;

symbolTable* enterScope(scopeType scope, int line, char* filename, symbolTable* parent);

symbolTable* leaveScope(symbolTable* table, int free);

int installSymbol(symbolTable* table, char* ident);

int containsSymbol(symbolTable* table, char* ident); //return 1 if found, 0 if not

//search through all parent scopes, return scope type else -1
symbolTable* searchSymbol(symbolTable* table, char* ident);

node* getNode(symbolTable* table, char* ident);

//return 1 if successful, 0 otherwise
int setNode(symbolTable* table, char* ident, node* astNode);

//For Assignment 2
int setSymbolValue(symbolTable* table, char* ident, long long val);

long long getSymbolValue(symbolTable* table, char* ident);

#endif