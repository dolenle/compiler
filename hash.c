/*
*	Data Structures and Algorithms 2
*	Programming Assignment 2 - Hash Table (C Version)
*	Dolen Le		10/10/14
*/

#include "hash.h"
 
//fixed size hashTable
hashTable* new_hashTable(int size) {
	hashTable* table = (hashTable*) malloc(sizeof(hashTable));
	if(!table) {
		fprintf(stderr, "Could not allocate memory for hash table\n");
		return NULL;
	}
	table->filled = 0;
 	table->capacity = getPrime(size*2);
 	if(!(table->data = calloc(table->capacity, sizeof(hashItem)))) {
		fprintf(stderr, "Could not allocate memory for hash table data\n");
 		return NULL;
 	}
	int i;
	for(i=0; i < table->capacity; i++) { //initialize items
		table->data[i].isOccupied = 0;
	}
	return table;
}

int ht_addSymbol(hashTable* table, char* identifier, int line, char* filename) {
	//printf("addSymbol called\n");
	if(table->filled < table->capacity) {
		int i = hash(table, identifier); //get index
		//printf("Inserting %s at index=%i\n",identifier,i);
		while(table->data[i].isOccupied && !table->data[i].isDeleted) { //collision
		    if(strcmp(table->data[i].key, identifier)==0) {
				return 1; //duplicate found
			}
			i = (i+1)%table->capacity; //linear probing
		}
		//insert item
		if(!table->data[i].isOccupied) {
			table->filled++;
		}
		table->data[i].key = identifier;
 		table->data[i].isOccupied = 1;
 		table->data[i].isDeleted = 0;
 		table->data[i].pv = NULL;
 		table->data[i].line = line;
 		strcpy(table->data[i].filename,filename);
		return 0; //success
	}
	fprintf(stderr, "WARNING: Hash table full, please increase size.");
	return 2;
}

ht_setValue(hashTable* table, char* identifier, long long value) {
	int i = findPos(table, identifier);
	if(i > -1)
		table->data[i].value = value;
	return i;
}

long long ht_getValue(hashTable* table, char* identifier) {
	int i = findPos(table, identifier);
	return table->data[i].value;
}

int ht_contains(hashTable* table, char* identifier) {
	if(findPos(table, identifier) > -1)
		return 1;
	else
		return 0;
}

//Insert key into hash table; return 0=success, 1=duplicate, 2=fail
int tableInsert(hashTable* table, char* key, void* pv) {
	if(table->filled < table->capacity) {
		int i = hash(table, key); //get index
		//printf("Inserting %s at index=%i\n",key,i);
		while(table->data[i].isOccupied && !table->data[i].isDeleted) { //collision
		    if(table->data[i].key==key) {
				return 1; //duplicate found
			}
			i = (i+1)%table->capacity; //linear probing
		}
		//insert item
		if(!table->data[i].isOccupied) {
			table->filled++;
		}
		table->data[i].key = key;
 		table->data[i].isOccupied = 1;
 		table->data[i].isDeleted = 0;
 		table->data[i].pv = pv;
		return 0; //success
	}
	fprintf(stderr, "WARNING: Hash table full, please increase size.");
	return 2;
}

//search for key in table, return -1 if not found
int findPos(hashTable* table, char* key) {
	int i = hash(table, key); //starting index
	//printf("starting at index=%i\n",i);
	while(table->data[i].isOccupied) //search through table
	{
		//printf("%s\n",table->data[i].key);
		if(strcmp(table->data[i].key, key) == 0)
			if(table->data[i].isDeleted) {
				return -1; //nothing here
			} else {
				//printf("Found %s at index=%i\n",table->data[i].key,i);
				return i; //found it
			}
		i = (i+1)%table->capacity; //keep looking
	}
	//printf("key not found\n");
	return -1;
}

//delete item from table
int tableRemove(hashTable* table, char* key) {
	int i;
	if(-1 != (i = findPos(table, key))) {
		return table->data[i].isDeleted=1;
	} else {
		return 0;
	}
}

//Return item pointer
void* getPointer(hashTable* table, char* key) {
	int i;
	if(-1 != (i = findPos(table, key))) {
		return table->data[i].pv;
	}
	return NULL;
}

//Set item pointer
int setPointer(hashTable* table, char* key, void* pv) {
	int i;
	if(-1 != (i = findPos(table, key))) {
		table->data[i].pv = pv;
		return 0; //success
	} else {
		return 1; //not found
	}
}

//Hashing function (from internet)
int hash(hashTable* table, char* key) {
	size_t hash = 0;
	int i;
	for(i=0; i < strlen(key); i++) {
		hash=(hash << 6) ^ (hash >> 26) ^ key[i];
	}
	return ((unsigned int) hash)%table->capacity;
}

//Return a prime number at least as large as size
unsigned int getPrime(int size) {
	unsigned int primeList[] = {17,23,53,101,503,1009,40063,80141,160309,320627,641261,1282529,2565061,5130143};
	int i;
	for(i=0; i < sizeof(primeList); i++)
		if(size < primeList[i])
			return primeList[i];
	if(size>primeList[sizeof(primeList) - 1]) //size too large
		exit(0);
}

void destroy_hashTable(hashTable* table) {
	free(table->data);
	free(table);
}

//Testing
// int main() {
// printf("HashTable Test\n");
// 	hashTable* t = new_hashTable(10);
// 	
// 	tableInsert(t, "dolen", (void*) "le");
// 	tableInsert(t, "gavin", (void*) "kaplan");
// 	tableInsert(t, "tits", (void*) "mcgee");
// 	hashTable* t2 = new_hashTable(10);
// 	tableInsert(t2, "john", (void*) "biswa");
// 	tableInsert(t2, "eric", (void*) "nguyen");
// 	tableInsert(t2, "howard", (void*) "chen");
// 	printf("%s\n", (char*) getPointer(t, "tits"));
// 	printf("%s\n", (char*) getPointer(t, "john"));
// 	printf("%s\n", (char*) getPointer(t, "dolen"));
// 	printf("%s\n", (char*) getPointer(t2, "dolen"));
// 	printf("%s\n", (char*) getPointer(t2, "howard"));
// 	printf("%s\n", (char*) getPointer(t, "howard"));
// 	printf("%s\n", (char*) getPointer(t2, "john"));
// 	return 1;
// }
