//9.	Write a C program to show the difference in memory allocation between structure and union using sizeof().

#include <stdio.h>

struct StudentStruct {
    int roll;
    float marks;
    char grade;
};

union StudentUnion {
    int roll;
    float marks;
    char grade;
};

int main() {
    struct StudentStruct s;
    union StudentUnion u;

    printf("Structure Size: %zu bytes\n", sizeof(s));
    printf("Union Size: %zu bytes\n", sizeof(u));

    printf("\nStructure Member Addresses:\n");
    printf("roll: %p\nmarks: %p\ngrade: %p\n", (void*)&s.roll, (void*)&s.marks, (void*)&s.grade);

    printf("\nUnion Member Addresses:\n");
    printf("roll: %p\nmarks: %p\ngrade: %p\n", (void*)&u.roll, (void*)&u.marks, (void*)&u.grade);

    return 0;
}