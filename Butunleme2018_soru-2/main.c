#include <stdio.h>
#include <stdlib.h>
//Kendisine parametere olarak gelen tek yonlu bagli listeyi ilk eleman son eleman ve son eleman ilk eleman olacak sekilde
//tersine ceviren kodu yaziniz.

typedef struct n
{
    int eleman;
    struct n *next;
} node;

node*ekle(node*root,int data)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->eleman=data;
        root->next=NULL;
        return root;
    }
    node*temp=(node*)malloc(sizeof(node));
    temp->eleman=data;
    temp->next=root;
    return temp;
}
void bastir(node*root)
{
    node*iter=root;
    while(iter!=NULL)
    {
        printf(" %d ",iter->eleman);
        iter=iter->next;
    }


}
int main()
{
    node*root=NULL;
    root=ekle(root,10);
    root=ekle(root,240);
    root=ekle(root,45);
    root=ekle(root,89);
    root=ekle(root,9);
    bastir(root);
    return 0;
}

































