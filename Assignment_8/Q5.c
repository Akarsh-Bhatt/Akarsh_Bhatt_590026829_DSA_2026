/*
5.	Write a C program to represent a graph using an adjacency matrix. The program should perform Breadth First Search (BFS) traversal starting from a given source vertex. The program should:
(i)	Accept the number of vertices n.
(ii)	Accept the adjacency matrix of the graph.
(iii)	 Accept a starting vertex for traversal.
(iv)	 Perform BFS traversal using a queue.
(v)	Display the order of traversal of vertices.


*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 20

// Queue structure for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

// BFS Function
void bfs(int adj[MAX][MAX], int n, int startVertex) {
    int visited[MAX] = {0}; // Initialize all vertices as unvisited (0)
    
    printf("\nBFS Traversal starting from vertex %d: ", startVertex);

    // Mark the start vertex as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        // Check all adjacent vertices
        for (int i = 0; i < n; i++) {
            // If there's an edge and the vertex hasn't been visited
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited before enqueuing to prevent duplicates
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, adj[MAX][MAX], startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex for BFS (0 to %d): ", n - 1);
    scanf("%d", &startVertex);

    if (startVertex >= 0 && startVertex < n) {
        bfs(adj, n, startVertex);
    } else {
        printf("Invalid starting vertex.\n");
    }

    return 0;
}