#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node{
    int data;
    struct node * prev;
    struct node * next;

}Bliste;

Bliste *insert(Bliste*root,int data)
{
    if(root==NULL)
    {
        root=(Bliste*)malloc(sizeof(Bliste));
        root->data=data;
        root->next=root;
        root->prev=root;
        return root;
    }
    Bliste *iter=root;
    if(iter->data > data)
    {
        Bliste*temp=(Bliste*)malloc(sizeof(Bliste));
        temp->data=data;
        temp->next=root;
        temp->prev=root->prev;
        root->prev=temp;
        temp->prev->next=temp;
        return temp;
    }
    while(iter->next->data < data)
    {
        if(iter->next==root)
        {
            iter->next=(Bliste*)malloc(sizeof(Bliste));
            iter->next->data=data;
            iter->next->prev=iter;
            iter->next->next=root;
            root->prev=iter->next;
            return root;

        }
        iter=iter->next;
    }
    Bliste*temp=(Bliste*)malloc(sizeof(Bliste));
    temp->data=data;
    temp->next=iter->next;
    temp->prev=iter;
    iter->next=temp;
    temp->next->prev=temp;
    return root;

}

Bliste * del(Bliste*root,int data)
{
    if(root==NULL)
    return NULL;
    if(root->data==data && root->next==root)
    {
        free(root);
        return NULL;
    }
    if(root->data==data)
    {
       Bliste *temp=root->next;
       temp->prev=root->prev;
       root->prev->next=temp;
       free(root);
       return temp;
    }
    Bliste *iter =root;
    while(iter->data!=data)
    {
        if(iter->next==root)
        return root;
        iter=iter->next;

    }
    iter->next->prev=iter->prev;
    iter->prev->next=iter->next;
    free(iter);
    return root;

}

void print(Bliste *root,Bliste *iter)
{
    if(root!=NULL)
    {
        while(iter->next!=root)
        {
            printf("%d <->",iter->data);
            iter=iter->next;
        }
        printf("%d\n",iter->data);
    }

}


int main()
{
    Bliste *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,25);
    root=insert(root,15);
    root=insert(root,5);
    root=insert(root,300);
    print(root,root);
    root=del(root,5);
    root=del(root,25);
    root=del(root,30);
    root=del(root,15);
    print(root,root);
    getch();


    return 0;
}






