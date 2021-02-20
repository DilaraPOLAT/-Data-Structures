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
            ++iter->kac_kere;
            node*b=iter;
            if(iter->prev==NULL)
                return root;
            while(iter->kac_kere > b->prev->kac_kere)
            {
                if(b->prev->prev==NULL && iter->next==NULL)
                {
                    node*temp=(node*)malloc(sizeof(node));
                    strcpy(temp->kelime,iter->kelime);
                    temp->kac_kere=iter->kac_kere;
                    temp->next=b->prev;
                    b->prev->prev=temp;
                    temp->prev=NULL;
                    b->prev->next=NULL;
                    return temp;
                }
                else if(b->prev->prev==NULL)
                {
                    node*temp=(node*)malloc(sizeof(node));
                    strcpy(temp->kelime,iter->kelime);
                    temp->kac_kere=iter->kac_kere;
                    temp->next=b->prev;
                    b->prev->prev=temp;
                    temp->prev=NULL;
                    b->prev->next=b->next;
                    b->next->prev=b->prev;
                    return temp;
                }
                else
                {
                    node*temp=(node*)malloc(sizeof(node));
                    strcpy(temp->kelime,iter->kelime);
                    temp->kac_kere=iter->kac_kere;
                    temp->next=b->prev;
                    temp->prev=b->prev->prev;
                    b->prev->prev->next=temp;
                    b->prev->prev=temp;
                    b->prev->next=b->next;
                    b->next->prev=temp->next;
                    return temp;
                }
                 b=b->prev;
                if(b==NULL)
                    break;
            }
            return root;
        }
        iter=iter->next;
    }
    if(root->next==NULL)
    {
        node*temp=(node*)malloc(sizeof(node));
        root->next=temp;
        temp->prev=root;
        temp->next=NULL;
        strcpy(temp->kelime,kelime);
        temp->kac_kere=1;
        return root;
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
