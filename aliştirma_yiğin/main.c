#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

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

int yigina_Ekle(Yiginlar*yeni_yigin,char ekle)
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


void cevir(Yiginlar*yeni_yigin,int sayi)
{
    int digit;
    while(sayi>0)
    {
       digit=sayi%2;
       yigina_Ekle(yeni_yigin,digit);
       sayi=sayi/2;
    }
    while(yeni_yigin->indis>0)
    {
        digit=Yigindan_cikar(yeni_yigin);
        printf("%d",digit);
    }

}

int Parantez_Kontrol(Yiginlar*yeni_yigin,char *islem)
{
    int i;
    for(i=0;i<strlen(islem);i++)
    {
        if(islem[i]=='(')
            yigina_Ekle(yeni_yigin,islem);


        else
        {
            if(islem[i]==')')
                if(Yigin_Bosmu(yeni_yigin)==-1)
                  return-1;
                else
                    Yigindan_cikar(yeni_yigin);
        }
    }
    if(Yigin_Bosmu(yeni_yigin)!=-1)return 0;
    else
    {
      return 1;
    }

}



void main()
{
    Yiginlar*yeni_yigin=Yigin_olustur();
    printf("yeni yigin olustu");
    int i;
    char secim;
    char s[100];
    system("cls");
    printf("kontrol stringi");
    scanf("%s",&s);
    for(i=0;i<strlen(s);i++)
    {
        if((s[i]=='*')||(s[i]=='/')||(s[i]=='+')||(s[i]=='-'))
        {
            while(Yigin_Bosmu(Yiginlar))
            {
                char temp;

            }
        }
    }


    return 0;
}







