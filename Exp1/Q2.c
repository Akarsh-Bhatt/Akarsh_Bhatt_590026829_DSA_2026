/*2.Write a C program to dynamically allocate memory for an array of N integers and perform insertion, display, sum, and average operations.*/

#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int n, i;
    int *arr;
    int sum = 0;
    float average;
    printf("Enter the number of elements (N): ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nArray elements: ");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
        sum += arr[i]; // Accumulating sum
    }
    average = (float)sum / n;
    printf("\n-----------------------");
    printf("\nSum of elements     : %d", sum);
    printf("\nAverage of elements : %.2f", average);
    printf("\n-----------------------\n");
    free(arr);
    printf("Memory successfully deallocated.\n");
    return 0;
}