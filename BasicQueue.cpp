#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	node *next;
};
struct queue{
	node *front,*rear;
};
void Init(queue &q){
	q.front=NULL;
}
int Empty(queue q){
	return q.front==NULL?1:0;
}
void EnQueue(queue &q,int k){
	node *p=new node;
	if(p==NULL){
		printf("Loi bo nho");
		return;
	}
	p->data=k;
	p->next=NULL;
		if(Empty(q)){
			q.front=p;
			q.rear=p;
		}
		else{
			q.rear->next=p;
			q.rear=p;
		}
}
int DeQueue(queue &q){
	if(Empty(q)){
		printf("Queue rong\n");
		return 1;
		
	}
	
		node *p=q.front;
		q.front=p->next;
		if(Empty(q))
			q.rear=NULL;
		int a=p->data;
		p->next=NULL;
		delete p;
		return a;
	
}
int Front(queue q){
	if(!Empty(q)){
		return q.front->data;
	}
	return 1;
}
int main(){
	int k;
	queue q;
	printf("Nhap phan tu vao queue(-1 de ket thuc): ");
	do{
		scanf("%d",&k);
		if(k!=-1) EnQueue(q,k);
	}while(k!=-1);
printf("\nLay cac phan tu ra khoi queue:");
while(!Empty(q)){
	k=DeQueue(q);
	printf("%d ",k);
}}
