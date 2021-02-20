#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROW 16
#define NAME_LENGTH 20

typedef struct _Row
{
    int index;
    char name[NAME_LENGTH];
    struct _Row*pNext;
}Row;

typedef struct _Table
{
    Row rows[MAX_ROW];
}Table;

Table table;

void intialize_Table();
int RSHash(char*str,int len);
void add_Row(char *str);
void collision(Row *row,Row *startRow);
int find_row(char *str);
void display_Table();

int RSHash(char *str,int len)
{
    int b =378553;
    int a =63689;
    int hash =0;
    int i =0;

    for(i=0;i<len;str++,i++)
    {
        hash=hash*a+(*str);
        a=a*b;
    }
    return (hash & 0x7FFFFFFF) %MAX_ROW;
}


void intialize_Table()
{
    int i;
    for(i=0;i<MAX_ROW;++i)
    {
        table.rows[i].index=-1;
        sprintf(table.rows[i].name,"%s","$$BOS$$");
        table.rows[i].pNext=NULL;
    }
}

void add_Row(char *str)
{
    int hash_index;
    Row *row;
    hash_index=RSHash(str,strlen(str));
    printf("%d",hash_index);

    if(table.rows[hash_index].index==-1 ||
       (strcmp(table.rows[hash_index].name,str)==0))
    {
        table.rows[hash_index].index=hash_index;
        sprintf(table.rows[hash_index].name,"%s",str);
        return ;
    }

    row=(Row*)malloc(sizeof(Row));
    if(!row)
    {
        puts("yeterli bellek yok");
        exit(0);
    }
    row->index=hash_index;
    sprintf(row->name,"%s",str);
    collision(row,&table.rows[hash_index]);
}

void collision(Row*row,Row*startRow)
{
    Row*old;
    old=startRow;
    while(startRow)
    {
        old=startRow;
        startRow=startRow->pNext;
    }
    old->pNext=row;
    row->pNext=NULL;
}

int find_row(char*str)
{
    int hash_index;
    Row*row;

    hash_index = RSHash(str,strlen(str));

    if(strcmp(table.rows[hash_index].name,str)==0)
        return table.rows[hash_index].index;
    else
    {
        row=table.rows[hash_index].pNext;
        while(row)
        {
            if(!strcmp(row->name,str))
                return row->index;
            row = row->pNext;
        }
    }
    return -1;
}

 void display_Table()
 {
     int i;
     Row*row;
     puts("\n***Tablo***");
     for(i=0;i<MAX_ROW;++i)
     {
         if(table.rows[i].pNext ==NULL)
            printf("%2d:%s\n",table.rows[i].index,table.rows[i].name);
         else
         {
             printf("%2d: %s",table.rows[i].index,table.rows[i].name);
             row=table.rows[i].pNext;
             while(row)
             {
                 printf("%2d :%s",row->index,row->name);
                 row=row->pNext;
             }
             puts(" ");
         }
     }
 }

int main()
{
    int i,index;
    char aranan[30];
    char*names[MAX_ROW]={"armagan","basin","cebir","diyet","erkek","filiz","gram","hastane","insanlik",
    "joker","kale","lizbon","makina","number","orta","pilav"};
    intialize_Table();
    for(i=0;i<MAX_ROW;++i)
    {
        add_Row(names[i]);
        printf(": %s\n",names[i]);
    }
    display_Table();
    printf("\nArama yapilacak kelimeyi giriniz:");
    scanf("%s",&aranan);
    index=find_row(aranan);
    printf("%s index :%d",aranan,index);
    // display_Table();
    return 0;















}
