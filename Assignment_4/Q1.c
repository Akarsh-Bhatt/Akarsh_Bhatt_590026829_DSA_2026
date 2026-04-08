/*
1.	Write a C program to implement a Queue data structure using an array. The program should be modular and use separate functions for each operation.
(i)	    Insert (Enqueue): Add an element to the Queue.
(ii)	Delete (Dequeue): Remove an element from the Queue.
(iii)	Display: Display all elements of the Queue.
(iv)	Peek: Display the front element of the Queue.

*/

#include<stdio.h>
#include<stdlib.h>

void enqueue(int *arr,int *bottom,int size)
{
    if(*bottom!=size-1)
    {
        printf("ENTER THE VALUE : ");
        int x;
        scanf("%d", &x);
        *bottom+=1;
        arr[*bottom]=x;
    }
    else
    {
        printf("OVERFLOW\n");
    }
}

int dequeue(int *arr,int *bottom)
{
    if(*bottom!=-1)
    {
        int y=arr[0];
        for(int i=0;i<*bottom;i++)
        {
            arr[i]=arr[i+1];
        }
        arr[*bottom]=0;
        *bottom=*bottom-1;
        return(y);
    }
    else
    {
        printf("UNDERFLOW\n");
    }
}

void display(int *arr,int bottom)
{
    for(int i=0;i<=bottom;i++)
    {
        printf("%d \n", arr[i]);
    }
}

void peek(int *arr,int bottom)
{
    printf("%d ", arr[bottom]);
}

int main()
{
    printf("enter the size of the queue :");
    int size,bottom=-1;
    scanf("%d", &size);
    int arr[size];
    while(1)
    {
        printf("1.insertion\n.2.deletion\n3.display\n4.peek\n5.exit\n");
        printf("enter your choice :");
        int ch;
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            enqueue(arr,&bottom,size);
            break;

            case 2:
            {
                int z;
                z=dequeue(arr,&bottom);
                printf("%d\n", z);
                break;
            }

            case 3:
            display(arr,bottom);
            break;

            case 4:
            peek(arr,bottom);
            break;

            case 5:
            return(0);

            default:
            printf("WRONG CHOICE\n");

        }
    }
}