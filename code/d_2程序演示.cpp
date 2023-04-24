#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *pNext;
} NODE, *PNODE;


//定义了一个栈
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
		printf("\n 出栈成功， 元素数据为: %d \n", val);
	}else{
		printf("栈内无元素，出栈失败！");
	}

	 clear(&S);
	traverse(&S);

}
//对栈的初始化
void init(PSTACK pS) {
	pS->pBottom = (PNODE)malloc(sizeof(NODE));
	if(pS->pBottom == NULL) {
		printf("分配失败， 程序终止！\n");
		exit(-1);
	} else {
		pS->pTop = pS->pBottom;
		pS->pBottom->pNext = NULL;
	}
}
//元素 入栈 
void push(PSTACK pS, int val){
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;
}
//遍历 栈内元素数据 
void traverse(PSTACK pS){
	if(is_empty(pS)){
		printf("\n 栈为空，无法为您遍历栈内元素数据！\n");
		exit(-1);
	}else{
			PNODE p = pS->pTop;
			while(p != pS->pBottom){
				printf("%d \t", p->data);
				p = p->pNext;				
		} 
   }
}
//判断栈是否为空
bool is_empty(PSTACK pS){
	if(pS->pTop == pS->pBottom)
		return true;
	else
		return false;
}
//元素出栈 -释放资源 
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

//清空栈内元素
void clear(PSTACK pS){
		if(is_empty(pS)){
		printf("栈内无元素，清空元素失败！");
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


