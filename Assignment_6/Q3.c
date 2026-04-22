/*
Write a C program to implement a Priority Queue using a Binary Heap (Min Heap or Max Heap). The program should support the following operations: 
Insert (Enqueue with Priority): Insert an element along with its priority into the queue. Maintain heap property using heapify-up. 
Delete (Dequeue Highest Priority Element): Remove the element with the highest priority: (Min Heap → smallest element) and (Max Heap → largest element). Maintain heap property using heapify-down. 
 Peek: Display the element with the highest priority without removing it. 
 Display: Print all elements of the priority queue. 
*/

#include <stdio.h>

int heap[100];
int size = 0;

void insert(int val) {
    heap[++size] = val;
    int i = size;

    while(i > 1 && heap[i] < heap[i/2]) {
        int temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i /= 2;
    }
}

void deletePQ() {
    printf("Removed: %d\n", heap[1]);

    heap[1] = heap[size--];

    int i = 1;
    while(2*i <= size) {
        int smallest = i;

        if(heap[2*i] < heap[smallest])
            smallest = 2*i;
        if(2*i+1 <= size && heap[2*i+1] < heap[smallest])
            smallest = 2*i+1;

        if(smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            i = smallest;
        } else break;
    }
}

void peek() {
    printf("Top Priority: %d\n", heap[1]);
}

void display() {
    for(int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
}

int main() 
{

    int n, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        insert(val);
    }

    printf("\nPriority Queue: ");
    display();

    peek();

    deletePQ();

    printf("After Deletion: ");
    display();

    return 0;
}