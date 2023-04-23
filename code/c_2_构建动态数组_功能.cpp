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

//���ã� ��β���� 
void inversion_arr(struct Arr *pArr);
void show_arr(struct Arr * pArr);

bool reset_arr(struct Arr *pArr, int cnt,int var);
bool append_arr(struct Arr *pArr, int index);
bool insert_arr(struct Arr *pArr, int index,int var);
bool delete_arr(struct Arr *pArr, int index, int *p);

bool sort_arr(struct Arr *pArr);


//���ӻ� �����Ż�-- �������� 

int main(){
	int val;
	struct Arr arr;
	init_arr(&arr, 7); //����������� ͨ������ַ ���ú�����ʼ�� 
	
	append_arr(&arr,1);
	append_arr(&arr,3);
	show_arr(&arr);
	reset_arr(&arr, 1, 5);
	append_arr(&arr,3);
	show_arr(&arr);
	
	insert_arr(&arr,3,15);
	show_arr(&arr);
	
	delete_arr(&arr,0,&val);
	show_arr(&arr);
	
	inversion_arr(&arr);
	show_arr(&arr);

	sort_arr(&arr);
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
		if(pArr->cnt == index ){
			pArr->pBase[index] = var;
			pArr->cnt++;	
			return true;
			}
		else{	
			if(index <0 ) exit(-1); 
		
			 
			
//		 �˴�forѭ���ô� �Ӻ���ǰ�� ����Ӧ���� �ж�����Ӧ���� >=����ִ�У�<�˳�ѭ�� 
				for(int i =1; pArr->cnt-i >= index; i++) {
				pArr->pBase[pArr->cnt] = pArr->pBase[pArr->cnt-i];
			}
		  	pArr->pBase[index] = var;
		  	pArr->cnt++;
		  	return true;
		} 
	}else
		return false;
	
}

//ɾ��ָ��λ�� 

bool delete_arr(struct Arr *pArr, int index, int *p) {
//	cnt-1 Ϊ���������һ��Ԫ�ص��±� 
	if( !is_empty(pArr) && pArr->cnt-1 >= index){
		if(pArr->cnt-1 == index ){
			*p = pArr->pBase[index]; 
			pArr->cnt--;	
			printf("\n ɾ����Ԫ��ֵΪ: %d", *p);
			return true;
			}
		else{	
			if(index <0 ) exit(-1); 
			
				for(int i = index; i < pArr->cnt-1; i++) {
					if(i == index) *p = pArr->pBase[index]; // 
					pArr->pBase[i] = pArr->pBase[i+1];
			}
		  	pArr->cnt--;
		  	printf("\n ɾ����Ԫ��ֵΪ: %d", *p);
		  	return true;
		} 
	}else
		return false;
	
}

// ����Ԫ�ص��� 
void inversion_arr(struct Arr *pArr){
	int i = 0;
	int j = pArr->cnt-1;
	int t;
	while(i<j){
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		i++;
		j--; 
	} 
	return; 
	
}

//ѡ������ 
bool sort_arr(struct Arr *pArr){
	int t;
	if(is_empty(pArr))
		return false; 
	else
//		for(int i=0; i<pArr->cnt-1; i++){
//			for(int j=i+1; j<pArr->cnt; j++){
//				if(pArr->pBase[i] > pArr->pBase[j]){
//					t = pArr->pBase[i];
//					pArr->pBase[i] = pArr->pBase[j]; 
//					pArr->pBase[j] = t;
//				}
//			
//			}
//	
//		}
			for(int i=0; i<pArr->cnt-1; i++){			
			for(int j=0; j<pArr->cnt-i-1; j++){
				if(pArr->pBase[j] > pArr-> pBase[j+1]){
					t = pArr->pBase[j];
					pArr->pBase[j] = pArr->pBase[j+1]; 
					pArr->pBase[j+1] = t;			

				}
			
			}
	
		}
	
		return true;	
}




