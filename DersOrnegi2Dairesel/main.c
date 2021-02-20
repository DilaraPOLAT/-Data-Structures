#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* next;

} BListe;

BListe *insert(BListe *ll,int data);
BListe *insert2(BListe *ll,int data);
void print1n(BListe *ll);
BListe *del(BListe *ll,int data);

BListe *insert2(BListe *ll,int data)
{
    if(ll==NULL)
    {
        ll=(BListe*)malloc(sizeof(BListe));
        ll->data=data;
        ll->next=ll;
        return ll;
    }
    BListe *temp=(BListe*)malloc(sizeof(BListe));
    temp->data=data;
    BListe*iter=ll;
    while(iter->next!=ll)
        iter=iter->next;
    temp->next=ll;
    iter->next=temp;
    return ll;

}

BListe *insert(BListe*ll,int data)
{
    if(ll==NULL)
    {
        ll=(BListe*)malloc(sizeof(BListe));
        ll->data=data;
        ll->next=ll;
        return ll;

    }
    if(ll->data > data)
    {
        BListe *temp=(BListe*)malloc(sizeof(BListe));
        temp->data=data;
        temp->next=ll;
        BListe *iter=ll;
        while(iter->next!=ll)
            iter=iter->next;
        iter->next=temp;
        return temp;
    }

    BListe *iter=ll;
    while(iter->next!=ll && iter->next->data < data)
        iter=iter->next;
    BListe *temp=(BListe*)malloc(sizeof(BListe));
    temp->data=data;
    temp->next=iter->next;
    iter->next=temp;
    temp->data=data;
    return ll;
}

void print1n(BListe *ll)
{
    BListe *iter=  ll;
    printf("\n");
    while(ll->next!=iter)
    {
        printf(" %d ",ll->data);
        ll=ll->next;
    }
    printf(" %d ",ll->data);
}

BListe *del(BListe *ll,int data)
{
    if(ll==NULL)
        return NULL;
    else if(ll->next==ll && ll->data==data)
    {
        return NULL;
    }
    else
    {
        BListe *iter=ll;
        while(iter->next!=ll)
        {
            if(iter->next->data==data)
            {
                BListe*temp=iter->next;
                iter->next=temp->next;
                free(temp);
                return ll;
            }
            iter=iter->next;
        }
        if(ll->data==data)
        {
            iter->next=iter->next->next;
            free(ll);
            ll=iter->next;
            return ll;
        }
    }
    return ll;
}


int main()
{
    BListe *ll=NULL;
    ll=insert(ll,20);
    ll=insert(ll,10);
    ll=insert(ll,40);
    ll=insert(ll,30);
    print1n(ll);
    ll=del(ll,10);
    print1n(ll);

    return 0;
}
