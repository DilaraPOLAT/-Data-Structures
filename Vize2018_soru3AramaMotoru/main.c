#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n
{
    struct  n* next;
    struct  n* prev;
    char kelime[10];
    int kac_kere;
} node;



node *Aranan(node *root,char kelime[])
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->next=NULL;
        root->prev=NULL;
        strcpy(root->kelime,kelime);
        root->kac_kere=1;
        return root;
    }
    node*iter=root;
    while(iter!=NULL)
    {
        while(strcmp(iter->kelime,kelime)==0)
        {
            iter->kac_kere++;
            if(iter->prev==NULL)
            {
                return root;
            }
            if(root->next->next==NULL && root->kac_kere < iter->kac_kere )
            {
                root->next=iter->next;
                root->prev=iter;
                iter->next=root;
                iter->prev=NULL;
                return iter;
            }
            node*b=iter;
            int syc=0;
            while(b->prev!=NULL && b->prev->kac_kere < iter->kac_kere)
            {
               b=b->prev;
               syc++;
            }


            if(syc==0)
                return root;

            if(b->prev==NULL && iter->next==NULL)
            {
                iter->prev->next=NULL;
                iter->next=root;
                root->prev=iter;
                iter->prev=NULL;
                return iter;
            }
            if(b->prev==NULL)
            {
                b->next=iter->next;
                iter->next->prev=b;
                b->prev=iter;
                iter->next=b;
                iter->prev=NULL;
                return iter;
            }
             if(iter->next==NULL)
            {
               iter->prev->next=NULL;
            b->prev->next=iter;
            iter->prev=b->prev;
            iter->next=b;
            b->prev=iter;
                return root;
            }


            iter->prev->next=iter->next;
            iter->next->prev=iter->prev;
            b->prev->next=iter;
            iter->prev=b->prev;
            iter->next=b;
            b->prev=iter;
            return root;
        }
        iter=iter->next;
    }



    node*a=root;
    while(a->next!=NULL)
        a=a->next;

    node*temp=(node*)malloc(sizeof(node));
    temp->prev=a;
    a->next=temp;
    temp->next=NULL;
    strcpy(temp->kelime,kelime);
    temp->kac_kere=1;

    return root;
}

void Listele(node*root)
{
    while(root!=NULL)
    {
        printf("%s ,%d\n",root->kelime,root->kac_kere);
        root=root->next;
    }
}
int main()
{
    node*root=NULL;
    char kelime[10];

    for(int i=0; i<20; i++)
    {
        printf("Arama motoru:");
        scanf("%s",&kelime);
        root=Aranan(root,kelime);
        Listele(root);
    }


    return 0;








}
