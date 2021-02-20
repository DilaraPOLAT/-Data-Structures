#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    struct n*next;
    int data;

}node;




int pop(node*root)
{
    if(root==NULL)
    {
        printf("stack bos");
        return -1;
    }

    if(root->next==NULL)
    {
         int rvalue=root->data;
         free(root);
         return rvalue;
    }
    node *iter=root;
    while(iter->next->next!=NULL)
       iter=iter->next;
    node*temp= iter->next;
    int rvalue=temp->data;
    free(temp);
    iter->next=NULL;
    return rvalue;
}


node* push(node*root,int a)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=a;
        root->next=NULL;
        return root;
    }

    node *iter=root;
    while(iter->next!=NULL)
        iter=iter->next;
    node *temp=(node*)malloc(sizeof(node));
    temp->data=a;
    iter->next=temp;
    temp->next=NULL;
    return root;
}
int main()
{
   node*s=NULL;
   s=push(s,10);
   s=push(s,20);
   printf("%d->",pop(s));
   s=push(s,30);
   printf("%d->",pop(s));
   printf("%d->",pop(s));
    return 0;
}
