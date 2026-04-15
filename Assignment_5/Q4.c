/*

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Level-wise insertion
struct Node* insert(struct Node* root, int data) {
    if(root == NULL) return create(data);

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {
        struct Node* temp = queue[front++];

        if(temp->left == NULL) {
            temp->left = create(data);
            return root;
        } else queue[rear++] = temp->left;

        if(temp->right == NULL) {
            temp->right = create(data);
            return root;
        } else queue[rear++] = temp->right;
    }
    return root;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);

        if(temp->left) queue[rear++] = temp->left;
        if(temp->right) queue[rear++] = temp->right;
    }
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}