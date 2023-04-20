#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include <cstdlib>

struct Arr{
	int * pBase; //�洢������Ԫ�صĵ�ַ
	int len; // �������ɵ����Ԫ�صĸ��� 
	int cnt; //��ǰ������ЧԪ�ظ��� 
//	int increment �Զ��������ӣ� �ÿռ任ʱ�䣬���Ч�� 
// ������ ����1ʱ���Զ�����5�Ŀռ�  ��Ҫ�õ���̬�����֪ʶ
};

void init_arr(struct Arr *pArr, int length);
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
  
void show_arr(struct Arr * pArr);
bool reset_arr(struct Arr *pArr, int cnt,int var);
bool append_arr(struct Arr *pArr, int index);
bool insert_arr(struct Arr *pArr, int index,int var);

//���ӻ� �����Ż�-- �������� 

int main(){
	struct Arr arr;
	init_arr(&arr, 6); //����������� ͨ������ַ ���ú�����ʼ�� 
	
	append_arr(&arr,1);
	append_arr(&arr,3);
	show_arr(&arr);
	reset_arr(&arr, 1, 5);
	append_arr(&arr,3);
	
	insert_arr(&arr,0,15);
	show_arr(&arr);
	
}

void init_arr(struct Arr *pArr, int length){
	pArr-> pBase = (int*) malloc (sizeof(int)* length);
		if(pArr->pBase == NULL){
			printf("�����Ը磬�ռ����ʧ��"); 
			exit(-1);
		}
	pArr->	len = length;
	pArr->  cnt = 0; 
}

//�ж�����Ԫ���Ƿ�Ϊ�� 
bool is_empty(struct Arr * pArr){
	if(pArr-> cnt == NULL)
		return true;
	else
		return false;
} 

//�ж�����Ԫ���Ƿ�Ϊ�� 
bool is_full(struct Arr * pArr){
	if(pArr-> cnt == pArr->len)
		return true;
	else
		return false;
} 

// ������Ԫ����� 
void show_arr(struct Arr * pArr){
	printf(" \n   ����Ԫ�صĸ���Ϊ: %d \n", pArr->cnt); 
	if(is_empty(pArr)){
		printf("����Ԫ�ظ���Ϊ0���޷�Ϊ������� \n");
	}else{
		for(int i=0; i<(pArr->cnt); i++){
			printf("�����е�%d��Ԫ��Ϊ�� %d  \n", i+1, pArr->pBase[i] ); 
		}	
	}
	return ;
} 

// ������β�� ����Ԫ�� 
bool append_arr(struct Arr *pArr, int var){
		if(is_full(pArr)){
		printf("����Ԫ�ظ����������޷���� \n");
		return false;
	}else{
		pArr->pBase[pArr->cnt] = var;
		pArr->cnt++;
		return true;
	}
}

// �滻ָ���±��Ԫ�� 
bool reset_arr(struct Arr *pArr, int index,int var){

	if(pArr->cnt >= index+1 && !is_empty(pArr)){
		pArr->pBase[index] = var;
		return true;
		}
	else
		return false;

}

// ָ��λ�ò���Ԫ�� 
bool insert_arr(struct Arr *pArr, int index,int var) {
	if( !is_full(pArr) && pArr->cnt >= index){
		if(pArr->cnt == index){
			pArr->pBase[index] = var;
			pArr->cnt++;	
			return true;
			}
		else{	
			for(int i =1; pArr->cnt-i == index; i++) {
				pArr->pBase[pArr->cnt-i] = pArr->pBase[pArr->cnt];
			}
		  	pArr->pBase[index] = var;
//		  	pArr->cnt++;
		  	return true;
		} 
	}else
		return false;
	
}









