#include <stdio.h>
#include <stdlib.h>

//SORU4 2019;
//bir tek yonlu bagli listede kac tane eleman oldugunu ozyinelemeli olarak bulan kodu yaziniz: global degisken kullanmayiniz.

typedef struct n
{
    struct n*next;
    int data;
}node;

node*ekle(node *root,int data)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=data;
        root->next=NULL;
        return root;
    }

    node*iter=root;
    while(iter->next!=NULL)
        iter=iter->next;

    node*temp=(node*)malloc(sizeof(node));
    temp->data=data;
    iter->next=temp;
    temp->next=NULL;
    return root;
}

int recurcive(node*root)
{
    int top=0;
    printf("%d",top);

    while(root->next==NULL)
        return 1;
    root=root->next;

    top++;
    return recurcive(root)+top;
}

int main()
{
    node*root=NULL;
    int x;
    for(int i=0;i<3;i++)
    {
     printf("Bir sayi giriniz:");
     scanf("%d",&x);
     root=ekle(root,x);
    }
    printf("%d",recurcive(root));

    return 0;
}
