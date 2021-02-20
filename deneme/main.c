#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DILARA SEVIM POLAT 19010011064
typedef struct n
{
    char data;
    struct n *next;

} node;

node*yigin=NULL;
char posfix[20];
int syc=0;



node*yigin_ekle(node*yigin,char infix)
{
    if(yigin==NULL)
    {
        yigin=(node*)malloc(sizeof(node));
        yigin->data=infix;
        yigin->next=NULL;
        return yigin;
    }

    node*iter=yigin;
    if(infix==')')//Eger kaoa parantez geldiginde acparantezi gorene kadar posfixe ekle ve yigindan sil
    {
        while(iter->data!='(')
        {
            posfix_ekle(iter->data);
            iter=iter->next;
        }
        yigin=iter->next;
        free(iter);
        return yigin;
    }
    else if(infix!='('){
    if(infix=='+'&&yigin->data=='*'||infix=='-'&&yigin->data=='*'||infix=='+'&&yigin->data=='/'||infix=='-'&&yigin->data=='/'
       ||infix==yigin->data||infix=='-'&&yigin->data=='+'||infix=='+'&&yigin->data=='-'||infix=='*'&&yigin->data=='/'||infix=='/'&&yigin->data=='*')
    {
        while(iter!=NULL)
        {
            posfix_ekle(iter->data);
            iter=iter->next;
        }

        free(iter);
        free(yigin);
        node*temp;
        temp=(node*)malloc(sizeof(node));
        temp->data=infix;
        temp->next=NULL;
        return temp;
    }
    }
    node*temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=infix;
    temp->next=yigin;
    return temp;

}

void listele(node*yigin)
{

    node*iter=yigin;

    while (iter!=NULL)
    {
        printf("%c",iter->data);
        iter=iter->next;
    }
    printf("\t\t\t\t\t");
}

void posfix_ekle(char infix)
{

    posfix[syc]=infix;
    syc++;

}

void posfix_Listele()
{
    for(int j=0; j<syc; j++)
    {
        printf("%c",posfix[j]);
    }
    printf("\t\t\t\t\t");
}

node*Yigindan_sil(node*yigin)
{
    node*iter=yigin;
    while(iter!=NULL)
    {
        posfix_ekle(iter->data);
        iter=iter->next;
    }
    free(iter);
    yigin=NULL;
    return yigin;
}
int main()
{

    char infix[20];

    printf("Infix ifade giriniz:");
    scanf("%s",infix);
    int i,k;
    printf("\nINFIX\t\t\t\t\tYIGIN\t\t\t\t\tPOSFIX");
    printf("\n%s\t\t\t\t\t",infix);
    listele(yigin);
    posfix_Listele();

    for(i=0; i<20; i++)
    {
        if(infix[i]==NULL)
        {
            int sayac=0;
            if(yigin==NULL)
            {
                break;
            }
            yigin=Yigindan_sil(yigin);//eger infix ifadenin elemaný kalmadýysa yiginda eleman varsa
                                      //elemanlari ilk once posfixe ekle sonrada yigin icindeki elemanlarýn hepsini sil
            printf("\n");
            for( k=i; k<20; k++)//infix ifadeyi yazdýrmak icin
            {
                sayac++;
                if(infix[k]==NULL)
                {
                    if(sayac>8)//Duzenli gozukmesi icin yaptim
                    {   printf("\t\t\t\t");
                        break;
                    }
                    printf("\t\t\t\t\t");
                        break;

                }

                printf("%c",infix[k]);
            }
            listele(yigin);
            posfix_Listele();
            break;
        }

        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='('||infix[i]==')')
        {
            int sayac=0;
            yigin=yigin_ekle(yigin,infix[i]);
            printf("\n");
            for( k=i; k<20; k++)
            {
                sayac++;
                if(infix[k+1]==NULL)
                {
                    if(sayac>8)
                    {   printf("\t\t\t\t");
                        break;
                    }
                    printf("\t\t\t\t\t");
                        break;
                }

                printf("%c",infix[k+1]);
            }
            listele(yigin);
            posfix_Listele();


        }
        else
        {
            int sayac=0;
            posfix_ekle(infix[i]);
            printf("\n");
            for( k=i; k<20; k++)
            {
                sayac++;
                if(infix[k+1]==NULL)
                {
                    if(sayac>8)
                    {   printf("\t\t\t\t");
                        break;
                    }
                    printf("\t\t\t\t\t");
                        break;
                }

                printf("%c",infix[k+1]);
            }
            listele(yigin);
            posfix_Listele();

        }
    }

    return 0;
}


