/*
3.	Write a C program to accept the number of vertices and edges of a graph and represent it using an adjacency matrix. The program should:
(i)	construct and display the adjacency matrix.
(ii)	Implement functions to calculate and print the in-degree and out-degree of a given vertex.

*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int main() {
    int matrix[MAX][MAX];
    int n, i, j;
    bool isUndirected = true;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Checking for symmetry: A[i][j] must equal A[j][i]
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isUndirected = false;
                break; 
            }
        }
        if (!isUndirected) break;
    }

    // Output the result
    printf("\n--- Result ---\n");
    if (isUndirected) {
        printf("The graph is Undirected (Symmetric Matrix).\n");
    } else {
        printf("The graph is Directed (Asymmetric Matrix).\n");
    }

    return 0;
}