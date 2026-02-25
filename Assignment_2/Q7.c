#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void print(struct Node *head)
{
    struct Node *ptr;
    ptr=head;
    int c=0;

    while(1)
    {
        if(ptr->next==NULL)
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
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}

void delend(struct Node *head)          //Deletion from the end
{
    struct Node *temp,*ptr;
    ptr=head;
    while(ptr->next->next!=NULL)
    {
        temp=ptr->next;
        ptr->next=NULL;
        free(temp);
    }
}

void delmiddle(struct Node *head, int index)            //Deletion from the middle
{
    struct Node *temp,*ptr;
    ptr=head;
    for(int i=1;i<index;i++)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next=temp->next;
    ptr->next->prev=ptr;
    free(ptr);

}

void inbegin(struct Node **head,int val)            //Insertion in the beginning
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=*head;
    new_node->prev=NULL;
    (*head)->prev=new_node;
    *head=new_node;
}

void inend(struct Node *head,int val)           //Insertion at the end
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr;
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    new_node->data=val;
    ptr->next=new_node;
    new_node->next=NULL;
    new_node->prev=ptr;
}

void inmiddle(struct Node *head,int val,int index)          //Insertion in the middle
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr;
    ptr=head;
    for(int i=1;i<index;i++)
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
        printf("3.MIDDLE \n");
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

            case 3:
            printf("ENTER THE POSITION TO DELETE : ");
            scanf("%d", &index);
            delmiddle(head,index);
            break;
        }
        break;

        case 2 :            //Case for Insertion
        printf("1.BEGINNING  \n");
        printf("2.END \n");
        printf("3.MIDDLE \n");
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

            case 3:
            printf("ENTER THE POSITION TO INSERT AFTER : ");
            scanf("%d", &index);
            inmiddle(head,val,index);
            print(head);
            break;
        }
        break;

    }
}
