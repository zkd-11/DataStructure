#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node * pNext; //ָ���� ָ��һ�����Լ�ͬ�������͵ĵĽṹ��
//	ָ����һ���ڵ� 
} Node, *PNODE; // �ṹ������ Node, �ṹ��ָ�� PNODE

//�������� 
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
		printf("\n \n ����ڵ㳤��Ϊ��%d \n", length_list(pHead));
	sort_list(pHead);
	traverse_list(pHead);
	
	insert_list(pHead, 1, 33);
	traverse_list(pHead);
	
	if(delete_list(pHead,1,&val)){
		printf("\n ɾ���ɹ�- ɾ����Ԫ��Ϊ�� %d \n", val);
	}else printf("\n ɾ��ʧ�ܣ�\n ");
	traverse_list(pHead);	
		
	return 0;
} 

PNODE create_List(){
	PNODE pHead = (PNODE) malloc(sizeof(Node));
	pHead->pNext = NULL; 
	
	PNODE pTail = pHead;
	int len, val;
	
	printf("������Ҫ��������Ľڵ������len = ");
	scanf("%d", &len);
	
	 
	for(int i=0; i<len; i++){
		printf(" \n �������%d�ڵ��ֵ: ", i+1);
		scanf("%d", &val);
		
		PNODE pNew = (PNODE)malloc(sizeof(Node));
		if(NULL == pNew){
			printf("����ʧ�ܣ�������ֹ! \n");
			exit(-1);
		}
		pTail->pNext = pNew;
		pNew->data = val;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
//�������� 
void traverse_list(PNODE pHead){
	printf("\n �Ը磬Ϊ������������Ԫ�أ� \n"); 
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("%d \t ",p->data);
		p = p->pNext;
	}
	return;
}

//�����Ƿ�Ϊ�� 
bool is_empty(PNODE pHead){
	if(pHead->pNext!= NULL)
		return false;
	else
		return true;
} 
//������ 
int length_list(PNODE pHead){
	PNODE p = pHead->pNext;
	int len = 0;
	while(p != NULL){
		len++;
		p = p->pNext;
	}
	return len;
} 
//����ڵ��������� 
void sort_list(PNODE pHead){
	int i, j, t, len;
	len = length_list(pHead);
	PNODE p, q; 
//	for(i=0, p=pHead->pNext; i<len-1; i++, p=p->pNext)
//// �����ж�ԭдΪ�� ѡ������ 
//// j<len-1, ����j����ֻ�ܵ��� �����ڶ����������һ�������ᱻ����		
//		for(j=i+1 , q=p->pNext; j<len; j++, q=q->pNext)
//		{
//			if(p->data > q->data){ //�����������е� a[i] > a[j] 
//				t = p->data; //�����������е� a[i] = t 
//				p->data = q->data; //�����������е� a[i] = a[j] 
//				q->data = t; //a[j] = t;
//			}
//		}
		
//	ð������  �״γ���Ϊ δ���׽ڵ��ʼ����ֵ��p 
	for(i=0 ,p=pHead->pNext; i<len-1; i++, p=pHead->pNext)
	
		for(j=0 , q=p->pNext; j<len-i-1; j++, p=q, q=q->pNext)
		{
			if(p->data > q->data){ //�����������е� a[i] > a[j] 
				t = p->data; //�����������е� a[i] = t 
				p->data = q->data; //�����������е� a[i] = a[j] 
				q->data = t; //a[j] = t;
			}
		}
	
	return;		

}

//�����ɾ���ڵ㣬������Ϊ��� /ɾ��Ŀ��λ��
// �ڵ�pos�ڵ�ǰ����һ���µĽڵ� 
bool insert_list(PNODE pHead, int pos, int val){
	int i =0;
	PNODE  p = pHead;
	
//	���д���Ϊ�жϲ� �ҵ�Ŀ��ڵ��ǰһ���ڵ㣨pos-1�� 
// p��Ӧ�ڵ�ʱ��i��Ӧ�ڼ����ڵ�  pos(Ŀ��λ�ýڵ�)
	while(NULL!=p && i<pos-1){
		p = p->pNext;
		i++;
	}
	if(NULL==p || i>pos-1)
		return false;
	
	PNODE pNew = (PNODE)malloc(sizeof(Node));
	if(pNew == NULL){
		printf("��̬�ڴ����ʧ�ܣ������˳��� ");
		exit(-1); 
	} 
//	����λ��Ϊ β�ڵ�����λ�� +1ʱ 
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
//	���д���Ϊ�жϲ� �ҵ���Ҫɾ���Ľڵ�λ��ǰһ���ڵ� 
//  ���ж���������������ӵ��һ���ڵ㣬����ɾ���Ľڵ㷶Χ��Ҫ����ӵ�з�Χ�� 
	while(NULL!=p->pNext && i<pos-1){
		p = p->pNext;
		i++;
	}
	if(NULL==p->pNext || i>pos-1)
		return false;
	
	PNODE q = p->pNext;
	*pVal =  q->data;

// ɾ��Ԫ��Ϊ���һ��Ԫ��ʱ 
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

