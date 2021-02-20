#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define YBoyut 100
typedef struct Yigin{
    int indis;
    int eleman[YBoyut];
}Yiginlar;

Yiginlar *Yigin_olustur()
{
    Yiginlar*yeni_yigin;
    yeni_yigin=(Yiginlar*)malloc(sizeof(Yiginlar));
    yeni_yigin->indis=0;
    return yeni_yigin;
}

int Yigin_Dolumu(Yiginlar*yeni_yigin)
{
    if(yeni_yigin->indis>=YBoyut)
        return -1;
    else
        return 1;
}

int Yigin_Bosmu(Yiginlar*yeni_yigin)
{
    if(yeni_yigin->indis==0)
        return -1;
    else
        return 1;
}

int yigina_Ekle(Yiginlar*yeni_yigin,int ekle)
{
    if(Yigin_Dolumu(yeni_yigin)==-1)
    {
        printf("yigin Dolu\n");
        getch();
        return -1;
    }
    else
    {
       yeni_yigin->eleman[yeni_yigin->indis]=ekle;
       yeni_yigin->indis++;
       return 1;
    }
}

int Yigindan_cikar(Yiginlar*yeni_yigin)
{
    int cikan_eleman;
    if(Yigin_Bosmu(yeni_yigin)==-1)
    {
        printf("yigin Bos\n");
        getch();
        return -1;
    }

    else
    {
        yeni_yigin->indis--;
        cikan_eleman=yeni_yigin->eleman[yeni_yigin->indis];
        return cikan_eleman;
    }
}


void main()
{
    Yiginlar*yeni_yigin=Yigin_olustur();
    int numara;
    free(yeni_yigin);
    getch();
    return 0;
}







