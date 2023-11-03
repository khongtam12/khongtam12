#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct mathang{
	int mamh;
	char tenmh[12];
};
struct node{
	mathang data;
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
void EnQueueMH(queue &q,mathang mhm){
	node *p=new node;
	if(p==NULL) {
		printf("Loi bo nho");
		return;
	}
	p->data=mhm;
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
void DeQueueMH(queue &q){
	if(!Empty(q)){
		node *p=q.front;
		q.front=p->next;
		mathang b=p->data;
		if(Empty(q))
			q.rear=NULL;
		delete p;
		printf("ma mat hang:%d\nten mat hang:%s\n",b.mamh,b.tenmh);
		
	}
}
void FrontMH(queue q){
	mathang b=q.front->data;
	printf("ma mat hang:%d\nten mat hang:%s\n",b.mamh,b.tenmh);
}
void RearMH(queue q){
	mathang b=q.rear->data;
	printf("ma mat hang:%d\nten mat hang%s\n",b.mamh,b.tenmh);
}
void XemDS(queue q){
	node *p=q.front;
	while(p){
		mathang b=p->data;
	printf("ma mat hang:%d\nten mat hang:%s\n",b.mamh,b.tenmh);
	p=p->next;
	}
}
void DequeueDSMH(queue &q){
	while(!Empty(q)){
		DeQueueMH(q);
	}
}
void EnqueueDS(queue &q){
	int n;
	printf("Nhap so luong MH: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		mathang mhm;
		printf("\nNhap mat hang %d: ",i);
		printf("\nNhap ma mat hang:");
		scanf("%d",&mhm.mamh);
		printf("Nhap ten mat hang: ");fflush(stdin);
		gets(mhm.tenmh);
		EnQueueMH(q,mhm);
}
printf("\nHoan tat nhap DS!");
}
int main(){
	int chon;
	queue q;
	Init(q);
	do{
		printf("\n\n\t\t\tCHUONG TRINH QUAN LY KHO");
 		printf("\n\t\t\t(NHAP TRUOC - XUAT TRUOC)");
		 printf("\n\nCac chuc nang cua chuong trinh:\n");
		 printf("1: Nhap mot mat hang\n");
		 printf("2.Nhap danh sach cac mat hang\n");
 		printf("3: Xuat mot mat hang\n");
		printf("4: Xem mat hang chuan bi xuat\n");
		printf("5: Xem mat hang moi nhap\n");
 		printf("6: Xem cac mat hang co trong kho\n");
 		printf("7: Xuat toan bo kho hang\n");
 		printf("0: Ket thuc chuong trinh\n");
		 printf("Chuc nang ban chon: ");
 		scanf("%d", &chon);
	switch(chon){
		case 1:{
			mathang mhm;
//		printf("\nNhap mat hang %d: ",i);
		printf("\nNhap ma mat hang:");
		scanf("%d",&mhm.mamh);
		printf("Nhap ten mat hang: ");fflush(stdin);
		gets(mhm.tenmh);
		EnQueueMH(q,mhm);
			break;
		}
		case 2:{
			EnqueueDS(q);
			break;
		}
		case 3:{
			DeQueueMH(q);
			break;
		}
		case 4:{
			FrontMH(q);
			break;
		}
		case 5:{
			RearMH(q);
			break;
		}
		case 6: {
			XemDS(q);
			break;
		}
		case 7:{
			DequeueDSMH(q);
			break;
		}
	}
	}while(chon!=0);
}
