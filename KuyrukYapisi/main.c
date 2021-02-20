#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define KBoyut 5

typedef struct Kuyruk
{
    int son;
    int eleman[KBoyut];
}Kuyruklar;

Kuyruklar *Kuyruk_Olustur()
{
    Kuyruklar *yeni_kuyruk;
    yeni_kuyruk=(Kuyruklar*)malloc(sizeof(Kuyruklar));
    yeni_kuyruk->son=-1;
    return yeni_kuyruk;
}

int Enque (Kuyruklar*yeni_kuyruk,int ekle)
{
    if(yeni_kuyruk->son>=KBoyut-1)
    {
        printf("kuyruk dolu\n");
        getch();
        return -1;
    }
    else
    {
        yeni_kuyruk->son++;
        yeni_kuyruk->eleman[yeni_kuyruk->son]=ekle;
        return 1;
    }
}

int Dequeu(Kuyruklar*yeni_kuyruk)
{
    char cikan_eleman;
    int i;
    if(yeni_kuyruk->son==-1)
    {
        printf("kuyruk bos\n");
        getch();
        return -1;
    }
    else
    {
        cikan_eleman=yeni_kuyruk->eleman[0];
        for(int i=0;i<=yeni_kuyruk->son;i++)
            yeni_kuyruk->eleman[i-1]=yeni_kuyruk->eleman[i];
        yeni_kuyruk->son--;
        return cikan_eleman;

    }
}

void listele(Kuyruklar*yeni_kuyruk)
{
    int i;
    for(i=0;i<=yeni_kuyruk->son;i++)
        printf("%d ->",yeni_kuyruk->eleman[i]);
    printf("\n");

}

void main()
{
    Kuyruklar *yeni_kuyruk=Kuyruk_Olustur();
    Enque(yeni_kuyruk,10);
    Enque(yeni_kuyruk,20);
    listele(yeni_kuyruk);
    Enque(yeni_kuyruk,30);
    Enque(yeni_kuyruk,40);
    Enque(yeni_kuyruk,50);
    listele(yeni_kuyruk);
    Enque(yeni_kuyruk,60);
    printf("Dequeu: %d\n",Dequeu(yeni_kuyruk));
    printf("Dequeu: %d\n",Dequeu(yeni_kuyruk));
    listele(yeni_kuyruk);
    printf("Dequeu: %d\n",Dequeu(yeni_kuyruk));
    listele(yeni_kuyruk);
    printf("Dequeu: %d\n",Dequeu(yeni_kuyruk));
    printf("Dequeu: %d\n",Dequeu(yeni_kuyruk));
    printf("Dequeu: %d\n",Dequeu(yeni_kuyruk));


    return 0;
}
