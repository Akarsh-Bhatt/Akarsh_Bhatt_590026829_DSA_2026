/*
1.	Write a C program to implement a Stack data structure using an array. The program should be modular and use separate functions for each operation.
(i)	Insert (Push): Add an element to the top of the stack.
(ii)	Delete (Pop): Remove an element from the top of the stack.
(iii)	Display: Display all elements of the stack from top to bottom.
*/

#include <stdio.h>
#include <stdlib.h>

void push(int *arr,int x,int *top,int n)
{
    if(*top!=n-1)
    {
        *top+=1;
        arr[*top]=x;
    }
    else
    {
        printf("Stack overflow");
    }
}

int pop(int *arr,int *top)
{
    if(*top!=-1)
    {
        int temp;
        temp=arr[*top];
        *top-=1;
        return temp;
    }
    else
    {
        printf("Stack is empty");
    }
}

void display(int arr[],int top)
{
    if(top!=-1)
    {
        for(int i=top;i>=0;i--)
        {
            printf("%d \n", arr[i]);
        }
    }
    else
    {
        printf("Stack is empty");
    }
}

int main()
{
    printf("ENTER THE SIZE OF THE STACK : ");
    int n;
    scanf("%d", &n);
    int *arr=(int *)malloc(n*sizeof(int));
    int top=-1;
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
                push(arr,x,&top,n);
                break;
            }
            
            case 2 :
            {
                int y;
                y=pop(arr,&top);
                printf("%d ", y);
                break;
            }

            case 3 :
            {            
                display(arr,top);
                break;
            }

            case 4 :
            {
                c=0;
                free(arr);
                break;
            }
        }
    }
    return 0;
}