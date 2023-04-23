#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node * pNext; //指针域， 指向一个与自己同数据类型的的结构体
//	指向下一个节点 
} Node, *PNODE; // 结构体类型 Node, 结构体指针 PNODE

//函数声明 
PNODE create_List(); 
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
void sort_list(PNODE pHead);
bool insert_list(PNODE pHead, int pos, int val);
bool delete_list(PNODE pHead, int pos, int * p);

int main(){
	
	int val;
	PNODE pHead = NULL;
	pHead = create_List();
	traverse_list(pHead);
	
	if(!is_empty(pHead))
		printf("\n \n 链表节点长度为：%d \n", length_list(pHead));
	sort_list(pHead);
	traverse_list(pHead);
	
	insert_list(pHead, 1, 33);
	traverse_list(pHead);
	
	if(delete_list(pHead,1,&val)){
		printf("\n 删除成功- 删除的元素为： %d \n", val);
	}else printf("\n 删除失败！\n ");
	traverse_list(pHead);	
		
	return 0;
} 

PNODE create_List(){
	PNODE pHead = (PNODE) malloc(sizeof(Node));
	pHead->pNext = NULL; 
	
	PNODE pTail = pHead;
	int len, val;
	
	printf("请输入要构造链表的节点个数：len = ");
	scanf("%d", &len);
	
	 
	for(int i=0; i<len; i++){
		printf(" \n 请输入第%d节点的值: ", i+1);
		scanf("%d", &val);
		
		PNODE pNew = (PNODE)malloc(sizeof(Node));
		if(NULL == pNew){
			printf("分配失败，程序终止! \n");
			exit(-1);
		}
		pTail->pNext = pNew;
		pNew->data = val;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
//遍历链表 
void traverse_list(PNODE pHead){
	printf("\n 赵哥，为您遍历链表内元素！ \n"); 
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("%d \t ",p->data);
		p = p->pNext;
	}
	return;
}

//链表是否为空 
bool is_empty(PNODE pHead){
	if(pHead->pNext!= NULL)
		return false;
	else
		return true;
} 
//链表长度 
int length_list(PNODE pHead){
	PNODE p = pHead->pNext;
	int len = 0;
	while(p != NULL){
		len++;
		p = p->pNext;
	}
	return len;
} 
//链表节点数据排序 
void sort_list(PNODE pHead){
	int i, j, t, len;
	len = length_list(pHead);
	PNODE p, q; 
//	for(i=0, p=pHead->pNext; i<len-1; i++, p=p->pNext)
//// 此行判断原写为： 选择排序 
//// j<len-1, 导致j最终只能到达 倒数第二个数，最后一个数不会被排序		
//		for(j=i+1 , q=p->pNext; j<len; j++, q=q->pNext)
//		{
//			if(p->data > q->data){ //类似于数组中的 a[i] > a[j] 
//				t = p->data; //类似于数组中的 a[i] = t 
//				p->data = q->data; //类似于数组中的 a[i] = a[j] 
//				q->data = t; //a[j] = t;
//			}
//		}
		
//	冒泡排序  首次出错为 未将首节点初始化赋值给p 
	for(i=0 ,p=pHead->pNext; i<len-1; i++, p=pHead->pNext)
	
		for(j=0 , q=p->pNext; j<len-i-1; j++, p=q, q=q->pNext)
		{
			if(p->data > q->data){ //类似于数组中的 a[i] > a[j] 
				t = p->data; //类似于数组中的 a[i] = t 
				p->data = q->data; //类似于数组中的 a[i] = a[j] 
				q->data = t; //a[j] = t;
			}
		}
	
	return;		

}

//插入和删除节点，本质上为添加 /删除目标位置
// 在第pos节点前插入一个新的节点 
bool insert_list(PNODE pHead, int pos, int val){
	int i =0;
	PNODE  p = pHead;
	
//	此行代码为判断并 找到目标节点的前一个节点（pos-1） 
// p对应节点时，i对应第几个节点  pos(目标位置节点)
	while(NULL!=p && i<pos-1){
		p = p->pNext;
		i++;
	}
	if(NULL==p || i>pos-1)
		return false;
	
	PNODE pNew = (PNODE)malloc(sizeof(Node));
	if(pNew == NULL){
		printf("动态内存分配失败，程序退出！ ");
		exit(-1); 
	} 
//	插入位置为 尾节点所处位置 +1时 
	if(length_list(pHead) == pos-1){
		p->pNext = pNew;
		pNew->data = val;
		pNew->pNext = NULL;
		return true;
	}
	else{
		pNew->data = val;
		pNew->pNext = p->pNext;
		p->pNext = pNew;
		return true;		
	}
} 
bool delete_list(PNODE pHead, int pos, int * pVal){
	int i =0;
	PNODE  p = pHead;
//	此行代码为判断并 找到所要删除的节点位置前一个节点 
//  此判断条件表明需至少拥有一个节点，并且删除的节点范围需要在已拥有范围内 
	while(NULL!=p->pNext && i<pos-1){
		p = p->pNext;
		i++;
	}
	if(NULL==p->pNext || i>pos-1)
		return false;
	
	PNODE q = p->pNext;
	*pVal =  q->data;

// 删除元素为最后一个元素时 
	 if(length_list(pHead) == pos){
		p->pNext = NULL;
		free(q);
		q=NULL;
		return true; 
	} 
	else{
		p->pNext = p->pNext->pNext;
		free(q);
		q = NULL;
		return true; 
	}
		
}

