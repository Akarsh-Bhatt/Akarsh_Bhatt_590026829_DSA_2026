/*
3.	Write a C program to reverse a given string using a stack. The program should follow the Last In First 
Out (LIFO) principle of the stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    char data;
    struct Node *next;
};

int main()
{
    char st[100];
    printf("ENTER THE STRING : ");
    fgets(st, sizeof(st), stdin);
    int l=strlen(st);
    struct Node *head,*top,*new_node,*ptr,*temp;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    top=head;
    for(int i=0;i<l;i++)
    {
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=st[i];
        new_node->next=top;
        top=new_node;
    }
    ptr=top;
    while(ptr!=head)
    {
        printf("%c", (ptr->data));
        temp=ptr;
        ptr=ptr->next;
        top=ptr;
        free(temp);
        
    }
    return 0;
}