//3.	Write a C program to dynamically allocate an array and find the largest and smallest element

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i, *arr, min, max;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 1;
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) return 1;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    min = max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Largest: %d\nSmallest: %d\n", max, min);
    free(arr);
    return 0;
}