#include <stdio.h>
#include <stdlib.h>
typedef struct n{
   int x;
   struct n*next;
   struct n*prev;
}node;


void pushit(node*r){//bastir
    while(r!=NULL){
        printf("%d->",r->x);
        r=r->next;
    }
    printf("\n");
}



node*add_ordered(node*r,int x){
    if(r==NULL){//linklist bossa
        r=(node*)malloc(sizeof(node));
        r->next=NULL;
        r->prev=NULL;
        r->x=x;
        return r;
    }
    if(r->x>x){//ilk eleman kucuk durumu
            node*temp=(node*)malloc(sizeof(node));//root deðsiyor
            temp->x=x;
            temp->next=r;
            r->prev=temp;
            return temp;
        }
    node *iter=r;
    while(iter->next!=NULL && iter->next->x <x){
        iter=iter->next;
    }
    node *temp=(node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->prev=iter;

    if(temp->next!=NULL){
       temp->next->prev=temp;
    }
    temp->x=x;
    return r;
}
node*sil(node*r,int x){
    node*temp=r;
    node*iter=r;
    if(r->x==x){
        r=r->next;
        free(temp);
        return r;
    }
    while(iter->next!=NULL && iter->next->x!=x){
        iter=iter->next;
    }
    if(iter->next==NULL){
        printf("Sayi bulunamadi\n");
        return r;
    }
    temp=iter->next;
    iter->next=iter->next->next;
    free(temp);
    if(iter->next!=NULL){

      iter->next->prev=iter;

    }

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
