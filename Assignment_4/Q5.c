/*
5.	Write a C program to implement a Stack using two Queues. The queues must be implemented using arrays, and all operations should be performed using functions.
(i)	    Push: Insert an element into the stack.
(ii)	Pop: Remove the top element from the stack.
(iii)	Peek: Display the top element without removing it.
(iv)	isEmpty: Check whether the stack is empty.
(v)	    Display: Print all elements of the stack.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct 
{
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) 
{
    q->front = -1;
    q->rear = -1;
}

int isQEmpty(Queue *q) 
{
    return q->front == -1;
}

// Enqueue operation
void enqueue(Queue *q, int value) 
{
    if (q->rear == MAX - 1) 
    {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->items[++(q->rear)] = value;
}

int dequeue(Queue *q) 
{
    if (isQEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

Queue q1, q2;

int isEmpty() 
{
    return isQEmpty(&q1);
}

void push(int val) 
{
    enqueue(&q1, val);
    printf("Pushed %d onto stack\n", val);
}

int pop() 
{
    if (isEmpty()) 
    {
        printf("Stack Underflow\n");
        return -1;
    }
    while (q1.front != q1.rear) {
        enqueue(&q2, dequeue(&q1));
    }
    int topElement = dequeue(&q1);
    Queue temp = q1;
    q1 = q2;
    q2 = temp;
    return topElement;
}

void peek() {
    if (isEmpty()) 
    {
        printf("Stack is empty\n");
        return;
    }
    while (q1.front != q1.rear) 
    {
        enqueue(&q2, dequeue(&q1));
    }
    int topElement = dequeue(&q1);
    printf("Top element: %d\n", topElement);
    enqueue(&q2, topElement);
    Queue temp = q1;
    q1 = q2;
    q2 = temp;
}

void display() {
    if (isEmpty()) 
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (Top to Bottom): ");

    for (int i = q1.rear; i >= q1.front; i--) 
    {
        printf("%d ", q1.items[i]);
    }
    printf("\n");
}

int main() 
{
    initQueue(&q1);
    initQueue(&q2);

    int choice, val;
    while (1) 
    {
        printf("\n1.Push \n2.Pop \n3.Peek \n4.Display \n5.Exit\n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                val = pop();
                if (val != -1) printf("Popped: %d\n", val);
                break;

            case 3: 
                peek(); 
                break;

            case 4: 
                display(); 
                break;

            case 5: 
                exit(0);

            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}