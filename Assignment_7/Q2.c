/*
Write a C program to implement a Hash table using arrays. Perform Insert, Delete and Search operations on the hash table using the above Hash function (S.No.1). Adopt a suitable user-defined exception handling strategy if collision occurs while inserting data. 
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// User-defined Exception Codes
typedef enum {
    SUCCESS,
    ERR_COLLISION,
    ERR_NOT_FOUND,
    ERR_EMPTY_SLOT
} Status;

// Global Hash Table Array
long hashTable[SIZE] = {0}; // 0 indicates an empty slot

// Hash Function from S.No.1
int hashFunction(long sapId) {
    return (sapId % 1000) % 10;
}

// INSERT Operation with Collision Exception Handling
Status insert(long sapId) {
    int index = hashFunction(sapId);
    
    // Check for collision (Slot already occupied)
    if (hashTable[index] != 0) {
        return ERR_COLLISION; 
    }
    
    hashTable[index] = sapId;
    return SUCCESS;
}

// SEARCH Operation
Status search(long sapId, int *foundIndex) {
    int index = hashFunction(sapId);
    
    if (hashTable[index] == sapId) {
        *foundIndex = index;
        return SUCCESS;
    }
    return ERR_NOT_FOUND;
}

// DELETE Operation
Status delete(long sapId) {
    int index = hashFunction(sapId);
    
    if (hashTable[index] == sapId) {
        hashTable[index] = 0; // Reset slot
        return SUCCESS;
    }
    return ERR_NOT_FOUND;
}

void display() {
    printf("\n--- Current Hash Table (Families 0-9) ---\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != 0)
            printf("Family %d: %ld\n", i, hashTable[i]);
        else
            printf("Family %d: [Empty]\n", i);
    }
    printf("----------------------------------------\n");
}

int main() {
    int choice;
    long id;
    int idx;
    Status status;

    while (1) {
        printf("\n1. Insert SAP-ID\n2. Search SAP-ID\n3. Delete SAP-ID\n4. Display Table\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter SAP-ID to insert: ");
                scanf("%ld", &id);
                status = insert(id);
                if (status == ERR_COLLISION) {
                    printf("EXCEPTION: Collision occurred! Family %d is already occupied.\n", hashFunction(id));
                } else {
                    printf("Successfully inserted into Family %d.\n", hashFunction(id));
                }
                break;

            case 2:
                printf("Enter SAP-ID to search: ");
                scanf("%ld", &id);
                status = search(id, &idx);
                if (status == SUCCESS) {
                    printf("Found at Family index: %d\n", idx);
                } else {
                    printf("Error: SAP-ID not found.\n");
                }
                break;

            case 3:
                printf("Enter SAP-ID to delete: ");
                scanf("%ld", &id);
                status = delete(id);
                if (status == SUCCESS) {
                    printf("Successfully deleted from Family %d.\n", hashFunction(id));
                } else {
                    printf("Error: SAP-ID not found.\n");
                }
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}