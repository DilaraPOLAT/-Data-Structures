#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct n{
   char kelime[20];
    char anlam[20];
   struct n*next;

}node;


node*ekle(node*r,char kelime[20],char anlam[20]){
    if(r==NULL){//linklist bossa
        r=(node*)malloc(sizeof(node));
        strcpy(r->kelime,kelime);
        strcpy(r->kelime,anlam);
        r->next=NULL;
        return r;
    }

    node *iter=r;
    while(iter->next!=NULL){
        iter=iter->next;
    }
    node *temp=(node*)malloc(sizeof(node));
    strcpy(temp->kelime,kelime);
    strcpy(temp->kelime,anlam);
    temp->next=iter->next;
    iter->next=NULL;;
    return r;
}



int main()
{
   node*root=NULL;
   root=ekle(root,"defh","bhj");
   root=ekle(root,"defh","bhj");






    return 0;
}
