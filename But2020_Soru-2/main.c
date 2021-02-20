#include <stdio.h>
#include <stdlib.h>

//Yiginin icindeki en kucuk elemani bulup yiginin tepesine tasiyan fonksiyonu c programlama dilinde yaziniz.Fonksiyona parametre
//olarak yiginin baslangic adresi gelecektir.
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
    temp->next=head;
    head->prev=temp;
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
    if(head->data==data)
    {
        return head;
    }
    Bliste*iter=head;

    while(iter->data!=data)
        iter=iter->next;

    Bliste*temp1=iter->prev;
    Bliste*temp2=iter->next;

    if(head->next->data==data)
    {
        iter->next=head;
        iter->prev=NULL;
        head->next=temp2;
        head->prev=iter;
        temp2->prev=head;
        return iter;
    }

    else if(iter->next==NULL)
    {
        iter->next=head;
        head->prev=iter;
        iter->prev=NULL;
        temp1->next=NULL;
        return iter;
    }

    else
    {
        iter->next=head;
        iter->prev=NULL;
        head->prev=iter;
        temp1->next=temp2;
        temp2->prev=head;
        return iter;

    }

}

int main()
{
    Bliste*head=NULL;
    head=ekle(head,4);
    head=ekle(head,2);
    head=ekle(head,8);
    head=ekle(head,3);
    head=ekle(head,6);
    head=ekle(head,5);

    listele(head);
    head=swap(head);
    listele(head);


    return 0;
}
























