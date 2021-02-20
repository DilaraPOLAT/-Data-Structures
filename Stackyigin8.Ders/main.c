#include <stdio.h>
#include <stdlib.h>
int *dizi=NULL;
int boyut=2;
int tepe=0;

int pop()
{
  if(dizi==NULL)
    {
        printf("Dizi bos");
        return -1;
    }

  if(tepe<=boyut/4)
    {
        int *dizi2=(int*)malloc(sizeof(int)*boyut/2);

        for(int i=0; i<boyut; i++){
            dizi2[i]=dizi[i];

        }

        free(dizi);
        dizi=dizi2;
        boyut/=2;

  }
  return dizi[--tepe];
}

void push (int a)
{
    if(dizi==NULL)
    {
      dizi=(int*)malloc(sizeof(int)*2);
    }

    if(tepe>=boyut)
    {
        int *dizi2=(int*)malloc(sizeof(int)*boyut*2);
        for(int i=0;i<boyut;i++)
            dizi2[i]=dizi[i];
        free(dizi);
        dizi=dizi2;
        boyut*=2;

    }
    dizi[tepe++]=a;
}

void bastir()
{
    printf("Boyut :%d\n",boyut);
    if(dizi==NULL)
    {
        printf("Dizi bos");
        return -1;
    }
    for(int i=0;i<tepe;i++)
    {
        printf("%d\t",dizi[i]);

    }
    printf("\n");
}

int main()
{
    printf("popped %d\n",pop());
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    bastir();
    printf("popped %d\n",pop());
    printf("popped %d\n",pop());
    printf("popped %d\n",pop());
    printf("popped %d\n",pop());
    printf("popped %d\n",pop());
    bastir();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    bastir();










    return 0;
}















