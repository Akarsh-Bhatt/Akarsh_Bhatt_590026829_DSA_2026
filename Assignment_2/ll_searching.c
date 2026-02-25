#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head,*ptr;
    int n;
    printf("ENTER THE NUMBER OF NODES TO BE CREATED : ");
    scanf("%d", &n);
    head=(struct Node *)malloc(sizeof(struct Node));
    printf("ENTER THE VALUE \n ");
    scanf("%d", &(head->data));
    head->next=NULL;
    ptr=head;
    for(int i=1;i<=n-1;i++)
    {
        ptr->next=(struct Node *)malloc(sizeof(struct Node));
        ptr=ptr->next;
        ptr->next=NULL;
        scanf("%d", &(ptr->data));
    }

    int num=0;
    printf("ENTER THE ELEMENT TO SEARCH FOR : ");
    scanf("%d", &num) ;

    ptr=head;
    int count=1;
    while(ptr!=NULL)
    {
        if(num==(ptr->data))
        {
            printf("ELEMENT FOUND AT POSITION %d ", count);
            return 0;
        }
        else
        {
            count++;
            ptr=ptr->next;
        }
    }
    printf("ELEMENT NOT FOUND");
    return 0;
}