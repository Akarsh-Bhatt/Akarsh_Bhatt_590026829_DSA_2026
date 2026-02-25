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
    int arr[n];
    arr[0]=head->data;
    for(int i=1;i<=n-1;i++)
    {
        ptr->next=(struct Node *)malloc(sizeof(struct Node));
        ptr=ptr->next;
        ptr->next=NULL;
        scanf("%d", &(ptr->data));
        arr[i]=ptr->data;
    }

    ptr=head;
    for(int i=n-1;i>=0;i--)
    {
        ptr->data=arr[i];
        ptr=ptr->next;
    }

    printf("DATA IN THE LIST : \n");
    ptr=head;
    for(int i=0;i<n;i++)
    {
        printf("%d \n", (ptr->data));
        ptr=ptr->next;
    }
    return 0;
}