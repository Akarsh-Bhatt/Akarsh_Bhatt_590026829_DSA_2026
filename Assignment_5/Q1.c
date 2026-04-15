/*
Write a C program to create a binary tree using an array. The program should support the following operations:  
(i)      Insert elements into the tree. 
(ii)     Display the tree elements. 
(iii)    Display the parent, left child, and right child of a given node. 
*/

#include <stdio.h>

int tree[100];

int main() 
{

    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &val);
        tree[i] = val;
    }

    printf("\nTree Elements: ");
    for(int i = 1; i <= n; i++) {
        printf("%d ", tree[i]);
    }

    int i;
    printf("\nEnter index to find relations: ");
    scanf("%d", &i);

    printf("\nNode: %d", tree[i]);

    if(i/2 >= 1)
        printf("\nParent: %d", tree[i/2]);
    else
        printf("\nNo Parent");

    if(2*i <= n)
        printf("\nLeft Child: %d", tree[2*i]);
    else
        printf("\nNo Left Child");

    if(2*i+1 <= n)
        printf("\nRight Child: %d", tree[2*i+1]);
    else
        printf("\nNo Right Child");

    return 0;
}