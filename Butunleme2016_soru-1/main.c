#include <stdio.h>
#include <stdlib.h>
//bir ikili agactaki toplam dugum sayisini bulan ozyinelemeli fonksiyonu yaziniz.

typedef struct n
{
    int deger;
    struct n*sag;
    struct n*sol;
} node;

node*ekle(node*agac,int data)
{
    if(agac==NULL)
    {
        node*root=(node*)malloc(sizeof(node));
        root->deger=data;
        root->sag=NULL;
        root->sol=NULL;
        return root;
    }
    if(agac->deger < data)
    {
        agac->sag=ekle(agac->sag,data);
        return agac;
    }
    agac->sol=ekle(agac->sol,data);
    return agac;
}


void dolas(node*agac)
{
    if(agac==NULL)
        return;
    dolas(agac->sag);
    printf(" %d ",agac->deger);
    dolas(agac->sol);
}

int Dugum(node*agac)
{
    if(agac==NULL)
        return 0;
    return 1+Dugum(agac->sag)+Dugum(agac->sol);

}

int main()
{
    node*agackok=NULL;
    agackok=ekle(agackok,44);
    agackok=ekle(agackok,20);
    agackok=ekle(agackok,10);
    agackok=ekle(agackok,73);
    agackok=ekle(agackok,21);
    agackok=ekle(agackok,84);
    agackok=ekle(agackok,99);
    agackok=ekle(agackok,60);
    dolas(agackok);
    int x=Dugum(agackok);
    printf("cikti:%d",x);







    return 0;
}
























