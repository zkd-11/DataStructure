#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void Hannoi(int val, char A, char B, char C){
	if(val == 1)
	printf("\n �����Ϊ%d�����Ӵ� %c ���ƶ��� %c �� \n",val, A, C); 
	else{
	//�˾�ִ���� ��ζ�� n-1�������Ѵ� A�ƶ��� B 
		Hannoi(val-1,A, C, B); 
		
	// ��ǰ���ӵ� n�������� C��
	 	printf("\n �����Ϊ%d�����Ӵ� %c ���ƶ��� %c �� \n ", val, A,C);
	 	
	//�˾�ִ���� ��ζ�� B�ϵ�val-1 ����  Ų��C��
		Hannoi(val-1,B, A, C); 
	}
	return 0;

}

int main(){
	int val;
	char ch1='A', ch2 = 'B', ch3 = 'C';
	
	printf("��������������ĺ�ŵ��������");
	printf("\n"); 
	
	scanf("%d", &val);
	
	Hannoi(val, ch1, ch2, ch3);
} 
