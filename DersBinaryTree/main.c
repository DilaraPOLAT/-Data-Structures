#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct Agac
{
    int eleman;
    struct Agac*sag,*sol;
}Agaclar;

Agaclar*DegerAl();
void ekle_rec(Agaclar*agackok,Agaclar*yeni);
void inlistele(Agaclar*agackok);
int say(Agaclar*agackok);
int full_binary_kontrol(Agaclar*agackok);
Agaclar*arama(Agaclar*agackok,int aranan);
Agaclar*enkucuk(Agaclar*agackok);
Agaclar*enbuyuk(Agaclar*agackok);
Agaclar*silme(Agaclar*agackok,int data);
int sayma;
Agaclar*kok=NULL;

Agaclar*DegerAl()
{
    Agaclar *yeni;
    yeni=(Agaclar*)malloc(sizeof(Agaclar));
    if(yeni==NULL)
    {
      puts("\nBellek yok");
      return NULL;
    }
    puts("\n Elemani Giriniz:");
    scanf("%d",&(yeni->eleman));
    yeni->sag=NULL;
    yeni->sol=NULL;
    return yeni;
}

int full_binary_kontrol(Agaclar*agackok)
{
    if(agackok==NULL)
        return 0;


}

void ekle_rec(Agaclar*agackok,Agaclar*yeni)
{
    if(agackok==NULL)
        kok=yeni;
    else
    {
        if(yeni->eleman < agackok->eleman)
        {
            if(agackok->sol==NULL)
                agackok->sol=yeni;
            else
                ekle_rec(agackok->sol,yeni);
        }
        else
        {
            if(agackok->sag==NULL)
                agackok->sag=yeni;
            else
                ekle_rec(agackok->sag,yeni);
        }
    }
}

void inlistele(Agaclar*agackok)
{
    if(agackok!=NULL)
    {
        printf("\n %d",agackok->eleman);//preoder
        inlistele(agackok->sol);
        inlistele(agackok->sag);
    }
}
Agaclar*arama(Agaclar*agackok,int aranan)
{
    if(agackok==NULL)
        return NULL;
    if(aranan < agackok->eleman)
        return arama(agackok->sol,aranan);
    else if(aranan > agackok->eleman)
        return arama(agackok->sag,aranan);
    else return agackok;
}

Agaclar*silme(Agaclar*agackok,int data)
{
    if(agackok==NULL)
      return agackok;
    if(data < agackok->eleman)
        agackok->sol=silme(agackok->sol,data);
    else if(data > agackok->eleman)
         agackok->sag=silme(agackok->sag,data);
    else
    {
        if(agackok->sol==NULL && agackok->sag==NULL)
        {
            free(agackok);
            agackok=NULL;
            return agackok;
        }
        else if(agackok->sol==NULL)
        {
            Agaclar*temp=agackok;
            agackok=agackok->sag;
            free(temp);
            return agackok;

        }
        else if(agackok->sag==NULL)
        {
            Agaclar*temp=agackok;
            agackok=agackok->sag;
            free(temp);
            return agackok;
        }
        else
        {
            Agaclar*temp=enkucuk(agackok->sag);
            agackok->eleman=temp->eleman;
            agackok->sag=silme(agackok->sag,temp->eleman);
        }
    }
    return agackok;
}

Agaclar*enbuyuk(Agaclar*agackok)
{
    if(agackok->sag==NULL)
        return agackok;
    return enbuyuk(agackok->sag);
}


Agaclar*enkucuk(Agaclar*agackok)
{
    if(agackok->sol==NULL)
        return agackok;
    return enkucuk(agackok->sol);
}
int say(Agaclar*agackok)
{
    if(agackok==NULL)
        return 0;
    else
    {
        return say(agackok->sol)+say(agackok->sag)+1;

    }
    {
      return say(agackok->sol)+say(agackok->sag)+1;
    }
}
int main()
{
    Agaclar*yeni,*bul,*ekucuk,*ebuyuk;
    int aranan,sil,sayma_sonuc,binary_sonuc;
    char secim;
    while(1)
    {
        system("cls");
        puts("\n1-Ekleme\n2-Inorder Listele\n3-Arama\n4-Silme\n5-Enkucuk\n6-Enbuyuk\n7-Say\n8-Binarytree");
        secim=getch();
        switch(secim)
        {
        case '1':
            yeni=DegerAl();
            ekle_rec(kok,yeni);
            break;
        case '2':
            if(kok!=NULL)
                inlistele(kok);
            else
                puts("Bos agac");
            getch();
            break;
        case '3':
            scanf("%d",&aranan);
            bul=arama(kok,aranan);
            if(bul!=NULL)
                printf("Bulunan eleman:%d",bul->eleman);
            else
                printf("Eleman bulunamadi");
            getch();
            break;
        case '4':
            printf("\nSilinecek eleman");
            scanf("%d",&sil);
            kok=silme(kok,sil);
            break;
        case '5':
            if(kok!=NULL)
            {
                ekucuk=enkucuk(kok);
                printf("\nAgacin en kucuk elemani=%d",ekucuk->eleman);

            }
        case'6':
             if(kok!=NULL)
            {
                ebuyuk=enbuyuk(kok);
                printf("\nAgacin en buyuk elemani=%d",ekucuk->eleman);

            }
        case'7':
            printf("Eleman Sayisi:%d",say(kok));


        case'8':


    }
    return 0;











}
