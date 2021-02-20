#include <stdio.h>
#include <stdlib.h>

int*dizi=NULL;
int sirabasi=0,sira=0,boyut=2;

int deque()
{
    if(sirabasi==sira)
    {
        printf("sira bos");
        return -1;
    }
    if(sira-sirabasi<=boyut/4)
    {
        int*dizi2=(int*)malloc(sizeof(int)*boyut/2);
        for(int i=0;i<sira-sirabasi;i++)
        {
            dizi2[i]=dizi[sirabasi+i];
        }

        sira-=sirabasi;
        sirabasi=0;
        free(dizi);
        boyut/=2;
        dizi=dizi2;

    }

    return dizi[sirabasi++];
}

void toparla()
{
    if(sirabasi==0)
        return;
    for(int i=0;i<boyut;i++)
    {
        dizi[i]=dizi[i+sirabasi];
    }
    sira-=sirabasi;
    sirabasi=0;
}

void enque(int a)
{
    if(dizi==NULL)
    {
        dizi=(int*)malloc(sizeof(int)*2);
    }
    if(sira>=boyut)
    {
        boyut*=2;
        int *dizi2=(int*)malloc(sizeof(int)*boyut);
        for(int i=0;i<boyut;i++)
            dizi2[i]=dizi[i];
        free(dizi);
        dizi=dizi2;

    }
    dizi[sira++]=a;
}

int main()
{
   for(int i=0;i<20;i++)
   {
       enque(i*10);
   }
   toparla();
   printf("\ndurum:boyut:%d,sira:%d,sirabasi:%d\n",boyut,sira,sirabasi);
    for(int i=0;i<13;i++)
   {
       printf("%d ",deque());
   }
   toparla();
   printf("\ndurum:boyut:%d,sira:%d,sirabasi:%d\n",boyut,sira,sirabasi);
   for(int i=0;i<20;i++)
   {
       enque(i*10);
   }
   toparla();
   printf("\ndurum:boyut:%d,sira:%d,sirabasi:%d\n",boyut,sira,sirabasi);
   for(int i=0;i<30;i++)
   {
       printf("%d ",deque());
   }


    return 0;
}













