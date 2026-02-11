//8.	Write a C program to demonstrate the use of union by storing integer, float, and character data and explain memory sharing

#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    data.i = 10;
    printf("Stored int: %d\n", data.i);

    data.f = 220.5;
    printf("Stored float: %.1f\n", data.f);

    data.c = 'G';
    printf("Stored char: %c\n", data.c);

    printf("\nFinal values (demonstrating corruption):\n");
    printf("int: %d, float: %.1f, char: %c\n", data.i, data.f, data.c);
    printf("Size of union: %zu bytes\n", sizeof(data));

    return 0;
}