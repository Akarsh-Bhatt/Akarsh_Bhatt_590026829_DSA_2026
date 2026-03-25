#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

void push(struct Node **top,int x)
{
    struct Node *new_node;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=x;
    new_node->next=*top;
    *top=new_node;
}

int pop(struct Node **top,struct Node *head)
{
    if(*top!=head)
    {
        int y;
        struct Node *temp;
        temp=*top;
        y=temp->data;
        *top=(*top)->next;
        free(temp);
        return y;
    }    
    else
    {
        printf("STACK UNDERFLOW");
        return -1;
    }
    
}

void display(struct Node *top,struct Node *head)
{
    struct Node *ptr;
    ptr=top;
    while(ptr!=head)
    {
        printf("%d\n", (ptr->data));
        ptr=ptr->next;
    }
}

int main()
{
    struct Node *head,*top;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    head->data=-1;
    top=head;
    int c=1;
    while(c)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Stop\n");
        printf("ENTER YOUR CHOICE : ");
        int ch;
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 :
            {
                printf("ENTER THE VALUE : ");
                int x;
                scanf("%d", &x);
                push(&top,x);
                break;
            }
            
            case 2 :
            {
                int y;
                y=pop(&top,head);
                printf("%d ", y);
                break;
            }

            case 3 :
            {            
                display(top,head);
                break;
            }

            case 4 :
            {
                return 0;
            }
        }
    }
    return 0;
}