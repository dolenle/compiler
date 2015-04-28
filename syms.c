#include "hash.h"
#include "syms.h"

symbolTable* enterScope(scopeType scope, int line, char* filename, symbolTable* parent) {
	printf("enterScope=%i\n", scope);
	struct symbolTable *table;
	if(!(table = malloc(sizeof(symbolTable)))) {
		fprintf(stderr, "Error: could not allocate memory for symbol table.\n");
		return NULL;
	}
	table->scope = scope;
	table->line = line;
	table->filename = strdup(filename);
	table->parent = parent;
	table->mainTable = new_hashTable(HT_SIZE);
	table->labelTable = new_hashTable(HT_SIZE);
	table->tagTable = new_hashTable(HT_SIZE);
	
	return table;
}

symbolTable* leaveScope(symbolTable* table, int free) {
	printf("leaveScope=%i\n", table->scope);
	if(free) {
		destroy_hashTable(table->mainTable);
		destroy_hashTable(table->tagTable);
		destroy_hashTable(table->labelTable);
	}
	return table->parent;
}

int installSymbol(symbolTable* table, char* ident, char* filename, int linenum, symType type) {
	printf("installSym symbol=%s\n", ident);
	return ht_addSymbol(table->mainTable, ident, linenum, filename, type);
}

//returns -1 if ident could not be found
int setSymbolValue(symbolTable* table, char* ident, long long val) {
	return ht_setValue(table->mainTable, ident, val);
}

long long getSymbolValue(symbolTable* table, char* ident) {
	printf("getSymbolValue of %s\n", ident);
	return ht_getValue(table->mainTable, ident);
}

int containsSymbol(symbolTable* table, char* ident) {
	return ht_contains(table->mainTable, ident);
}

char* getTableFile(symbolTable* table) {
	return table->filename;
}

int searchSymbol(symbolTable* table, char* ident) {
	symbolTable* curTable = table;
	do {
		if(containsSymbol(curTable, ident)) {
			return 1;
		} else if (table->scope != GLOBAL_SCOPE) {
			curTable = curTable->parent;
		}
	} while(table->scope != GLOBAL_SCOPE);
	return 0;
}