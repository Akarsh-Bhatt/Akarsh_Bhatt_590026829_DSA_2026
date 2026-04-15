/*
Write a C program to implement non-recursive tree traversals of a binary tree using a stack. Your program should implement the following traversals using the stack: 
(i)Inorder traversal (Left → Root → Right). 
(ii)Preorder traversal (Root → Left → Right). 
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

// -------- STACK --------
struct Node* stack[100];
int top = -1;

void push(struct Node* n) {
    stack[++top] = n;
}

struct Node* pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

// -------- NON-RECURSIVE INORDER --------
void inorder(struct Node* root) {
    struct Node* curr = root;

    while(curr != NULL || !isEmpty()) {
        while(curr != NULL) {
            push(curr);
            curr = curr->left;
        }

        curr = pop();
        printf("%d ", curr->data);

        curr = curr->right;
    }
}

// -------- NON-RECURSIVE PREORDER --------
void preorder(struct Node* root) {
    if(root == NULL) return;

    push(root);

    while(!isEmpty()) {
        struct Node* temp = pop();
        printf("%d ", temp->data);

        if(temp->right) push(temp->right);
        if(temp->left) push(temp->left);
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

    printf("\nNon-Recursive Inorder: ");
    inorder(root);

    // Reset stack
    top = -1;

    printf("\nNon-Recursive Preorder: ");
    preorder(root);

    return 0;
}