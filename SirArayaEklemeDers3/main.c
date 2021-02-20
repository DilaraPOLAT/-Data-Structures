#include <stdio.h>
#include <stdlib.h>
typedef struct n{
   int x;
   struct n*next;
}node;


void pushit(node*r){//bastir
    while(r!=NULL){
        printf("%d\t",r->x);
        r=r->next;
    }
}


node*add_ordered(node*r,int x){
    if(r==NULL){//linklist bossa
        r=(node*)malloc(sizeof(node));
        r->next=NULL;
        r->x=x;
        return r;
    }
    if(r->x>x){//ilk eleman kucuk durumu
            node*temp=(node*)malloc(sizeof(node));//root deðsiyor
            temp->x=x;
            temp->next=r;
            return temp;
        }
    node *iter=r;
    while(iter->next!=NULL && iter->next->x <x){
        iter=iter->next;
    }
    node *temp=(node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=x;
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



    return 0;
}
