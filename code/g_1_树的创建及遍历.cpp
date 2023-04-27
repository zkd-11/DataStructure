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

 
//静态创建一棵树 
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

//	 终止条件： 递归至叶子节点时 
	if(NULL != pT){
		if(pT->data == 'A') printf("该树的先序遍历为： \n"); 
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

//中序遍历 
void InTraverseBTree(struct BTNode * pT){
	if(pT->data == 'A') printf("\n \n该树的中序遍历为： \n"); 
//	 终止条件： 递归至叶子节点时 
	if(NULL != pT){
//		左子树中序遍历 
			if(NULL != pT->pLchild){
				InTraverseBTree(pT->pLchild);	
			}
		printf("%c \t", pT->data);
// 		右子树中序遍历 
			if(NULL != pT->pRchild){
			InTraverseBTree(pT->pRchild);	
			}
		return;
	}
} 

//后序遍历 
void PostTraverseBTree(struct BTNode * pT){

//	 终止条件： 递归至叶子节点时 
	if(NULL != pT){
	if(pT->data == 'A') printf("\n \n该树的后序遍历为： \n");
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


