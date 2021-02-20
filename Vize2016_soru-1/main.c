#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Bir kutuphanede kitaplar kitap ismi yazar ismi ve ISBN numarasýný icerecek sekilde cýft yonlu bir bagli
listeye kayýt edilmek istenmektedir.Bunun için:
a) Uygun veri yapýsýný belirleyiniz.
b) Kitap ismine gore alfabetik olarak ekleme islemi yapan fonksiyonu yaziniz.
c) Var olan listeyi ISBN numarasýna gore kucukten buyuge dogru sýralayan fonksiyonu yaziniz. */

typedef struct n
{
    char eser[50];
    char yazar[50];
    int ISBN;
    struct n*next;
    struct n*prev;
} node;

node*KitapEkle(node*root,char eser[50],char yazar[50],int data)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        strcpy(root->eser,eser);
        strcpy(root->yazar,yazar);
        root->ISBN=data;
        root->next=NULL;
        root->prev=NULL;
        return root;
    }

    if(strcmp(root->eser, eser) > 0)
    {

        node*temp=(node*)malloc(sizeof(node));
        strcpy(temp->eser,eser);
        strcpy(temp->yazar,yazar);
        temp->ISBN=data;
        temp->next=root;
        root->prev=temp;
        temp->prev=NULL;
        return temp;
    }

    node*iter=root;
    while(iter->next!=NULL)
    {

        if (strcmp(iter->eser, eser) > 0)
        {

            node*temp=(node*)malloc(sizeof(node));
            strcpy(temp->eser,eser);
            strcpy(temp->yazar,yazar);
            temp->ISBN=data;
            temp->next=iter;
            temp->prev=iter->prev;
            iter->prev->next=temp;
            iter->prev=temp;
            return root;
        }
        iter=iter->next;
    }
    node*temp=(node*)malloc(sizeof(node));
    strcpy(temp->eser,eser);
    strcpy(temp->yazar,yazar);
    temp->ISBN=data;
    temp->next=NULL;
    temp->prev=iter;
    iter->next=temp;
    return root;

}

void bastir(node*root)
{
    if(root==NULL)
        return 0 ;
    node*iter=root;
    while(iter!=NULL)
    {
        printf(" %d ",iter->ISBN);
        iter=iter->next;
    }
    printf("\n");


}
node* sirala(node*root)
{
    if(root==NULL)
        return 0;
    if(root->next==NULL)
        return root;
    node*iter=root;

    while(iter->next!=NULL)
    {
        if(root->ISBN > iter->next->ISBN)
        {
            node*temp=iter->next;
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            temp->next=root;
            temp->prev=NULL;
            root->prev=temp;
            return sirala(temp);
        }
        if(iter->ISBN > iter->next->ISBN && iter->next->next==NULL)
        {
            node*temp=iter->next;
            temp->next=iter->prev;
            iter->next=NULL;
            temp->prev=iter->prev;
            iter->prev->next=temp;
            iter->prev=temp;
            return sirala(root);
        }
        if(iter->ISBN > iter->next->ISBN )
        {
            node*temp=iter->next;
            temp->next=iter->prev;
            iter->next=temp->next;
            temp->prev=iter->prev;
            iter->prev->next=temp;
            iter->prev=temp;
            return sirala(root);
        }
        iter=iter->next;
    }
    return root;
}
int main()
{
    node*root=NULL;
    root=KitapEkle(root,"suc ve ceza","Dostoyoveski",150);
    root=KitapEkle(root,"dhjjhh","Dostoyoveski",45);
    root=KitapEkle(root,"aasahj","Dostoyoveski",82);
    root=KitapEkle(root,"tfbhjf","Dostoyoveski",4);
    root=KitapEkle(root,"cehjfe","Dostoyoveski",178);

    bastir(root);
    root=sirala(root);
    bastir(root);
    return 0;
}


































