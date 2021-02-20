#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Liste
{
    int numara;
    struct Liste *sonraki;

}BListe;

BListe *ilk=NULL,*gecici;

BListe *Bilgi_Al(int num)
{
    BListe *Bilgi=(BListe*)malloc(sizeof(BListe));
    Bilgi->numara=num;
    return Bilgi;

}

int SiraliEkle(BListe *bilgi)
{
    if(ilk==NULL)
    {
        ilk=bilgi;
        ilk->sonraki=NULL;
        return 0;
    }

    if(ilk->numara>bilgi->numara)
    {
        bilgi->sonraki=ilk;
        ilk=bilgi;
        return 0;
    }
    gecici=ilk;
    while(gecici->sonraki!=NULL && gecici->sonraki->numara < bilgi->numara)
        gecici=gecici->sonraki;
    bilgi->sonraki=gecici->sonraki;
    gecici->sonraki=bilgi;

}

void Ekle(BListe *bilgi)
{
    if(ilk==NULL)
    {
        ilk=bilgi;
        ilk->sonraki=NULL;
    }
    else
    {
     gecici=ilk;
     while(gecici->sonraki!=NULL)
        gecici=gecici->sonraki;
     gecici->sonraki=bilgi;
     bilgi->sonraki=NULL;

    }
}

void Silme(int silnum)
{
    BListe *bironceki;
    gecici=ilk;
    bironceki=NULL;
    while(gecici)
    {
        if(gecici->numara==silnum)
            break;
        bironceki=gecici;
        gecici=gecici->sonraki;
    }
    if(gecici!=NULL)
    {
        if(bironceki==NULL)
        {
            if(ilk->sonraki==NULL)
            {
                ilk=NULL;
            }
            else
            {
              ilk=ilk->sonraki;
            }
        }
        else
        {
            bironceki->sonraki=gecici->sonraki;
        }
        free(gecici);
        printf("Kayit silindi.");
    }
    else
        printf("Kayit silinemedi.");
}

BListe *Ara(int num)
{
    gecici=ilk;
    while(gecici)
    {
        if(gecici->numara==num)
          return gecici;
        gecici=gecici->sonraki;
    }
    return gecici;
}

int Listele()
{
    gecici=ilk;
    if(gecici==NULL)
        return 0;
    while(gecici)
    {
        printf("%d->",gecici->numara);
        gecici=gecici->sonraki;

    }
    return 1;

}

int Listelerec(BListe *siradaki)
{
    if(siradaki==NULL)
        return 0;
    printf("%d",siradaki->numara);
    Listelerec(siradaki->numara);

}


void main()
{
    BListe *Bilgi,*bul;
    char secim;
    int numara;
    while(1==1)
    {
        system("cls");
        puts("Ekle(e)\nListele(l)\nAra(a)\nSil(s)\nSiraliEkle(t)\nCikis(c)\nSecim?");
        secim=getchar();
        switch(secim)
        {
        case 'e':
            puts("Numarayi giriniz:");
            scanf("%d",&numara);
            Bilgi=Bilgi_Al(numara);
            Ekle(Bilgi);
            break;

        case 't':
            puts("Numarayi giriniz:");
            scanf("%d",&numara);
            Bilgi=Bilgi_Al(numara);
            SiraliEkle(Bilgi);
            break;
        case 'a':
            puts("Aranacak numarayi giriniz:");
            scanf("%d",&numara);
            bul=Ara(numara);
            if(bul!=NULL)
                printf("\nKayit bulundu");
            else
                printf("\nKayit  bulunamadi");
            getch();
            break;

        case 'l':
            Listele(ilk);
            getch();
            break;

        case 's':
            puts("Silinecek numarayi giriniz:");
            scanf("%d",&numara);
            Silme(numara);
            getch();
            break;

        case 'c':
            exit(0);


        }
    }

}
