#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

long f(long n){
	if(1 == n)
		return 1;
	else
		return n * f(n-1); 
//f(n-1)为当前值-1的阶乘，递归进入，最终获得 
}
long g(long n){
	if(1 == n)
		return 1;
	else
		return n + g(n-1); 
//f(n-1)为当前值-1的阶乘，递归进入，最终获得 
}

int main(){
	long c,n,t;
	printf("请输入要计算阶乘的值： \n");
	scanf("%d",&c);
	for(n=1, t=1; n<=c; n++){
			t = n*t;
	}
	printf("%d的阶乘值 = %ld \n",c, t);
	
	printf("通过递归获得%d的阶乘值 = %ld \n",c, f(c));

	printf("通过递归获得%d从1开始的类加值 = %ld",c, g(c));
}



