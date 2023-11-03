
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	char data;
	node *next;
};
struct stack{
	node *top;
};
void Init(stack &s){
	s.top=NULL;
}
int Empty(stack s){
	return s.top==NULL?1:0;
}

void Push(stack &s, char k){
	node *p=new node;
	if(p==NULL) {
		printf("loi bo nho");
		return;
	}
	p->data=k;
	p->next=NULL;
	if(s.top==NULL)
	s.top=p;
	else {
		p->next=s.top;
		s.top=p;
	}
}
void Pop(stack &s ){
	if(!Empty(s)){
		node *p=s.top;
		char a;

		a=p->data;
		s.top=p->next;
		p->next=NULL;
		delete p;
		printf("%c",a);		
	}
}

int main(){
	stack s;
	Init(s);
	char tam;
char chuoi[20];
	printf("Nhap chuoi can ma hoa: ");fflush(stdin);
	gets(chuoi);
//		Push(s,chuoi[0]);
		int dem=1;
	for(int i=strlen(chuoi)-1;i>=0;i--){	
		char kt=chuoi[i];
		if(kt==chuoi[i-1])dem++;	
		else {	
//			char dem1=(char)dem;
			Push(s,dem+'0');
			Push(s,kt);
			dem=1;
		}
	}
	printf("Chuoi da ma hoa : ");
	while(!Empty(s)){
			Pop(s);

	}
}
