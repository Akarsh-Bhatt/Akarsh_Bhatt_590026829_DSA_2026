#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node **start,int x)          //Fuction for printing
{
    struct Node *pr=(struct Node *)malloc(sizeof(struct Node));
    pr=*start;
    
    for(int i=1;i<=x+1;i++)
    {
        printf("%d \n", pr->data);
        pr=pr->next;
    }
    printf("END \n");
}

void begin(struct Node **head,int val)          //Function for adding at the beginning
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=*head;
    *head=new_node;
}

void end(struct Node **head,int val)            //Function for adding at the end
{
    struct Node *ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr=*head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=val;
    ptr->next=new_node;
    new_node->next=NULL;
}

void middle(struct Node **head,int val,int pos)         //Function for adding at the middle
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr=*head;
    for(int i=1;i<pos;i++)
    {
        ptr=ptr->next;
    }
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=ptr->next;
    ptr->next=new_node;
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

    int choice,val,index;
    printf("1.BEGINNING  \n");
    printf("2.END \n");
    printf("3.MIDDLE \n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);

    switch(choice)          //switch case for choice
    {
        case 1 : 
        printf("ENTER THE VALUE : ");
        scanf("%d", &val);
        begin(&head,val);
        print(&head,n);
        break;

        case 2 :
        printf("ENTER THE VALUE : ");
        scanf("%d", &val);
        end(&head,val);
        print(&head,n);
        break;

        case 3 :
        printf("ENTER THE value : ");
        scanf("%d", &val);
        printf("ENTER THE POSITION AFTER WHICH TO INSERT : ");
        scanf("%d", &index);
        middle(&head,val,index);
        print(&head,n);
        break;

        default :
        printf("INVALID CHOICE");
    }
    return 0;
}