#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "project3C_hashtable.h"


int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("No filename entered, exiting program...\n");
        return 0;

    }

    char* filename = argv[1];
    HashTable ht;
    initialize(&ht);

    FILE* file = fopen(filename, "r");

    if (file == NULL) {

        printf("Failed to open file '%s'. Please try again.\n", filename);
        return 1;

    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {

        char* key = strtok(line, " ");
        int value = atoi(strtok(NULL, "\n"));
        insert(&ht, key, value);

    }

    fclose(file);

    int count;
    int* results = NULL;
    char searchKey[100];

    printf("Enter the key to search: ");

    fgets(searchKey, sizeof(searchKey), stdin);
    strtok(searchKey, "\n");

    get(&ht, searchKey, &results, &count);

    printf("Results for key '%s':\n", searchKey);

    for (int i = 0; i < count; i++) {

        printf("%d ", results[i]);

    }

    printf("\n");

    freeHashTable(&ht);

    return 0;
}