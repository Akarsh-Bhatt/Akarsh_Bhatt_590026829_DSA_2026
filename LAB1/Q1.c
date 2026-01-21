#include <stdio.h>
#include <math.h>

int main()
{
   int x,n=0;
   printf("ENTER THE NUMBER \n");
   scanf("%f", &x);
   for(int i=2;i<x;i++)
   {
    if(x%i==0)
    {
        printf("NOT PRIME \n");
        return 0;
    }
   }
   printf("PRIME \n");
   return 0;
}
