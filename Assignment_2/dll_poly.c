#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void print(struct Node *head,int x)
{
    struct Node *ptr;
    ptr=head;
    x=x+1;
    while(1)
    {
        if(ptr->next==NULL)
        {
            printf("+ %d ", ptr->data);
            break;
        }
        else if(ptr==head)
        {
            printf("%dx^%d ", ptr->data, (--x));
            ptr=ptr->next;

        }
        else
        {
            printf("+ %dx^%d ", ptr->data, (--x));
            ptr=ptr->next;
        }
    }
}

void main()
{
    struct Node *head,*ptr;
    int deg,x;
    printf("ENTER THE DEGREE OF THE POLYNOMIAL : ");
    scanf("%d", &deg);
    head=(struct Node *)malloc(sizeof(struct Node));
    head->prev=NULL;
    head->next=NULL;
    printf("ENTER COEFFICIENT OF x^%d : ", deg);
    scanf("%d", &(head->data));
    ptr=head;
    x=deg;
    for(int i=1;i<=x;i++)
    {
        ptr->next=(struct Node *)malloc(sizeof(struct Node));
        ptr->next->prev=ptr;
        ptr=ptr->next;
        printf("ENTER COEFFICIENT OF x^%d : ", (--deg));
        scanf("%d", &(ptr->data));
        ptr->next=NULL;
    }
    print(head,x);
}