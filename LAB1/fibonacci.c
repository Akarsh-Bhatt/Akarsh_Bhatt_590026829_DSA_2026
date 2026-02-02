#include <stdio.h>

int a=0;
int b=1;
int c=0;
int i;

void input()
{
    printf("ENTER THE NUMBER TILL WHICH THE SERIES IS TO BE PRINTED \n");
    scanf("%d", &i);
}

void fibo()
{
    if((a+b)>i)
    {
        return;
    }

    printf("%d  ", (a+b));
    c=a+b;
    a=b;
    b=c;
    fibo();
}

void main()
{
    input();
    printf("0  1  ");
    fibo();
}