#include <stdio.h>
#include <stdlib.h>

/*int fact(int n)
{
   int x,y;
   if(n==0)
   {
       return 1;
   }
   else
   {
       x=n-1;
       y=fact(x);
       printf(" y:%d,x:%d ",y,x);

       return n*y ;
   }
}*/

int fibbo(int n)
{
    if(n<=1)
    {
        return n;
    }

    return fibbo(n-1)+fibbo(n-2);

}
int main()
{
    //printf("%d",fact(5));
    printf("%d",fibbo(5));

    return 0;
}
