/*
3.	Write a C program to accept the number of vertices and edges of a graph and represent it using an adjacency matrix. The program should:
(i)	construct and display the adjacency matrix.
(ii)	Implement functions to calculate and print the in-degree and out-degree of a given vertex.
*/

#include <stdio.h>

#define MAX 20

// Function prototypes
void displayMatrix(int matrix[MAX][MAX], int v);
void calculateDegrees(int matrix[MAX][MAX], int v, int target);

int main() {
    int matrix[MAX][MAX] = {0}; // Initialize matrix with zeros
    int v, e, i, origin, destination, searchVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &v);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    // Constructing the adjacency matrix
    for (i = 0; i < e; i++) {
        printf("Enter edge %d (origin destination): ", i + 1);
        scanf("%d %d", &origin, &destination);

        // Standard validation for vertex bounds (assuming 0 to v-1)
        if (origin >= v || destination >= v || origin < 0 || destination < 0) {
            printf("Invalid vertex! Please use vertices between 0 and %d.\n", v - 1);
            i--; // Redo this iteration
        } else {
            matrix[origin][destination] = 1;
        }
    }

    // (i) Display the adjacency matrix
    displayMatrix(matrix, v);

    // (ii) Calculate in-degree and out-degree
    printf("\nEnter the vertex to find its degrees: ");
    scanf("%d", &searchVertex);

    if (searchVertex >= 0 && searchVertex < v) {
        calculateDegrees(matrix, v, searchVertex);
    } else {
        printf("Vertex not found in graph.\n");
    }

    return 0;
}

void displayMatrix(int matrix[MAX][MAX], int v) {
    printf("\n--- Adjacency Matrix ---\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculateDegrees(int matrix[MAX][MAX], int v, int target) {
    int inDegree = 0, outDegree = 0;

    for (int i = 0; i < v; i++) {
        // Out-degree: count 1s in the row of the target vertex
        if (matrix[target][i] == 1) {
            outDegree++;
        }
        // In-degree: count 1s in the column of the target vertex
        if (matrix[i][target] == 1) {
            inDegree++;
        }
    }

    printf("Vertex %d -> In-degree: %d, Out-degree: %d\n", target, inDegree, outDegree);
}