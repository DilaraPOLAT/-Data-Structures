#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct lnode{
    int data;
    struct lnode *next;
}stackList;

stackList*iter=NULL;

void push(int data)
{
    if(iter==NULL)
    {
        iter=(stackList*)malloc(sizeof(stackList));
        iter->next=NULL;
        iter->data=data;
    }
    else{
        stackList*yeni=(stackList*)malloc(sizeof(stackList));
        yeni->next=iter;
        yeni->data=data;
        iter=yeni;
    }
}

int pop(){
  if(iter==NULL)
    return -1;
  int result=iter->data;
  stackList*temp=iter;
  iter=iter->next;
  free(temp);
  return result;
}

void printStack()
{
    printf("\n");
    stackList*temp=iter;
    while(temp!=NULL)
    {
        printf("%d_",temp->data);
        temp=temp->next;
    }
}




int main()
{
    push(10);
    printStack();
    push(20);
    printStack();
    push(30);
    printStack();
    printf("\npop> %d",pop());
    printStack();
    printf("\npop> %d",pop());
    printStack();
    printStack();
    printf("\npop> %d",pop());
    printStack();
    printf("\npop> %d",pop());
    printStack();
    getch();

    return 0;
}










