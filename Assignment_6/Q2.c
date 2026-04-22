/*
2.	Write a C program to implement a Binary Heap (Min Heap or Max Heap). The program should support the following operations:
(i)    	 Heap Creation: Initialize an empty heap using an array.
(ii)	 Insertion (Heapify-Up): Insert a new element into the heap. Maintain the heap property using heapify-up operation.
(iii)	 Deletion (Heapify-Down): Delete the root element (minimum in Min Heap / maximum in Max Heap). Maintain heap property using heapify-down operation.
(iv)	 Display Heap: Print the elements of the heap.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// (i) Heap Creation: Structure to represent the Heap
struct MaxHeap 
{
    int arr[MAX_SIZE];
    int size;
};

// Initialize the heap
void initHeap(struct MaxHeap* heap) 
{
    heap->size = 0;
}

// (ii) Insertion (Heapify-Up)
void heapifyUp(struct MaxHeap* heap, int index) 
{
    // Formula for parent index: (index - 1) / 2
    int parent = (index - 1) / 2;

    if (index > 0 && heap->arr[index] > heap->arr[parent]) 
    {
        // Swap
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[parent];
        heap->arr[parent] = temp;

        // Recursive call
        heapifyUp(heap, parent);
    }
}

void insert(struct MaxHeap* heap, int value) 
{
    if (heap->size >= MAX_SIZE) 
    {
        printf("Heap Overflow!\n");
        return;
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
    printf("Inserted %d\n", value);
}

// (iii) Deletion (Heapify-Down)
void heapifyDown(struct MaxHeap* heap, int index) 
{
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && heap->arr[leftChild] > heap->arr[largest])
        largest = leftChild;

    if (rightChild < heap->size && heap->arr[rightChild] > heap->arr[largest])
        largest = rightChild;

    if (largest != index) {
        // Swap
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;

        heapifyDown(heap, largest);
    }
}

void deleteRoot(struct MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap Underflow!\n");
        return;
    }

    int deletedValue = heap->arr[0];
    // Move last element to root and reduce size
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Restore heap property
    heapifyDown(heap, 0);
    printf("Deleted root element: %d\n", deletedValue);
}

// (iv) Display Heap
void display(struct MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap array: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    struct MaxHeap heap;
    initHeap(&heap);
    int choice, val;

    printf("--- Binary Max Heap Operations ---\n");
    while(1) {
        printf("\n1. Insert\n2. Delete Root\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(&heap, val);
                break;
            case 2:
                deleteRoot(&heap);
                break;
            case 3:
                display(&heap);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}