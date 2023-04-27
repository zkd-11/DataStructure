#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>


struct BTNode{
	char data;
	struct BTNode * pLchild; 
	struct BTNode * pRchild; 
};

struct BTNode * CreateBTree();
void PreTraverseBTree(struct BTNode * pT);
void InTraverseBTree(struct BTNode * pT);
void PostTraverseBTree(struct BTNode * pT);
 
int main(){
	struct BTNode * pT = CreateBTree();
	PreTraverseBTree(pT);
	InTraverseBTree(pT);
	PostTraverseBTree(pT);	
	return 0;
}

 
//��̬����һ���� 
struct BTNode * CreateBTree(){
	struct BTNode * A = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * B = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * C = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * D = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * E = (struct BTNode *)malloc(sizeof(struct BTNode));
	
	A->data = 'A';	
	B->data = 'B';	
	C->data = 'C';	
	D->data = 'D';	
	E->data = 'E';	
	
	A->pLchild = B;
	A->pRchild = C;	 
	B->pLchild = NULL;
	B->pRchild = NULL;	 
	
	C->pLchild = D;
	C->pRchild = NULL;	
	D->pLchild = NULL;
	D->pRchild = E;	

	
	E->pLchild = NULL;
	E->pRchild = NULL;	

	return A;
	
} 

void PreTraverseBTree(struct BTNode * pT){

//	 ��ֹ������ �ݹ���Ҷ�ӽڵ�ʱ 
	if(NULL != pT){
		if(pT->data == 'A') printf("�������������Ϊ�� \n"); 
		printf("%c \t", pT->data);
		
		if(NULL != pT->pLchild){
			PreTraverseBTree(pT->pLchild);	
		}
		if(NULL != pT->pRchild){
			PreTraverseBTree(pT->pRchild);	
		}
		return;
	}
} 

//������� 
void InTraverseBTree(struct BTNode * pT){
	if(pT->data == 'A') printf("\n \n�������������Ϊ�� \n"); 
//	 ��ֹ������ �ݹ���Ҷ�ӽڵ�ʱ 
	if(NULL != pT){
//		������������� 
			if(NULL != pT->pLchild){
				InTraverseBTree(pT->pLchild);	
			}
		printf("%c \t", pT->data);
// 		������������� 
			if(NULL != pT->pRchild){
			InTraverseBTree(pT->pRchild);	
			}
		return;
	}
} 

//������� 
void PostTraverseBTree(struct BTNode * pT){

//	 ��ֹ������ �ݹ���Ҷ�ӽڵ�ʱ 
	if(NULL != pT){
	if(pT->data == 'A') printf("\n \n�����ĺ������Ϊ�� \n");
		if(NULL != pT->pLchild){
			PostTraverseBTree(pT->pLchild);	
		}
		
		if(NULL != pT->pRchild){
			PostTraverseBTree(pT->pRchild);	
		}
		printf("%c \t", pT->data);
			
		return;
} 
}


