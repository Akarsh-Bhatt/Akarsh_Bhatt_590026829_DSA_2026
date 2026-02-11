//5.	Write a C program using structure and dynamic memory allocation to store and display student details such as roll number, name, and marks

#include <stdio.h>
#include <stdlib.h>
struct Student {
    int roll;
    char name[50];
    float marks;
};
int main() {
    int n, i;
    struct Student *ptr;
    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    ptr = (struct Student*)malloc(n * sizeof(struct Student));
    if (ptr == NULL) return 1;
    for (i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &(ptr + i)->roll);
        printf("Name: ");
        scanf("%s", (ptr + i)->name);
        printf("Marks: ");
        scanf("%f", &(ptr + i)->marks);
    }
    printf("\nStudent Records:\n");
    for (i = 0; i < n; i++) {
        printf("Roll: %d, Name: %s, Marks: %.2f\n", (ptr + i)->roll, (ptr + i)->name, (ptr + i)->marks);
    }
    free(ptr);
    return 0;
}