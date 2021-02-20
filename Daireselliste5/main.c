#include <stdio.h>
#include <stdlib.h>
typedef struct n{
   int x;
   struct n*next;
}node;


void pushit(node*r){//bastir fonk
    node *iter=r;
    printf("%d\t",iter->x);
    iter=iter->next;
    while(iter!=r){
        printf("%d\t",iter->x);
        iter=iter->next;
    }
    printf("\n");
}


void ekle(node*r,int x){
    node*iter=r;
    while(iter->next!=r){
        iter=iter->next;
    }
    iter->next=(node*)malloc(sizeof(node*));
    iter->next->x=x;
    iter->next->next=r;



}


node*add_ordered(node*r,int x){//ekle fonk
    if(r==NULL){//linklist bossa
        r=(node*)malloc(sizeof(node));
        r->next=r;
        r->x=x;
        return r;
    }
    if(r->x>x){//ilk eleman kucuk durumu
            node*temp=(node*)malloc(sizeof(node));//root deðsiyor
            temp->x=x;
            temp->next=r;
            node*iter=r;
            while(iter->next!=r){
                iter=iter->next;
            }
            iter->next=temp;
            return temp;
    }
    node *iter=r;
    while(iter->next!=r && iter->next->x < x){
        iter=iter->next;
    }
    node *temp=(node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=x;
    return r;
}


node *sil(node*r,int x){
    node*temp;
    node*iter=r;
    if(r->x==x){
        while(iter->next!=r){
            iter=iter->next;

        }
        iter->next=r->next;
         free(r);
         return iter->next;
    }
    while(iter->next!=r && iter->next->x!=x){
        iter=iter->next;
    }
    if(iter->next==r){
        printf("Sayi bulunamadi");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    return r;
}


int main()
{
    node*root;
    root=NULL;
    root=add_ordered(root,400);
    root=add_ordered(root,40);
    root=add_ordered(root,4);
    root=add_ordered(root,450);
    root=add_ordered(root,50);
    pushit(root);
    root=sil(root,50);
    pushit(root);
    root=sil(root,999);
    pushit(root);
    root=sil(root,4);
    pushit(root);
    root=sil(root,450);
    pushit(root);


    return 0;
}
