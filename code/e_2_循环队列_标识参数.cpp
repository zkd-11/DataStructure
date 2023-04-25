#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Queue{
	int front, rear;
	int *pBase;
	bool is_full;
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
	enQueue(&qe, 5); //5���Բ���
	
	traverse_queue(&qe); 
	
	if(full_queue(&qe)){
		printf("\n ѭ����������������Ϊ 4 \n"); 
	}
	else
		printf("\n ѭ������δ�� \n"); 
	
	deQueue(&qe, &val);
	printf("%d",val); 
	
	traverse_queue(&qe); 

} 

void init(Q qe){
	qe->front = 0;
	qe->rear = 0;
	qe->pBase = (int*)malloc(sizeof(int)* 5); 
	 qe->is_full = false;
}

// �ж��Ƿ�Ϊ��
bool empty_queue(Q qe){
	if(qe->front == qe->rear &&  qe->is_full == false)
	 return true;
	else
	 return false;
	 }

// �ж��Ƿ�Ϊ�� 
bool full_queue(Q qe){
	if( (qe->is_full == true)) 
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
			
		if(qe->rear == qe->front )
		qe->is_full = true; 
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
		 qe->is_full = false;

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
			
			if( qe->is_full == true){
				printf("ѭ���б���Ԫ������������Ϊ5��\n");
				for(int j=0; j<5; j++){
					cnt++;
					printf("ѭ�������е�%d��Ԫ�ص�ֵΪ��%d \n ", cnt, qe->pBase[(i+j)%5]);	
				}
			} 
			else
				while( i != qe->rear){
					printf("ѭ�������е�%d��Ԫ�ص�ֵΪ��%d \n ", cnt, qe->pBase[i]);
					cnt++;
					i = (i+1)%5;
				}
	}	
	
}

