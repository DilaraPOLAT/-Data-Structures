#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct n{
    int number;
    char name[25];
    struct n*next;
    struct n*prev;
}node;

void pushit(node*r){
    while(r!=NULL){
      printf("Kisi adi :%s\n number:%d\n",r->name,r->number);
      r=r->next;
    }
    printf("\n");

}

node*ekle(node*r,int number,char name[25]){
    if(r==NULL){
        r=(node*)malloc(sizeof(node));
        r->next=NULL;
        r->prev=NULL;
        r->number=number;
        strcpy(r->name,name);

        return r;
    }

    node*iter=r;
    while(iter->next!=NULL){
            iter=iter->next;

    }
    node*temp= (node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->prev=iter;
    temp->next=NULL;
    temp->number=number;
    strcpy(temp->name,name);
    free(temp);

    return r;

}


void bul(node*r){
    node *iter=r;
    int syc=0;
    char ad[25];
    printf("Aranacak isim giriniz:");
    scanf("%s",&ad);
    while(iter!=NULL)
    {
        if(strcmp(iter->name,ad)==0)
        {   printf("kisi adi :%s , numara:%d\n",iter->name,iter->number);
            syc++;

        }
        iter=iter->next;

    }
    if(syc=0){
        printf("Rehberde aranan isimde biri yok!\n");
    }
}

node*silme(node*r){
    node *iter=r;
    int syc=0;
    char ad[25];
    printf("Silinecek isim giriniz:");
    scanf("%s",&ad);
    while(iter!=NULL)
    {
        if(strcmp(iter->name,ad)==0)
        {
            printf("kisi adi :%s , numara:%d\n",iter->name,iter->number);
            syc++;
            node*temp=iter->next;
            iter->next=iter->next->next;
            return iter;
        }
        iter=iter->next;


    }
    if(syc=0){
        printf("Rehberde aranan isimde biri yok!\n");
    }

}


int main()
{
    node*root;
    root=NULL;
    int a,i,x,y;

    root=ekle(root,482,"Dilara");
    root=ekle(root,714,"Sevim");
    root=ekle(root,19,"Polat");
    do
    {
        printf("-Kisi Eklemek icin:1\n-Rehber listelemek icin:2\n-Arama yapmak icin:3\n-Silmek icin 4 basiniz.");
        scanf("%d",&x);
        if(x==1)
        {
            printf("Kac kisi ekleyeceksiniz:");
            scanf("%d",&a);
            for(i=0; i<a; i++)
            {
                char nam[10];
                int num;
                printf("Kisi adi:");
                scanf("%s",&nam);
                printf("Kisi no:");
                scanf("%d",&num);
                root=ekle(root,num,nam);
            }

        }
        else if(x==2){
             pushit(root);

        }

         else if(x==3){
             bul(root);

        }
        else if(x==4){
            root=silme(root);
        }
        printf("islemler devam etmek istiyorsaniz '0' a basiniz. \n");
        scanf("%d",&y);
    }while(y==0);

    return 0;




}
