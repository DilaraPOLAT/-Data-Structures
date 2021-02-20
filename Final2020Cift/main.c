#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef struct n {
	int data;
	struct n * next;
	struct n * prev;

}node;

// 2
void bastir(node *r){

	while(r!=NULL)
		{
			printf("%d ",r->data);
			r = r->next;
		}
}

node * ekle(node * r,int a){
	if(r==NULL){
		node *temp = (node*)malloc(sizeof(node));
		temp->prev=0;
		temp->next=NULL;
		temp->data=a;
		return temp;
	}

	node*iter=r;
	while(iter->next != NULL)
		iter = iter->next;
	iter->next = (node*)malloc(sizeof(node));
	iter->next->data = a;
	iter->next->prev = iter;
	iter->next->next = NULL;
	return r;
}


//a
node * ilksil(node *r){
	free(r->prev);
	r->data=NULL;
	return r->next;
}



//b
node * araekle(node *r,int m){
	while(r->next != NULL){
		if(r->data == m){
			r=ekle(r,m);
			return r;}
		r=r->next;
	}

	// fonksiyonu int main'de   araekle(root,2) olarak giriyoruz.  ( 2= m deðiskeni. farklý degerler girilebilir)
}


//c
node * swap (node *r,int m){
	node * iter = r;
	while(iter->next != NULL){

		if(iter->data == m){
			node*temp=r;
			node *temp2=iter->next;

			r=iter;
			r->next=temp->next;
			r->prev->next=temp;
			temp->next=temp2;
			return iter;
		}
		iter = iter->next;
	}
}


int main(){
	node * root = NULL;
	for(int i=0;i<10;i++)
		root=ekle(root,i);

	//root=ilksil(root);
	araekle(root,4);
	bastir(root);
	printf("\n");
	root=swap(root,5);

	bastir(root);




}









