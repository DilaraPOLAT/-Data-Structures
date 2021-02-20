#include <stdio.h>
#include <stdlib.h>

typedef struct liste
{
    int numara;
    struct liste*sonraki;
} Bliste;
Bliste *ilk=NULL;

Bliste*ekle(int data)
{
    if(ilk==NULL)
    {
        ilk=(Bliste*)malloc(sizeof(Bliste));
        ilk->sonraki=NULL;
        ilk->numara=data;
        return ilk;
    }
    else
    {
        Bliste*iter=ilk;
        while(iter->sonraki!=NULL)
            iter=iter->sonraki;
        Bliste*temp=(Bliste*)malloc(sizeof(Bliste));
        iter->sonraki=temp;
        temp->numara=data;
        temp->sonraki=NULL;
        return ilk;
    }
}

int search(struct liste* adres)
{
    if(ilk==NULL)
        return NULL;
    Bliste*iter=ilk;
    while(iter!=NULL)
    {
        if(iter==adres)
            return iter->numara;
        iter=iter->sonraki;

    }
    return NULL;
}
int main()
{

    ilk=ekle(10);
    ilk=ekle(20);
    ilk=ekle(30);
    ilk=ekle(40);
    printf("%d\n",search(ilk->sonraki->sonraki));
     printf("%d",search(2));

    return 0;
}
