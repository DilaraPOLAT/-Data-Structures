#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define KBoyut 5

typedef struct kuyruk
{
    int son;
    int bas;
    int sayi;
    int eleman[KBoyut];
}kuyruklar;

kuyruklar *kuyruk_olustur()
{
    kuyruklar *yeni_kuyruk;
    yeni_kuyruk=(kuyruklar*)malloc(sizeof(kuyruklar));
    yeni_kuyruk->son=0;
    yeni_kuyruk->bas=0;
    yeni_kuyruk->sayi=0;
    return yeni_kuyruk;
}

int Enqueue(kuyruklar *yeni_kuyruk,int ekle)
{
    if(yeni_kuyruk->sayi>=KBoyut)
    {
        printf("kuyruk dolu\n");
        getch();
        return -1;
    }
    else
    {
        yeni_kuyruk->eleman[yeni_kuyruk->son]=ekle;
        yeni_kuyruk->son=(yeni_kuyruk->son+1)%KBoyut;
        yeni_kuyruk->sayi++;
    return 1;
    }
}

int dequeue(kuyruklar *yeni_kuyruk)
{
    int cikan_eleman;
    if(yeni_kuyruk->sayi==0)
    {
        printf("kuyruk bos\n");
        getch();
        return -1;
    }
    else
    {
        cikan_eleman=yeni_kuyruk->eleman[yeni_kuyruk->bas];
        yeni_kuyruk->bas=(yeni_kuyruk->bas+1)%KBoyut;
        yeni_kuyruk->sayi--;
        return cikan_eleman;
    }
}

void listele(kuyruklar *yeni_kuyruk)
{
    int i;
    for(i=yeni_kuyruk->bas;i<yeni_kuyruk->bas+yeni_kuyruk->sayi;i++)
        printf("%d ->",yeni_kuyruk->eleman[i%KBoyut]);
    printf("\n");

}

void main()
{
    kuyruklar *yeni_kuyruk=kuyruk_olustur();
    Enqueue(yeni_kuyruk,10);
    Enqueue(yeni_kuyruk,20);
    listele(yeni_kuyruk);
    Enqueue(yeni_kuyruk,30);
    Enqueue(yeni_kuyruk,40);
    listele(yeni_kuyruk);
    printf("Dequeu: %d\n",dequeue(yeni_kuyruk));
    printf("Dequeu: %d\n",dequeue(yeni_kuyruk));
    listele(yeni_kuyruk);
    Enqueue(yeni_kuyruk,50);
    Enqueue(yeni_kuyruk,60);
    printf("Dequeu: %d\n",dequeue(yeni_kuyruk));
    listele(yeni_kuyruk);
    printf("Dequeu: %d\n",dequeue(yeni_kuyruk));
    printf("Dequeu: %d\n",dequeue(yeni_kuyruk));


    return 0;
}
