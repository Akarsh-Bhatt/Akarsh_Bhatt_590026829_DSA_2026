#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    char name[20];
    int marks;
    struct Node *next;
    struct Node *prev;
};

void print(struct Node *head)
{
    struct Node *ptr;
    ptr=head->next;
    int c=1;
    while(ptr!=head)
    {
        printf("CREDENTIALS OF STUDENT %d \n", c++);
        printf("ROLL NUMBER : %d \n", ptr->roll);
        printf("NAME : %s \n", ptr->name);
        printf("MARKS : %d \n", ptr->marks);
        ptr=ptr->next;
    }
}

void inbegin(struct Node *head)         //insertion in the beginning
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    printf("ENTER THE CREDENTIALS OF STUDENT \n");
    printf("ROLL NUMBER : ");
    scanf("%d", &(new_node->roll));
    printf("NAME : ");
    scanf("%s", &(new_node->name));
    printf("MARKS : ");
    scanf("%d", &(new_node->marks));
    new_node->next=head->next;
    new_node->prev=head;
    head->next=new_node;
    new_node->next->prev=new_node;
}

void inend(struct Node *head)           //insertion at the end
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    printf("ENTER THE CREDENTIALS OF STUDENT \n");
    printf("ROLL NUMBER : ");
    scanf("%d", &(new_node->roll));
    printf("NAME : ");
    scanf("%s", &(new_node->name));
    printf("MARKS : ");
    scanf("%d", &(new_node->marks));
    new_node->next=head;
    new_node->prev=head->prev;
    new_node->prev->next=new_node;
    head->prev=new_node;
}

void inmiddle(struct Node *head)            //insertion in the middle
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr;
    ptr=head->next;
    int pos;
    printf("ENTER THE POSITION TO INSERT AFTER : ");
    scanf("%d", &pos);
    printf("ENTER THE CREDENTIALS OF STUDENT \n");
    printf("ROLL NUMBER : ");
    scanf("%d", &(new_node->roll));
    printf("NAME : ");
    scanf("%s", &(new_node->name));
    printf("MARKS : ");
    scanf("%d", &(new_node->marks));
    for(int i=1;i<pos;i++)
    {
        ptr=ptr->next;
    }
    new_node->prev=ptr;
    new_node->next=ptr->next;
    ptr->next=new_node;
    new_node->next->prev=new_node;
}

void delbegin(struct Node *head)            //deletion in the beginning
{
    struct Node *temp;
    temp=head->next;
    head->next->next->prev=head;
    head->next=head->next->next;
    free(temp);

}

void delend(struct Node *head)          //deketion from the end
{
    struct Node *temp;
    temp=head->prev;
    head->prev->prev->next=head;
    head->prev=head->prev->prev;
    free(temp);
}

void delmiddle(struct Node *head)           //deletion from the middle
{
    int pos;
    printf("ENTER THE POSITION TO DELETE : ");
    scanf("%d", &pos);
    struct Node *temp,*ptr;
    ptr=head->next;
    for(int i=1;i<pos;i++)
    {
        ptr=ptr->next;
    }
    temp=ptr->next;
    ptr->next->next->prev=ptr;
    ptr->next=temp->next;
    free(temp);
}

int search(struct Node *head)           //searching for a name
{
    char ch[20];
    printf("ENTER THE NAME TO SEARCH FOR : ");
    scanf("%s", ch);
    struct Node *ptr;
    ptr=head->next;
    while(ptr!=head)
    {
        if(ptr->name==ch)
        {
            printf("FOUND!!");
            return 0;
        }
        else
        {
            ptr=ptr->next;
        }
    }
    printf("NOT FOUND T_T");
    return 0;
}

void main()
{
    struct Node *head,*ptr;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    head->prev=NULL;
    head->next=(struct Node *)malloc(sizeof(struct Node));
    ptr=head->next;
    int n,c=0;
    printf("ENTER THE NUMBER OF NODES TO CREATE : ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        printf("ENTER THE CREDENTIALS OF STUDENT %d \n", i);
        printf("ROLL NUMBER : ");
        scanf("%d", &(ptr->roll));
        printf("NAME : ");
        scanf("%s", &(ptr->name));
        printf("MARKS : ");
        scanf("%d", &(ptr->marks));
        ptr->next=(struct Node *)malloc(sizeof(struct Node));
        ptr->next->prev=ptr;
        ptr=ptr->next;
        ptr->next=NULL;
        c++;
    }
    ptr->next=head;
    head->prev=ptr;
    head->roll=c;
    
    int choice,index;
    printf("\n");
    printf("1.INSERTION");
    printf("2.DELETION");
    printf("3.SEARCHING");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    switch(choice)          //outermost switch case
    {
        case 1 :
        printf("1.BEGINNING  \n");
        printf("2.END \n");
        printf("3.MIDDLE \n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        switch(choice)          //cases for insertion
        {
            case 1 :
            inbegin(head);
            print(head);
            break;

            case 2 :
            inend(head);
            print(head);
            break;

            case 3 :

            inmiddle(head);
            print(head);
            break;
        }

        break;

        case 2 :
        printf("1.BEGINNING  \n");
        printf("2.END \n");
        printf("3.MIDDLE \n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        switch(choice)          //cases for deletion
        {
            case 1 :
            delbegin(head);
            print(head);
            break;

            case 2 :
            delend(head);
            print(head);
            break;

            case 3 :

            delmiddle(head);
            print(head);
            break;
        }

        break;

        case 3 :
        search(head);
        break;

    }

}