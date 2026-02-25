#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node **start,int x)          //Fuction for printing
{
    struct Node *pr;
    pr=*start;
    
    while(pr!=NULL)
    {
        printf("%d \n", (pr->data));
        pr=pr->next;
    }
    printf("END \n");
}

void begin(struct Node *head)          //Function for deleting from the beginning
{
    struct Node *ptr;
    ptr=head;
    head=(head)->next;
    free(ptr);
    
}

void end(struct Node *head)            //Function for deleting from the end
{
    struct Node *ptr;
    ptr=head;
    while(ptr->next->next!=NULL)
    {
        ptr=ptr->next;
    }
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp=ptr->next;
    ptr->next=NULL;
    free(temp);
}

void middle(struct Node **head,int pos)         //Function for deletion from the middle
{
    struct Node *ptr;
    ptr=*head;
    for(int i=1;i<pos-1;i++)
    {
        ptr=ptr->next;
    }
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp=ptr->next;
    ptr->next=ptr->next->next;
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

    int choice,index;
    printf("1.BEGINNING  \n");
    printf("2.END \n");
    printf("3.MIDDLE \n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);

    switch(choice)          //switch case for choice
    {
        case 1 : 
        begin(head);
        print(&head,n);
        break;

        case 2 :
        end(head);
        print(&head,n);
        break;

        case 3 :
        printf("ENTER THE POSITION TO DELETE : ");
        scanf("%d", &index);
        middle(&head,index);
        print(&head,n);
        break;

        default :
        printf("INVALID CHOICE");
    }
    return 0;
}