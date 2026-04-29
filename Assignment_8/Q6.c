/*
6.	Write a C program to represent a graph using an adjacency matrix. The program should perform Depth First Search (DFS) traversal starting from a given source vertex. The program should:
(i)	Accept the number of vertices n.
(ii)	Accept the adjacency matrix of the graph.
(iii)	 Accept a starting vertex for traversal.
(iv)	 Perform DFS traversal using recursion or stack.
(v)	Display the order of traversal of vertices.

*/

#include <stdio.h>

#define MAX 20

// Global variables for simplicity in recursion
int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int vertex) {
    // Mark the current vertex as visited and print it
    printf("%d ", vertex);
    visited[vertex] = 1;

    // Traverse all neighbors of the current vertex
    for (int i = 0; i < n; i++) {
        // If there is an edge and the neighbor hasn't been visited
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i); // Recursive call to dive deeper
        }
    }
}

int main() {
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize visited array to 0
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex for DFS (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    if (startVertex >= 0 && startVertex < n) {
        printf("\nDFS Traversal starting from vertex %d: ", startVertex);
        dfs(startVertex);
        printf("\n");
    } else {
        printf("Invalid starting vertex.\n");
    }

    return 0;
}