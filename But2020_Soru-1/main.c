#include <stdio.h>
#include <stdlib.h>

int recursive(int sayi,int sayac)
{
    if(sayac==0)
    {

       return sayi%10;
    }


    sayi=sayi/10;
    sayac--;
   return recursive(sayi,sayac);


}

int main()
{
    int sayi1,sayi,sayac=0;
    printf("Bir sayi giriniz:");
    scanf("%d",&sayi);
    sayi1=sayi;
    while(sayi>0)
    {
        sayi=sayi/10;
        sayac++;
    }
    sayac=sayac/2;
    printf("%d",recursive(sayi1,sayac));

    return 0;
}























