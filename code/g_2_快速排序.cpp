#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void QuickSort(int *a, int low, int high);
int FindPos(int *a, int low, int high); 
int main(){
	int a[5]= {1, 4, 77, 53,-3};
	
	QuickSort(a, 0, 4);
	for(int i=0; i<5; i++){
		printf("�����ڵ�%d��Ԫ�ص�ֵΪ��%d \n", i+1, a[i]);
	}
	return 0; 
}
//�ݹ���еĿ������� 
void QuickSort(int *a, int low, int high){
	int pos;
	if (low < high){
		pos = FindPos(a, low, high);
		QuickSort(a, low, pos-1);
		QuickSort(a, pos+1, high);
	}
	return;
}
int FindPos(int *a, int low, int high){
	int val = a[low];
	
		while(low<high){
			while(low<high && a[high] >= val)
				high--;
			a[low] = a[high];
			
		while(low<high && a[low] <= val)
				low++;
			a[high] = a[low];
			}
	a[high] = val;  //a[low ]= val; ����whileѭ��ʱ���ѵ���÷ŵ�λ�� 
	return high;
		
	}


