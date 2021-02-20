#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//2020 Vize
typedef struct n
{
    char arama[25];
    struct n*next;
    struct n*prev;
}node;

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
    iter->next=root;
    temp->next=root;
    root->prev=temp;
    temp->prev=NULL;
    strcpy(temp->arama,arama);
    return temp;

}
void yazdir(node*root)
{
    int x,y;
     if(root==NULL)
    {
      printf("yiðin bos:");
    }
    node*iter=root;

    while(iter->next!=NULL)
    {

         printf("kac kere geri tusuna basmak isteriniz 1 e;");
          scanf("%d",&x);
         printf("kac kere geri tusuna basmak isteriniz 2 e;");
        scanf("%d",&y);
        if(x==1)
        {
            printf("%s",iter->arama);
            iter=iter->next;
        }
         else if(x==2)
        {
            printf("%s",iter->arama);
            iter=iter->prev;
        }

    }
    }

int main()
{
    node *root=NULL;
    char ad[25];
    int sayi,x,y;

    printf("kac kere arama motoru ekleyeceksiniz:");
    scanf("%d",&sayi);
    for(int i=0;i<sayi;i++)
    {
        printf("Arama motoru giriniz:");
    scanf("%s",&ad);
      root=ekleme(root,ad);
    }
    yazdir(root);



    return 0;
}
