#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *pNext;
} NODE, *PNODE;


//������һ��ջ
typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
} STACK, *PSTACK;

void init(PSTACK pS);
void push(PSTACK pS, int val);
void traverse(PSTACK pS);
bool is_empty(PSTACK pS);
bool pop(PSTACK pS, int *val);
void clear(PSTACK pS);


int main() {
	int val;
	STACK S;
	init(&S);
	push(&S, 5);
	push(&S, 3);
	push(&S, 1);
	traverse(&S);
	
	if(pop(&S, &val)){
		printf("\n ��ջ�ɹ��� Ԫ������Ϊ: %d \n", val);
	}else{
		printf("ջ����Ԫ�أ���ջʧ�ܣ�");
	}

	 clear(&S);
	traverse(&S);

}
//��ջ�ĳ�ʼ��
void init(PSTACK pS) {
	pS->pBottom = (PNODE)malloc(sizeof(NODE));
	if(pS->pBottom == NULL) {
		printf("����ʧ�ܣ� ������ֹ��\n");
		exit(-1);
	} else {
		pS->pTop = pS->pBottom;
		pS->pBottom->pNext = NULL;
	}
}
//Ԫ�� ��ջ 
void push(PSTACK pS, int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}
//���� ջ��Ԫ������ 
void traverse(PSTACK pS){
	if(is_empty(pS)){
		printf("\n ջΪ�գ��޷�Ϊ������ջ��Ԫ�����ݣ�\n");
		exit(-1);
	}else{
			PNODE p = pS->pTop;
			while(p != pS->pBottom){
				printf("%d \t", p->data);
				p = p->pNext;				
		} 
   }
}
//�ж�ջ�Ƿ�Ϊ��
bool is_empty(PSTACK pS){
	if(pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}
//Ԫ�س�ջ -�ͷ���Դ 
bool pop(PSTACK pS, int *val) {
	if(is_empty(pS)){
		return false;
	}else{	
			PNODE p = pS->pTop;
			*val = p->data;
			pS->pTop = p->pNext;		
			free(p);
			p = NULL; 		
}
}

//���ջ��Ԫ��
void clear(PSTACK pS){
		if(is_empty(pS)){
		printf("ջ����Ԫ�أ����Ԫ��ʧ�ܣ�");
		return ;
	}else{
		PNODE p = pS->pTop;
		while(p != pS->pBottom){
				p = pS->pTop->pNext;
				free(pS->pTop);
				pS->pTop = p; 
		}
			if(p == pS->pBottom)
			p == NULL;
		return;
	} 
}


