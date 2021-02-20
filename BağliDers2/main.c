#include <stdio.h>
#include <stdlib.h>
typedef struct n{
   int x;
   struct n*next;
}node;


void pushit(node*r){
    while(r!=NULL){
        printf("%d\t",r->x);
        r=r->next;
    }
}
void add(node*y,int a){
    while(y->next!=NULL){
        y=y->next;
    }
    y->next=(node*)malloc(sizeof(node));
    y->next->x=a;
    y->next->next=NULL;
}

int main()
{
    node*root;
    root=(node*)malloc(sizeof(node));
    root->x=500;
    root->next=NULL;
    int i;
    for(i=0;i<5;i++){
       add(root,i*10);
    }
    pushit(root);
    node*iter=root;
    for(i=0;i<3;i++){
        iter=iter->next;
    }
    node*temp=(node*)malloc(sizeof(node));
    temp->next=iter->next;
    iter->next=temp;
    temp->x=100;
    pushit(root);


    return 0;
}
