/*
Write a C program to create a binary tree using linked list representation and perform various operations on it. 
(i)Insert nodes into the tree (use user input). 
(ii)Create separate functions to count. 
            - Total number of nodes. 
            - Number of leaf nodes (nodes with no children). 
            - Height of the binary tree. 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Insert level-wise
struct Node* insert(struct Node* root, int data) {
    if(root == NULL) return createNode(data);

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {
        struct Node* temp = queue[front++];

        if(temp->left == NULL) {
            temp->left = createNode(data);
            return root;
        } else queue[rear++] = temp->left;

        if(temp->right == NULL) {
            temp->right = createNode(data);
            return root;
        } else queue[rear++] = temp->right;
    }
    return root;
}

int countNodes(struct Node* root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaf(struct Node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int height(struct Node* root) {
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
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

    printf("\nTotal Nodes: %d", countNodes(root));
    printf("\nLeaf Nodes: %d", countLeaf(root));
    printf("\nHeight: %d", height(root));

    return 0;
}