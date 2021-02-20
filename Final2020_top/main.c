#include <stdio.h>
#include <stdlib.h>

typedef struct lnode
{
    int data;
    struct lnode *next;

} StackList;

StackList*yigin1=NULL;
StackList*yigin2=NULL;
StackList*yigin3=NULL;
StackList*iterator;

int pop(StackList*yigin1);
int top(StackList*yigin1);
void push(StackList*yigin3,int data);
int empty(StackList*yigin1);
void karsilastir(StackList*yigin1,StackList*yigin2);


StackList*ekle(StackList*yigin,int data)
{
    if(yigin==NULL)
    {
        yigin=(StackList*)malloc(sizeof(StackList));
        yigin->data=data;
        yigin->next=NULL;
        return yigin;
    }
    else if(yigin->data>data)
    {
        StackList*temp;
        temp=(StackList*)malloc(sizeof(StackList));
        temp->data=data;
        temp->next=yigin;
        return temp;
    }
    StackList*iter=yigin;
    StackList*prev=yigin;

    while(iter!=NULL)
    {
        if(iter->data>data)
        {
            StackList*temp;
            temp=(StackList*)malloc(sizeof(StackList));
            temp->data=data;
            temp->next=iter;
            prev->next=temp;
            return yigin ;
        }
        prev=iter;
        iter=iter->next;
    }

    StackList*temp;
    temp=(StackList*)malloc(sizeof(StackList));
    temp->data=data;
    prev->next=temp;
    temp->next=NULL;
    return yigin ;
}
void karsilastir(StackList*yigin1,StackList*yigin2)
{
    while(empty(yigin1)==1 && empty(yigin2)==1)
    {

        if(top(yigin1)<top(yigin2))
        {
            push(yigin3,pop(yigin1));
            printf(" yigin1  ");
            liste(yigin1);

        }

        else
        {
            push(yigin3,pop(yigin2));
             printf(" yigin2  ");
             liste(yigin2);
        }
    }
    if(empty(yigin1)==1)
    {
        while(empty(yigin1)==1)
        {
            push(yigin3,pop(yigin1));
             printf(" yigin1  ");
            liste(yigin1);
        }
    }
    else if(empty(yigin2)==1)
    {
        while(empty(yigin2)==1)
        {
            push(yigin3,pop(yigin2));
            printf(" yigin2  ");
             liste(yigin2);
        }
    }


}
int empty(StackList*yigin)
{
    if(yigin==NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

int top(StackList*yigin)
{
    return yigin->data;

}

void push(StackList*yigin3,int data)
{
    if(empty(yigin3)==0)
    {
        yigin3=(StackList*)malloc(sizeof(StackList));
        yigin3->data=data;
        yigin3->next=NULL;

        return;
    }
    else
    {
        iterator=yigin3;
        while(iterator!=NULL)
            iterator=iterator->next;
        StackList*yeni=(StackList*)malloc(sizeof(StackList));
        yeni->data=data;
        yeni->next=iterator;
        yigin3=yeni;

        return ;

    }
}
void liste(StackList*yigin)
{
    iterator=yigin;
    while(iterator!=NULL)
    {
        printf("%d\t",iterator->data);
        iterator=iterator->next;
    }
    printf("\n");
}

int pop(StackList*yigin)
{
    iterator=yigin;
    int a=yigin->data;
    if(yigin==yigin1)
    {
        yigin1=yigin1->next;
        free(iterator);
        return a;
    }

    yigin2=yigin2->next;
    free(iterator);
    return a;

}
int main()
{

    yigin1=ekle(yigin1,10);
    yigin1=ekle(yigin1,50);

    liste(yigin1);

    liste(yigin2);

    karsilastir(yigin1,yigin2);
    liste(yigin1);
    printf("aaaa");



    return 0;
}





































