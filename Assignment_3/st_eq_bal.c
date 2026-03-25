/*
4.	Write a program to check whether a given expression is balanced or not using a stack implemented with an array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    char data;
    struct Node *next;
};

void push(struct Node **top)
{
    struct Node *new_node;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data='(';
    new_node->next=*top;
    *top=new_node;
}

void pop(struct Node **top,struct Node *head)
{
    if(*top!=head)
    {
        struct Node *temp;
        temp=*top;
        *top=(*top)->next;
        free(temp);
    }    
    else
    {
        printf("EQUATION IS NOT BALANCED");
        exit(0);
    }
}

int main()
{
    char st[100];
    printf("ENTER THE EQUATION : ");
    fgets(st, sizeof(st), stdin);
    int l=strlen(st);
    struct Node *head,*top,*new_node,*ptr,*temp;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    top=head;
    for(int i=0;i<l;i++)
    {
        char ch=st[i];
        if(ch=='(')
        {
            push(&top);
        }
        else if(ch==')')
        {
            pop(&top,head);
        }
    }

    if(top!=head)
    {
        printf("EQUATION NOT BALANCED");
    }
    else
    {
        printf("EQUATION IS BALANCED");
    }
    return 0;
}