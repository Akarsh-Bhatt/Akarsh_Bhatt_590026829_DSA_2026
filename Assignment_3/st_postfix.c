/*
5.	Write a C program to convert a given infix expression (A+B*(C^D-E)^(F+G*H)-I) into its corresponding postfix expression (ABCD^E-FGH*+^*+I-) using a stack implemented with arrays.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char symbol) {
    switch(symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

int main() {
    char infix[] = "(A+B*(C^D-E)^(F+G*H)-I)";
    char postfix[MAX];
    int i, j = 0;
    char item, x;

    printf("Infix Expression: %s\n", infix);

    for (i = 0; i < strlen(infix); i++) {
        item = infix[i];

        if (isalnum(item)) {
            postfix[j++] = item;
        } 
        else if (item == '(') {
            push(item);
        } 
        else if (item == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        } 
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

