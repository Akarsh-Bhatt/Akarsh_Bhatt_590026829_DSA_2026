#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void print(struct Node *head)           //print function
{
    struct Node *ptr;
    ptr=head;
    int c=0;

    while(1)
    {
        if(ptr->next==head)
        {
            c++;
            printf("%d \n", ptr->data);
            break;
        }
        else
        {
            c++;
            printf("%d \n", ptr->data);
            ptr=ptr->next;
        }
    }
    printf("NUMBER OF NODES : %d", c);
}

void delbegin(struct Node **head)           //Deletion from the beginning
{
    struct Node *temp;
    temp=*head;
    (*head)->prev->next=(*head)->next;
    *head=(*head)->next;
    (*head)->prev=temp->prev;
    free(temp);
}

void delend(struct Node *head)          //Deletion from the end
{
    struct Node *temp,*ptr;
    ptr=head;
    while(ptr->next->next!=head)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=head;
    head->prev=ptr;
    free(temp);
}

void inbegin(struct Node **head,int val)            //Insertion in the beginning
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=*head;
    new_node->prev=(*head)->prev;
    new_node->prev->next=new_node;
    (*head)->prev=new_node;
    *head=new_node;
}

void inend(struct Node *head,int val)           //Insertion at the end
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    new_node->data=val;
    new_node->next=ptr->next;
    new_node->prev=ptr;
    ptr->next=new_node;
    new_node->next->prev=new_node;
}


int main()          //main function
{
    struct Node *head,*ptr;
    int n;
    printf("ENTER THE NUMBER OF NODES : ");
    scanf("%d", &n);
    head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    head->prev=NULL;
    printf("ENTER THE VALUES\n");
    scanf("%d", &(head->data));
    ptr=head;

    for(int i=0;i<n-1;i++)
    {
        ptr->next=(struct Node *)malloc(sizeof(struct Node));
        ptr->next->prev=ptr;
        ptr=ptr->next;
        ptr->next=NULL;
        scanf("%d", &(ptr->data));
    }
    ptr->next=head;
    head->prev=ptr;

    int choice,val,index=0;
    printf("1.DELETION\n");
    printf("2.INSERTION\n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:         //Case for deletion
        printf("1.BEGINNING  \n");
        printf("2.END \n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            delbegin(&head);
            print(head);
            break;

            case 2:
            delend(head);
            print(head);
            break;

        }
        break;

        case 2 :            //Case for Insertion
        printf("1.BEGINNING  \n");
        printf("2.END \n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        printf("ENTER THE VALUE TO INSERT");
        scanf("%d", &val);

        switch(choice)
        {
            case 1:
            inbegin(&head,val);
            print(head);
            break;

            case 2:
            inend(head,val);
            print(head);
            break;

        }
        break;

    }
}