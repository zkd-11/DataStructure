#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Queue{
	int front, rear;
	int *pBase;
}QUEUE,*Q;

void init(Q qe);
bool empty_queue(Q qe);
bool full_queue(Q qe);
bool enQueue(Q qe, int val);
bool deQueue(Q qe, int *val);
void traverse_queue(Q qe);
 

int main(){
	int val;
	QUEUE qe ;
	init(&qe);
	enQueue(&qe, 1);
	enQueue(&qe, 2);
	enQueue(&qe, 3);
	enQueue(&qe, 4);
	enQueue(&qe, 5); //5���벻�� 
	
	traverse_queue(&qe); 
	
	if(full_queue(&qe)){
		printf("\n ѭ����������������Ϊ 4 \n"); 
	}
	else
		printf("\n ѭ������δ�� \n"); 
	
	deQueue(&qe, &val);
	traverse_queue(&qe); 

} 

void init(Q qe){
	qe->front = 0;
	qe->rear = 0;
	qe->pBase = (int*)malloc(sizeof(int)* 5); 
}

// �ж��Ƿ�Ϊ��
bool empty_queue(Q qe){
	if(qe->front == qe->rear)
	 return true;
	else
	 return false;
	 }

// �ж��Ƿ�Ϊ�� 
bool full_queue(Q qe){
	if( (qe->rear+1)%5 == qe->front)
	 return true;
	else
	 return false;
	 }
	 
// ���
bool enQueue(Q qe, int val){
	if(full_queue(qe))
		return false;
	else{
			qe->pBase[qe->rear] = val;
			qe->rear = (qe->rear+1)%5;
			return true;
	}
}
// ����
bool deQueue(Q qe, int *val){
	
	if(empty_queue(qe))
		return false;
	else{
			*val = qe->pBase[qe->front];
			qe->front = (qe->front+1)%5;
			return true;
	}	

} 
//ѭ�����б��� 
void traverse_queue(Q qe){
	if(empty_queue(qe)){
		printf("�磬ѭ��������Ԫ��Ϊ�գ��޷�Ϊ�������\n");
		return;
	}
	else{
			printf("\n Ϊ����������Ԫ��! \n ");
			int cnt=1; 
			int i = qe->front;
			while( i != qe->rear){
				printf("ѭ�������е�%d��Ԫ�ص�ֵΪ��%d \n ", cnt, qe->pBase[i]);
				cnt++;
				i = (i+1)%5;
			}
	}	
	
}

