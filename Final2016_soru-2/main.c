#include <stdio.h>
#include <stdlib.h>
//kok nodeun adresini parametre olarak gelen bir binary treedeki elemanlarýn  toplamýný bulan recursive fonksiyonu.
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

int recursive(node*agac)
{
    int toplam=0;
    if(agac==NULL)
        return 0;

    toplam=agac->deger;
    return toplam+recursive(agac->sag) +recursive(agac->sol);

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
    printf("%d",recursive(agackok));

    return 0;
}

























