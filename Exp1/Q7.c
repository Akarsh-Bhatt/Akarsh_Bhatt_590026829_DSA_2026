//7.	Write a menu-driven C program using structure and dynamic memory allocation to add, display, delete records and free memory before exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
    int id;
    char name[50];
};

int main() {
    struct Record *arr = NULL;
    int count = 0, choice, i, targetId, found;

    while (1) {
        printf("\n1. Add\n2. Display\n3. Delete\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;

        if (choice == 1) {
            arr = (struct Record*)realloc(arr, (count + 1) * sizeof(struct Record));
            if (arr == NULL) return 1;
            printf("Enter ID: ");
            scanf("%d", &arr[count].id);
            printf("Enter Name: ");
            scanf("%s", arr[count].name);
            count++;
        } 
        else if (choice == 2) {
            if (count == 0) printf("Empty.\n");
            for (i = 0; i < count; i++) {
                printf("ID: %d, Name: %s\n", arr[i].id, arr[i].name);
            }
        } 
        else if (choice == 3) {
            if (count == 0) {
                printf("Nothing to delete.\n");
                continue;
            }
            printf("Enter ID to delete: ");
            scanf("%d", &targetId);
            found = 0;
            for (i = 0; i < count; i++) {
                if (arr[i].id == targetId) {
                    for (int j = i; j < count - 1; j++) arr[j] = arr[j + 1];
                    count--;
                    found = 1;
                    arr = (struct Record*)realloc(arr, count * sizeof(struct Record));
                    printf("Deleted.\n");
                    break;
                }
            }
            if (!found) printf("Not found.\n");
        } 
        else if (choice == 4) {
            free(arr);
            printf("Memory freed. Exit.\n");
            break;
        }
    }
    return 0;
}