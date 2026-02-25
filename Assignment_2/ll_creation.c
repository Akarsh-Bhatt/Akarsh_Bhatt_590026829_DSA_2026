#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *head , *p;
int n;
void print();
int main()
{
    printf("ENTER THE NUMBER OF NODES TO BE CREATED \n");
    scanf("%d", &n);
    head=(node *)malloc(sizeof(node));
    printf("ENTER THE VALUE \n");
    scanf("%d", &(head->data));
    head->next=NULL;
    p=head;
    for(int i=1;i<n;i++)
    {
        p->next=(node *)malloc(sizeof(node));
        p=p->next;
        p->next=NULL;
        printf("ENTER THE VALUE \n");
        scanf("%d", &(p->data));
    }
    print();
    return 0;
}

void print()
{
    printf("DATA IN THE LIST : \n");
    printf("%d \n", (head->data));
    p=head->next;
    for(int i=1;i<n;i++)
    {
        printf("%d \n", (p->data));
        p=p->next;
    }
}