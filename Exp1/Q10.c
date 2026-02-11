//10.	Write a C program using structure and dynamic memory allocation to sort student record based on marks

#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    int n, i, j;
    struct Student *ptr, temp;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;

    ptr = (struct Student*)malloc(n * sizeof(struct Student));
    if (ptr == NULL) return 1;

    for (i = 0; i < n; i++) {
        printf("Student %d (Roll, Name, Marks): ", i + 1);
        scanf("%d %s %f", &ptr[i].roll, ptr[i].name, &ptr[i].marks);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ptr[j].marks < ptr[j + 1].marks) {
                temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Records (Descending by Marks):\n");
    for (i = 0; i < n; i++) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", ptr[i].roll, ptr[i].name, ptr[i].marks);
    }

    free(ptr);
    return 0;
}