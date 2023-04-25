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
	enQueue(&qe, 5); //5可以插入
	
	traverse_queue(&qe); 
	
	if(full_queue(&qe)){
		printf("\n 循环队列已满，长度为 4 \n"); 
	}
	else
		printf("\n 循环队列未满 \n"); 
	
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

// 判断是否为空
bool empty_queue(Q qe){
	if(qe->front == qe->rear &&  qe->is_full == false)
	 return true;
	else
	 return false;
	 }

// 判断是否为满 
bool full_queue(Q qe){
	if( (qe->is_full == true)) 
	 return true;
	else
	 return false;
	 }
	 
// 入队
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
// 出队
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
//循环队列遍历 
void traverse_queue(Q qe){
	if(empty_queue(qe)){
		printf("哥，循环队列中元素为空，无法为您输出！\n");
		return;
	}
	else{
			printf("\n 为您遍历队列元素! \n ");
			int cnt=1; 
			int i = qe->front;
			
			if( qe->is_full == true){
				printf("循环列表中元素已满，容量为5！\n");
				for(int j=0; j<5; j++){
					cnt++;
					printf("循环队列中第%d个元素的值为：%d \n ", cnt, qe->pBase[(i+j)%5]);	
				}
			} 
			else
				while( i != qe->rear){
					printf("循环队列中第%d个元素的值为：%d \n ", cnt, qe->pBase[i]);
					cnt++;
					i = (i+1)%5;
				}
	}	
	
}

