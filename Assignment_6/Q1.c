/*
1.	Write a C program to implement a Binary Search Tree (BST) using a linked list representation. Your program should support the following operations:
(i)	 Insertion: Insert a node into the BST while maintaining BST properties. Duplicate values should not be allowed.
(ii) Deletion: Delete a node from the BST based on a given key.
        Handle all three cases: (a) Node is a leaf node, (b) Node has one child and (c) Node has two children
(iii)Searching: Search for a given value in the BST (Display whether the element is found or not).
(iv) Traversal: In order Traversal (Left → Root → Right).

*/

#include <stdio.h>
#include <stdlib.h>

// Structure for the BST Node
struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// (i) Insertion: Maintains BST properties, avoids duplicates
struct Node* insert(struct Node* root, int value) 
{
    if (root == NULL) 
    {
        return createNode(value);
    }

    if (value < root->data) 
    {
        root->left = insert(root->left, value);
    } else if (value > root->data) 
    {
        root->right = insert(root->right, value);
    } else 
    {
        printf("Duplicate value %d ignored.\n", value);
    }
    return root;
}

// Helper function to find the minimum value node (used for deletion)
struct Node* minValueNode(struct Node* node) 
{
    struct Node* current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// (ii) Deletion: Handles leaf, one child, and two children cases
struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL) return root;

    if (key < root->data) 
    {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) 
    {
        root->right = deleteNode(root->right, key);
    } else 
    {
        // Case (a) & (b): Leaf or one child
        if (root->left == NULL) 
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) 
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case (c): Two children
        // Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// (iii) Searching
struct Node* search(struct Node* root, int key) 
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// (iv) In-order Traversal (Left -> Root -> Right)
void inorder(struct Node* root) 
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() 
{
    struct Node* root = NULL;
    int choice, val;

    printf("\n--- Binary Search Tree Operations ---\n");
    while(1) 
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. In-order Traversal\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Element %d found in BST.\n", val);
                else
                    printf("Element %d NOT found.\n", val);
                break;
            case 4:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}