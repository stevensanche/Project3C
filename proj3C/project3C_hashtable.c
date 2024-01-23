#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project3C_hashtable.h"


unsigned int hash(const char *key){

	unsigned int hash = 0;

  	for (int i = 0; key[i] != '\0'; i++)
  	{
    	hash = hash * 31 + key[i];
  	}

  	return hash % BUCKET_SIZE;
}


void initialize(HashTable *ht){

	int i;
	for (i = 0; i < BUCKET_SIZE; i++) {
		ht->bucket[i] = NULL;
	}

	ht->count = 0;
}


Node *createNode(const char *key, int value){

	Node *newNode = malloc(sizeof(Node));

	newNode->key = strdup(key);
	newNode->next = NULL;
	newNode->value = value;
	return newNode;

}


void insert(HashTable *ht, const char *key, int value){

	unsigned int insrt = hash(key);
	Node *nNode = createNode(key, value);

	if (nNode == NULL) {
        return; 
    }

    if (ht->bucket[insrt] == NULL) {
        ht->bucket[insrt] = nNode;
    } 

    else {
        Node *position = ht->bucket[insrt];

        while (position->next != NULL) {
            position = position->next;
        }

        position->next = nNode;
    }

    ht->count++;
}


void get(HashTable *ht, const char *key, int **results, int *count){
	unsigned int getHash = hash(key);
	printf("%d\n", getHash);

	if (ht->bucket[getHash] == NULL) {

		printf("%s does not exists within the tashtable\n", key);
		*count = 0;
		*results = NULL;
		return;
	}

	Node *current = ht->bucket[getHash];

	while (1) {

		if (strcmp(current->key, key) == 0) {

			printf("found\n");
			(*count)++;
			*results = realloc(*results , sizeof(int) * (*count));
			(*results)[*count- 1] = current->value;

		}

		if (current->next == NULL ) {

			break;

		}

		current = current->next;
	}
}


void freeHashTable(HashTable *ht){
	int i;

	for (i = 0; i < BUCKET_SIZE; i++) {

		Node * position = ht->bucket[i];

		while (position != NULL) {
			Node *freeHash = position;
			position = position->next;
			free(freeHash->key);
			free(freeHash);

		}
	}
}


float calculateLoadFactor(HashTable *ht) {

	return (float)ht->count / BUCKET_SIZE;
}

