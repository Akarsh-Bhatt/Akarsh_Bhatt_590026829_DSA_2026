#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *head)          //Fuction for printing ^^
{
    struct Node *ptr;
    ptr=head;
    int count=0;
    
    while(1)
    {
        if(ptr->next==head)
        {
            printf("%d \n", (ptr->data));
            count++;
            break;
        }
        else
        {
            printf("%d \n", (ptr->data));
            ptr=ptr->next;
            count++;
        }
    }
    printf("END \n");
    printf("NUMBER OF NODES : %d", count);
}

void inbegin(struct Node **head,int val)          //Function for adding at the beginning ^^
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=val;
    struct Node *ptr;
    ptr=*head;
    new_node->next=*head;
    while(1)
    {
        if(ptr->next==*head)
        {
            break;
        }
        else
        {
            ptr=ptr->next;
        }
    }
    *head=new_node;
    ptr->next=*head;
}

void inend(struct Node *head,int val)            //Function for adding at the end ^^
{
    struct Node *ptr;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=val;
    ptr->next=new_node;
    new_node->next=head;
}

void delbegin(struct Node **head,int n)          //Function for deleting from the beginning ^^
{
    struct Node *ptr;
    ptr=*head;
    *head=(*head)->next;
    free(ptr);
    ptr=*head;
    for(int i=0;i<n-1;i++)
    {
        ptr=ptr->next;
    }
    ptr->next=*head;
    
}

void delend(struct Node *head)            //Function for deleting from the end ^^
{
    struct Node *ptr;
    ptr=head;
    while(ptr->next->next!=head)
    {
        ptr=ptr->next;
    }
    struct Node *temp;
    temp=ptr->next;
    ptr->next=head;
    free(temp);
}

int main()          //main function
{
    struct Node *head,*ptr;
    int n;
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("ENTER THE NUMBER OF NODES \n");
    scanf("%d", &n);
    printf("ENTER THE VALUES : \n");
    scanf("%d", &(head->data));
    head->next=NULL;
    ptr=head;
    for(int i=1;i<=n-1;i++)          //initialization
    {

        ptr->next=(struct Node *)malloc(sizeof(struct Node));
        ptr=ptr->next;
        scanf("%d", &(ptr->data));
        ptr->next=NULL;
    }
    ptr->next=head;

    int choice,val;
    printf("1.INSERTION\n");
    printf("2.DELETION\n");
    printf("SELECT YOUR CHOICE : ");
    scanf("%d", &choice);
    switch(choice)          //switch case for asking for choice
    {
        case 1 : 
        printf("1.BEGINNING  \n");
        printf("2.END \n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        printf("ENTER THE VALUE : ");
        scanf("%d", &val);

        switch(choice)          //switch case for INSERTION
        {
            case 1 : 
            inbegin(&head,val);
            print(head);
            break;

            case 2 :
            inend(head,val);
            print(head);
            break;

            default :
            printf("INVALID CHOICE");
        }
        break;

        case 2 : 
        printf("1.BEGINNING  \n");
        printf("2.END \n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        switch(choice)          //switch case for DELETION
        {
            case 1 : 
            delbegin(&head,n);
            print(head);
            break;

            case 2 :
            delend(head);
            print(head);
            break;

            default :
            printf("INVALID CHOICE");
        }
    }
    return 0;
}