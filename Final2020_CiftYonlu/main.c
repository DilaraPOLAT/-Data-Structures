#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int data;
    struct node*next;
    struct node*prev;
} Bliste;

Bliste*ekle(Bliste*head,int data)
{
    if(head==NULL)
    {
        head=(Bliste*)malloc(sizeof(Bliste));
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        return head;
    }
    Bliste*temp=(Bliste*)malloc(sizeof(Bliste));
    temp->data=data;

    Bliste*iter=head;
    while(iter->next!=NULL)
        iter=iter->next;
    temp->prev=iter;
    iter->next=temp;
    temp->next=NULL;
    return head;

}
Bliste*araelemanekleme(Bliste*head,int data,int ara)
{

    Bliste*temp=(Bliste*)malloc(sizeof(Bliste));
    temp->data=data;

    Bliste*iter=head;
    while(iter->data!=ara)
        iter=iter->next;

    temp->prev=iter;
    temp->next=iter->next;
    iter->next=temp;
    return head;

}
void listele(Bliste*head)
{
    Bliste*iter=head;
    while(iter!=NULL)
    {
        printf(" %d ",iter->data);
        iter=iter->next;
    }
    printf("\n");
}
Bliste*swap(Bliste*head,int data)
{

    Bliste*iter=head;
    while(iter->data!=data)
        iter=iter->next;
    Bliste*temp=iter->prev;
    Bliste*temp2=iter->next;
    if(head->next->data==data)
    {
        iter->next=head;
        iter->prev=NULL;
        head->next=temp2;
        temp2->prev=head;
        return iter;


    }
    else if(iter->next==NULL)
    {

        iter->next=head->next;
        iter->prev=NULL;
        head->next->prev=iter;
        temp->next=head;
        head->next=NULL;
        head->prev=temp;
        return iter;
    }
    else
    {
        iter->next=head->next;
        iter->prev=NULL;
        head->next->prev=iter;
        temp->next=head;
        head->next=temp2;
        temp2->prev=head;
        head->prev=temp;
        return iter;

    }
}
Bliste*sil(Bliste*head)
{
    if(head==NULL)
        return 0;
    Bliste*iter=head;
    head=iter->next;
    free(iter);
    return head;
}
int main()
{
    Bliste*head=NULL;
    head=ekle(head,10);
    head=ekle(head,20);
    head=ekle(head,30);
    head=ekle(head,40);
    listele(head);
    int m=head->next->next->data;
    int p=50;
    head=araelemanekleme(head,p,m);
    listele(head);
    head=swap(head,m);
    listele(head);
    head=sil(head);
    listele(head);


    return 0;
}
