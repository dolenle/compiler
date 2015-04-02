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
	table->mainTable = new_hashTable(20);
	table->labelTable = new_hashTable(20);
	table->tagTable = new_hashTable(20);
	
	return table;
}

symbolTable* leaveScope(symbolTable* table, int free) {
	if(free) {
		destroy_hashTable(table->mainTable);
		destroy_hashTable(table->tagTable);
		destroy_hashTable(table->labelTable);
	}
	return table->parent;
}

int installSymbol(symbolTable* table, char* ident, char *filename, int linenum, symType type) {
	printf("installSym symbol=%s\n", ident);
	return ht_addSymbol(table->mainTable, ident, linenum, filename, type);
}

//returns -1 if ident could not be found
int setSymbolValue(symbolTable* table, char* ident, long long val) {
	return ht_setValue(table->mainTable, ident, val);
}

long long getSymbolValue(symbolTable* table, char* ident) {
	return ht_getValue(table->mainTable, ident);
}

char* getTableFile(symbolTable* table) {
	return table->filename;
}

// int main() {
// 	printf("[Symbol Table Test]\n");
// 	symbolTable* globalTable = enterScope(GLOBAL_SCOPE, 0, "TestFileName.c", NULL);
// 	printf("Created symTab\n");
// 	installSymbol(globalTable, "test", "TestFileName.c", 12, NUM);
// 	installSymbol(globalTable, "var2", "TestFileName.c", 13, NUM);
// 	setSymbolValue(globalTable, "test", 123);
// 	installSymbol(globalTable, "var3", "TestFileName.c", 13, NUM);
// 	installSymbol(globalTable, "var4", "TestFileName.c", 13, NUM);
// 	printf("%lli\n", getSymbolValue(globalTable, "test"));
// 	return 0;
// }