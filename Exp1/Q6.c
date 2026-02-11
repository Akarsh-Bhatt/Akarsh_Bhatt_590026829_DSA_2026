//6.	Write a C program using array of structures with dynamic memory allocation to store employee details and find the employee with the highest salary.

#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int id;
    char name[50];
    float salary;
};
int main() {
    int n, i, top_idx = 0;
    struct Employee *emp;
    printf("Enter number of employees: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    emp = (struct Employee*)malloc(n * sizeof(struct Employee));
    if (emp == NULL) return 1;
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\nID: ", i + 1);
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
        if (emp[i].salary > emp[top_idx].salary) {
            top_idx = i;
        }
    }
    printf("\nEmployee with Highest Salary:\n");
    printf("ID: %d\nName: %s\nSalary: %.2f\n", emp[top_idx].id, emp[top_idx].name, emp[top_idx].salary);
    free(emp);
    return 0;
}