#include <stdio.h>

int main()
{
    int a,b,temp;
    printf("ENTER THE VALUE OF A \n");
    scanf("%d", &a);
    printf("ENTER THE VALUE OF B \n");
    scanf("%d", &b);

    b=a+b;
    a=b-a;
    b=b-a;

    printf("VALUE OF A : %d VALUE OF B : %d", a, b);
    return 0;
}