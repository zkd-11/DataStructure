#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

long f(long n){
	if(1 == n)
		return 1;
	else
		return n * f(n-1); 
//f(n-1)Ϊ��ǰֵ-1�Ľ׳ˣ��ݹ���룬���ջ�� 
}
long g(long n){
	if(1 == n)
		return 1;
	else
		return n + g(n-1); 
//f(n-1)Ϊ��ǰֵ-1�Ľ׳ˣ��ݹ���룬���ջ�� 
}

int main(){
	long c,n,t;
	printf("������Ҫ����׳˵�ֵ�� \n");
	scanf("%d",&c);
	for(n=1, t=1; n<=c; n++){
			t = n*t;
	}
	printf("%d�Ľ׳�ֵ = %ld \n",c, t);
	
	printf("ͨ���ݹ���%d�Ľ׳�ֵ = %ld \n",c, f(c));

	printf("ͨ���ݹ���%d��1��ʼ�����ֵ = %ld",c, g(c));
}



