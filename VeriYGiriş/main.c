#include <stdio.h>
#include <stdlib.h>
typedef struct n{
   int x;
   struct n*next;
}node;


void bastir(node*r){
    while(r!=NULL){
        printf("%d\t",r->x);
        r=r->next;

    }
}

int main()
{
    node *root;
    root=(node*) malloc(sizeof(node));
    root->x=10;
    root->next=(node*)malloc(sizeof(node));
    root->next->x=20;
    root->next->next=(node*)malloc(sizeof(node));
    root->next->next->x=30;
    root->next->next->next=NULL;
    node *iter;
    iter=root;
    printf("%d\n",iter->x);
    iter=iter->next;
    printf("%d",iter->x);
    iter=root;
    int i=0;
    while(iter->next!= NULL){//iter!=NULL   iter NULL gösteriyor.ama iter->next !=NULL iterin nexti null gösterdiðinde.
     i++;
     printf("%d.nin elemani: %d\n",i,iter->x);
     iter=iter->next;
    }
    for(i=0;i<5;i++){
        iter->next=(node*)malloc(sizeof(node));
        iter=iter->next;
        iter->x=i*10;
        iter->next=NULL;
    }
    bastir(root);


    return 0;
}
