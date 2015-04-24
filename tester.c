#include "syms.h"
symbolTable* currentTable;

void ht_test_print(hashTable* table, char* key) {
	if(ht_contains(table, key))
		printf("%s\n", (char*) getPointer(table, key));
	else
		printf("%s%s%s\n", "Error, key ",key," not found");
}

int main() {
	printf("HashTable Test\n");
	
	hashTable* t = new_hashTable(10);
	tableInsert(t, "dolen", (void*) "le");
	tableInsert(t, "gavin", (void*) "kaplan");
	tableInsert(t, "tits", (void*) "mcgee");
	tableInsert(t, "john", (void*) "biswak");
	
	hashTable* t2 = new_hashTable(10);
	tableInsert(t2, "john", (void*) "biswa");
	tableInsert(t2, "eric", (void*) "nguyen");
	tableInsert(t2, "howard", (void*) "chen");
	
	ht_test_print(t, "tits");
	ht_test_print(t, "john");
	ht_test_print(t, "dolen");
	ht_test_print(t, "howard");
	
	ht_test_print(t2, "dolen");
	ht_test_print(t2, "howard");
	ht_test_print(t2, "john");
	return 1;
}