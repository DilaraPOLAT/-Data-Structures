#include <stdio.h>
#include <stdlib.h>
//Bir ikili arama agacina 67,44,56,48,50,52 degerlerini sirasiyla ekleyin ve daha sonra 22,34,20 degerlerini sirasiyla siliniz
//preoder,inorder ve postorder ile dolasiniz.
typedef struct n
{
    int data;
    struct n*sol;
    struct n*sag;

}node;





node* ekle(node*agac,int x)
{
    if(agac==NULL)
    {
        node*root=(node*)malloc(sizeof(node));
        root->data=x;
        root->sag=NULL;
        root->sol=NULL;
        return root;
    }

    if(agac->data<x)
    {
        agac->sag= ekle(agac->sag,x);
        return agac;
    }

    agac->sol= ekle(agac->sol,x);
    return agac;
}


void dolas(node*agac)
{

     if(agac==NULL)
        return;
    dolas(agac->sag);
    printf(" %d ",agac->data);
    dolas(agac->sol);
}

int main()
{
    node*agac=NULL;

    for(int i=1;i<5;i++)
    {
       agac=ekle(agac,i*10);
    }
    dolas(agac);
    return 0;
}
