/*
4.	Write a C program to implement a Circular Queue using an array of fixed size using the following functions for each operation.
(i)	    Insert (Enqueue): Add an element to the Circular Queue.
(ii)	Delete (Dequeue): Remove an element from the Circular Queue.
(iii)	 Display: Display all elements of the Circular Queue.

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

int isFull() 
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
    return 0;
}

int isEmpty() 
{
    if (front == -1) return 1;
    return 0;
}

void enqueue() 
{
    int element;
    if (isFull()) 
    {
        printf("\n Queue is full!! \n");
    } else 
    {
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        
        if (front == -1) front = 0;
        
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("Inserted -> %d\n", element);
    }
}

void dequeue() 
{
    int element;
    if (isEmpty()) 
    {
        printf("\n Queue is empty !! \n");
    } else 
    {
        element = items[front];
        if (front == rear) 
        {
            front = -1;
            rear = -1;
        } else 
        {
            front = (front + 1) % SIZE;
        }
        printf("Deleted element -> %d\n", element);
    }
}

void display() 
{
    int i;
    if (isEmpty()) 
    {
        printf(" \n Empty Queue\n");
    } else 
    {
        printf("\n Front -> %d ", front);
        printf("\n Items -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) 
        {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\n Rear -> %d \n", rear);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n---------------------------------------------");
        printf("\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\n Invalid choice \n");
        }
    }
    return 0;
}