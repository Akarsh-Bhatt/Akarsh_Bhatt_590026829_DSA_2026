#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head,*ptr;
    int n;
    printf("ENTER THE NUMBER OF NODES TO BE CREATED");
    scanf("%d", &n);
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("ENTER THE VALUE : ");
    scanf("%d", &(head->data));
    head->next=NULL;
    ptr=head;
    for(int i=1;i<=n-1;i++)
    {
        ptr->next=(struct Node *)malloc(sizeof(struct Node));
        ptr=ptr->next;
        ptr->next=NULL;
        printf("ENTER THE VALUE : ");
        scanf("%d", &(ptr->data));
    }

    ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }

    printf("NUMBER OF NODES : %d \n", count);
}