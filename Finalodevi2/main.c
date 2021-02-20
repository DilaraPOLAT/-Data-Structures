#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n
{
    char data;
    struct n *next;

} node;


char posfix[20];
int syc=0;
node*Yigindan_sil(node*yigin);



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
    if(infix==')')
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
    else if(infix=='(')
    {
        node*temp;
        temp=(node*)malloc(sizeof(node));
        temp->data=infix;
        temp->next=yigin;
        return temp;
    }
    else if(infix=='*'&&yigin->data=='+'||infix=='*'&&yigin->data=='-'||infix=='/'&&yigin->data=='+'||infix=='/'&&yigin->data=='-'||infix!=')'&&yigin->data=='(')
    {
        node*temp;
        temp=(node*)malloc(sizeof(node));
        temp->data=infix;
        temp->next=yigin;
        return temp;
    }

    else
    {
        while(iter!=NULL)
        {
            posfix_ekle(iter->data);
            iter=iter->next;
            yigin=Yigindan_sil(yigin);
        }
        yigin=(node*)malloc(sizeof(node));
        yigin->data=infix;
        yigin->next=NULL;
        return yigin;

    }
}

void listele(node*yigin)
{

    node*iter=yigin;

    while (iter!=NULL)
    {
        printf("%c",iter->data);
        iter=iter->next;
    }
    printf("\t\t\t");
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
    printf("\t\t\t");
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
    node*yigin = NULL;
    char infix[20];

    printf("infix ifade giriniz:");
    scanf("%s",infix);
    int i,k;
    printf("\nINFIX\t\t\tYIGIN\t\t\tPOSFIX");
    printf("\n%s\t\t\t",infix);
    listele(yigin);
    posfix_Listele();

    for(i=0; i<20; i++)
    {
        if(infix[i]==NULL)
        {
            if(yigin==NULL)
            {
                break;
            }
            yigin=Yigindan_sil(yigin);
            printf("\n");
            for( k=i; k<20; k++)
            {
                if(infix[k]==NULL)
                {
                    printf("\t\t\t");
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
            yigin=yigin_ekle(yigin,infix[i]);
            printf("\n");
            for( k=i; k<20; k++)
            {
                if(infix[k+1]==NULL)
                {
                    printf("\t\t\t");
                    break;
                }

                printf("%c",infix[k+1]);
            }
            listele(yigin);
            posfix_Listele();


        }
        else
        {
            posfix_ekle(infix[i]);
            printf("\n");
            for( k=i; k<20; k++)
            {
                if(infix[k+1]==NULL)
                {
                    printf("\t\t\t");
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









































