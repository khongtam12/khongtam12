#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	node *pLeft,*pRight;
	int data;
};
typedef node *Tree;

node *TaoNode(int x){
	node *p=new node;
	if(p==NULL) return NULL;
		p->pLeft=NULL;
		p->pRight=NULL;
		p->data=x;
		return p;
}
void ThemNodeVaoCay(node *p,Tree &c){
	if(c==NULL) 
		c=p;
	else {
		if(p->data<c->data)
			ThemNodeVaoCay(p,c->pLeft);
		else if(p->data>c->data)
			ThemNodeVaoCay(p,c->pRight);
		return;	
	}
}
void Nhap(Tree &c){
	int chon=0;
	do{
		int x;
		printf("\nNhap x:");
		scanf("%d",&x);
		node *p=TaoNode(x);
		ThemNodeVaoCay(p,c);
		printf("Muon nhao thong tin lien tiep ko?1: co,o: ko~~>");
		scanf("%d",&chon);
		
		
	}while(chon);
}
void Xuat(Tree c){
	if(c!=NULL){
		if(c->pLeft!=NULL) 
			Xuat(c->pLeft);
		printf("%4d",c->data);
		if(c->pRight!=NULL)
			Xuat(c->pRight);
	}
}
int main(){
	Tree c=NULL;
	Nhap(c);
	printf("Xuat cay LNR(Tang dan): ");
	Xuat(c);
	return 0;
}
