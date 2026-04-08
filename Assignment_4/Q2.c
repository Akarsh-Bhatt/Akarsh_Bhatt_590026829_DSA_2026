/*
2.	Write a C program to implement a Queue using a Linked List. The program should support the following operations using separate functions:
(i)	    Enqueue (Insert): Insert an element into the Queue.
(ii)	Dequeue (Delete): Remove an element from the Queue.
(iii)	Display: Display all elements of the Queue.
(iv)	Peek: Display the front element of the Queue.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue() 
{
    int x;
    printf("ENTER THE DATA : ");
    scanf("%d", &x);
    
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;

    if (rear == NULL) 
    {
        front = rear = new_node;
        return;
    }

    rear->next = new_node;
    rear = new_node;
}

void dequeue() 
{
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    node *temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
        return;
    }
    node *ptr = front;
    printf("Queue elements: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void peek() {
    if (front == NULL) {
        printf("Queue is Empty!\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Insertion\n2.Deletion\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: peek(); break;
            case 5: exit(0);
            default: printf("WRONG CHOICE\n");
        }
    }
    return 0;
}