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
    temp->prev=NULL;
    iter->next=NULL;
    temp->next=head;
    return temp;

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
Bliste*swap(Bliste*head)
{
    Bliste*itere=head;
    int data=1000;
    while(itere!=NULL)
    {
        if(itere->data < data)
        {
            data=itere->data;

        }
        itere=itere->next;
    }
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
        printf("fff");
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

int main()
{
    Bliste*head=NULL;
    head=ekle(head,40);
    head=ekle(head,30);
    head=ekle(head,9);
    head=ekle(head,10);

    listele(head);
    head=swap(head);
    listele(head);


    return 0;
}
























