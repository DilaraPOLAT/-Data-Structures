#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Asagida tanimlanan veri yapisini kullanan tek yonlu bir bagli liste bulunmaktadır.Buna gore kitapekle( kendisine parametre
//olarak gelen kitabı basım yılına gore kucukten buyuge sıralı olarak ekleyen),kitapsil(kendisine parametre olarak gelen isbn numarasındaki
//kitabı listeden silen fonksiyonları yaziniz.

typedef struct Kitap
{
    int  basim_yili,isbn;
    char ad[100];
    char yazar[100];
    struct Kitap*sonraki;
} KListe;

KListe*kitapekle(KListe*kitap,int isbn,int by,char ad[100],char yazar[100])
{
    if(kitap==NULL)
    {
        kitap=(KListe*)malloc(sizeof(KListe));
        kitap->basim_yili=by;
        kitap->isbn=isbn;
        strcpy(kitap->ad,ad);
        strcpy(kitap->yazar,yazar);
        kitap->sonraki=NULL;
        return kitap;
    }
    if(kitap->basim_yili > by)
    {
        KListe*temp=(KListe*)malloc(sizeof(KListe));
        temp->basim_yili=by;
        temp->isbn=isbn;
        strcpy(temp->ad,ad);
        strcpy(temp->yazar,yazar);
        temp->sonraki=kitap;
        return  temp;

    }
    KListe*iter=kitap;
    while(iter->sonraki!=NULL&&iter->sonraki->basim_yili < by)
        iter=iter->sonraki;


    KListe*temp=(KListe*)malloc(sizeof(KListe));
    temp->basim_yili=by;
    temp->isbn=isbn;
    strcpy(temp->ad,ad);
    strcpy(temp->yazar,yazar);
    temp->sonraki=iter->sonraki;
    iter->sonraki=temp;
    return kitap;


}

KListe*kitapsil(KListe*kitap,int silinen)
{
    if(kitap==NULL)
        return -1;
    if(kitap->isbn==silinen&&kitap->sonraki==NULL)
        return 0;
    if(kitap->isbn==silinen)
    {
        KListe*temp=kitap;
        KListe*iter=kitap->sonraki;
        free(temp);
        return iter;
    }
    KListe*iter=kitap;
    while(iter->sonraki!=NULL)
    {
        if(iter->sonraki->isbn==silinen)
        {
            KListe*temp=iter->sonraki;
            iter->sonraki=iter->sonraki->sonraki;
            free(temp);
            return kitap;
        }

        iter=iter->sonraki;
    }

    return kitap;


}
void dolas(KListe*kitap)
{
    KListe*iter=kitap;
    while(iter!=NULL)
    {
        printf(" %d ",iter->basim_yili);
        iter=iter->sonraki;
    }
    printf("\n");


}
int main()
{
    KListe*kitap=NULL;
    kitap=kitapekle(kitap,10,2000,"Suc ve ceza","Dostoyeveski");
    kitap=kitapekle(kitap,45,2020,"Gunun sonunda","Dilara");
    kitap=kitapekle(kitap,7,1999,"ajeweh","ffhrf");
    kitap=kitapekle(kitap,2,2009,"ajeweh","ffhrf");
    kitap=kitapekle(kitap,1,2040,"ajeweh","ffhrf");
    dolas(kitap);
    kitap=kitapsil(kitap,7);
    dolas(kitap);
    kitap=kitapsil(kitap,1);
    dolas(kitap);
    kitap=kitapsil(kitap,2);
    dolas(kitap);

    return 0;
}

























