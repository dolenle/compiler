/*
*	Data Structures and Algorithms 2
*	Programming Assignment 2 - Hash Table (C Version)
*	Dolen Le		10/10/14
*/

#ifndef _HASH_H
#define _HASH_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct hashItem {
	char* key;
	int isOccupied;
	int isDeleted;
	void *pv;
	
	long long value;
	char filename[4096];
	int line;
} hashItem;

typedef struct hashTable {
	int capacity; // The current capacity of the hash table.
	int filled; // Number of occupied items in the table.
	hashItem* data; // The actual entries are here.
} hashTable;

hashTable* new_hashTable(int size);

int ht_addSymbol(hashTable* table, char* identifier, int line, char* filename);

int ht_contains(hashTable* table, char* identifier);

// Test functions for assignment 2

int ht_setValue(hashTable* table, char* identifier, long long value);

long long ht_getValue(hashTable* table, char* identifier);

//Legacy Functions

//returns 0 on success, 1 on duplicate, 2 on fail
int tableInsert(hashTable* table, char* key, void* pv);

void *getPointer(hashTable* table, char* key);

//returns 0 on success, 1 if not found
int setPointer(hashTable* table, char* key, void *pv);

int tableRemove(hashTable* table, char* key);

int hash(hashTable* table, char* key);

int findPos(hashTable* table, char * key);

void destroy_hashTable(hashTable* table);

unsigned int getPrime(int size);

#endif
