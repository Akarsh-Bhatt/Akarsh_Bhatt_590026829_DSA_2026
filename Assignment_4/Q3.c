/*
Write a program to check whether a given string is a palindrome or not using an Array and a Queue data structure. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node 
{
    char data;
    struct Node* next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(char val) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        return; 
    }
    newNode->data = val;
    newNode->next = NULL;
    
    if (rear == NULL) 
    {
        front = rear = newNode;
    } else 
    {
        rear->next = newNode;
        rear = newNode;
    }
}

char dequeue() 
{
    if (front == NULL) return '\0';
    
    Node* temp = front;
    char val = temp->data;
    front = front->next;
    
    if (front == NULL) 
    {
        rear = NULL;
    }
    
    free(temp);
    return val;
}

int main() 
{
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) 
    {
        enqueue(str[i]);
    }

    int isPalindrome = 1;
    for (int i = len - 1; i >= 0; i--) 
    {
        char charFromQueue = dequeue();
        char charFromArray = str[i];

        if (charFromQueue != charFromArray) 
        {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) 
    {
        printf("The string \"%s\" is a palindrome.\n", str);
    } else 
    {
        printf("The string \"%s\" is NOT a palindrome.\n", str);
    }

    return 0;
}