#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct n
{
    char arama[25];
    struct n*next;
    struct n*prev;
} node;

node*ekleme(node*root,char arama[25])
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->next=NULL;
        root->prev=NULL;
        strcpy(root->arama,arama);
        return root;
    }

    node*iter=root;

    while(iter->next!=NULL)
        iter=iter->next;
    node*temp=(node*)malloc(sizeof(node));
    root->prev=temp;
    temp->next=root;
    temp->prev=NULL;
    strcpy(temp->arama,arama);
    return temp;

}
void yazdir(node*root)
{
    int x;
    if(root==NULL)
    {
        printf("Yigin bos:");
    }
    node*iter=root;

    while(iter!=NULL)
    {

        printf("GERI TUSU icin:1 - ILERI TUSU :2 icin  :");
        scanf("%d",&x);

        if(x==1)
        {
            iter=iter->next;
            printf("%s\n",iter->arama);
        }
        else if(x==2)
        {
            iter=iter->prev;
            printf("%s\n",iter->arama);
        }
        else
            printf("Lutfen tuslara duzgun basiniz!");

    }
    if(iter==NULL)
      printf("Web tarayicisi bulunamadi!");

}

int main()
{
    node *root=NULL;
    char ad[25];
    int sayi,x,y;

    printf("kac kere arama motoru ekleyeceksiniz:");
    scanf("%d",&sayi);
    for(int i=0; i<sayi; i++)
    {
        printf("Arama motoru giriniz:");
        scanf("%s",&ad);
        root=ekleme(root,ad);
    }
    yazdir(root);



    return 0;
}
