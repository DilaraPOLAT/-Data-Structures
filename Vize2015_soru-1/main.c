#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Asagýda tanimlanan veri yapýsýný gore olusturulmus list1 ve list2 isimli iki bagli listeyi parametre olarak alan ve veri yapýsný kendinizin
belirleyeceginiz cýft yonlu bir bagli listede ogrenci numarasýna gore kucukten buyuge sýralanmýs sekilde birlestiren ve geri donus degeri numarasýna gore kucukten
buyuge sýralanmýs sekilde birlestiren ve geri donus degeri olarak da iki yonlu bagli listenin baslangýc adresini donduren fonksiyonu ve
yrdýmcý fonksiyonlarý yazýnýz.iki listede ortak kayýt varsa sadece bir tanesi eklenecek.*/

typedef struct ogrenci
{
    int numara;
    char *ad[20],*soyad[20];
    struct ogrenci*sonraki;
} ogrenciler;

typedef struct son
{
    int numara;
    char ad[20],soyad[20];
    struct son *next;
    struct son *prev;
} node;

ogrenciler* ekle(ogrenciler*list,char *ad[20],char *soyad[20],int data)
{
    if(list==NULL)
    {
        list=(ogrenciler*)malloc(sizeof(ogrenciler));
        strcmp(list->ad,ad);
        strcmp(list->soyad,soyad);
        list->numara=data;
        list->sonraki=NULL;
        return list;

    }
    if(list->numara >data)
    {
        ogrenciler*temp=(ogrenciler*)malloc(sizeof(ogrenciler));
        strcmp(temp->ad,ad);
        strcmp(temp->soyad,soyad);
        temp->numara=data;
        temp->sonraki=list;
        return temp;
    }
    ogrenciler*iter=list;
    while(iter->sonraki!=NULL && iter->sonraki->numara < data )
        iter=iter->sonraki;
    if(iter->sonraki!=NULL)
    {
        ogrenciler*temp=(ogrenciler*)malloc(sizeof(ogrenciler));
        strcmp(temp->ad,ad);
        strcmp(temp->soyad,soyad);
        temp->numara=data;
        temp->sonraki=iter->sonraki;
        iter->sonraki=temp;
        return list;
    }
    ogrenciler*temp=(ogrenciler*)malloc(sizeof(ogrenciler));
    strcmp(temp->ad,ad);
    strcmp(temp->soyad,soyad);
    temp->numara=data;
    temp->sonraki=NULL;
    iter->sonraki=temp;
    return list;
}
node*sonekle(ogrenciler*list1,ogrenciler*list2,node*root)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        if(list1!=NULL && list2!=NULL)
        {
            if(list1->numara < list2->numara)
            {
                strcmp(root->ad,list1->ad);
                strcmp(root->soyad,list1->soyad);
                root->numara=list1->numara;
                root->next=NULL;
                root->prev=NULL;
                return sonekle(list1->sonraki,list2,root);

            }
            strcmp(root->ad,list2->ad);
            strcmp(root->soyad,list2->soyad);
            root->numara=list2->numara;
            root->next=NULL;
            root->prev=NULL;
            return sonekle(list1,list2->sonraki,root);
        }
        if(list1!=NULL)
        {
                strcmp(root->ad,list1->ad);
                strcmp(root->soyad,list1->soyad);
                root->numara=list1->numara;
                root->next=NULL;
                root->prev=NULL;
                return sonekle(list1->sonraki,list2,root);
        }
    }

    node*iter=root;


    while(iter->next!=NULL)
        iter=iter->next;

    if(list1!=NULL && list2!=NULL)
    {

        if(list1->numara < list2->numara)
        {
            node*temp=(node*)malloc(sizeof(node));
            strcmp(temp->ad,list1->ad);
            strcmp(temp->soyad,list1->soyad);
            temp->numara=list1->numara;
            temp->next=NULL;
            temp->prev=iter;
            return sonekle(list1->sonraki,list2,root);

        }

        node*temp=(node*)malloc(sizeof(node));
        strcmp(temp->ad,list2->ad);
        strcmp(temp->soyad,list2->soyad);
        temp->numara=list2->numara;
        temp->next=NULL;
        temp->prev=iter;
        return sonekle(list1,list2->sonraki,root);
    }
    if(list1!=NULL)
    {
        node*temp=(node*)malloc(sizeof(node));
        strcmp(temp->ad,list1->ad);
        strcmp(temp->soyad,list1->soyad);
        temp->numara=list1->numara;
        temp->next=NULL;
        temp->prev=iter;
        return sonekle(list1->sonraki,list2,root);
    }
    if(list2!=NULL)
    {

        node*temp=(node*)malloc(sizeof(node));
        strcmp(temp->ad,list2->ad);
        strcmp(temp->soyad,list2->soyad);
        temp->numara=list2->numara;
        temp->next=NULL;
        temp->prev=iter;
        return sonekle(list1,list2->sonraki,root);
    }
    return root;


}
void bastir(ogrenciler*list)
{
    ogrenciler*iter=list;
    while(iter!=NULL)
    {
        printf(" %d ",iter->numara);
        iter=iter->sonraki;
    }
    printf("\n");

}
void sbastir(node*root)
{
    node*iter=root;
    while(iter!=NULL)
    {
        printf(" %d ",iter->numara);
        iter=iter->next;
    }
    printf("\n");

}

int main()
{
    ogrenciler*list1=NULL;
    ogrenciler*list2=NULL;
    node*root=NULL;

    list1=ekle(list1,"ailara","polat",4);
        list2=ekle(list2,"bekdke","demir",15);
        list1=ekle(list1,"tilara","polat",33);
        list2=ekle(list2,"eekdke","demir",78);
        list1=ekle(list1,"wilara","polat",43);
        list2=ekle(list2,"sekdke","demir",2);

    root=sonekle(list1,list2,root);
    sbastir(root);
    bastir(list1);
    bastir(list2);
    return 0;
}




































