#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

void Hannoi(int val, char A, char B, char C){
	if(val == 1)
	printf("\n 将编号为%d的盘子从 %c 柱移动到 %c 柱 \n",val, A, C); 
	else{
	//此句执行完 意味着 n-1个盘子已从 A移动到 B 
		Hannoi(val-1,A, C, B); 
		
	// 当前盘子第 n个放入至 C盘
	 	printf("\n 将编号为%d的盘子从 %c 柱移动到 %c 柱 \n ", val, A,C);
	 	
	//此句执行完 意味着 B上的val-1 盘子  挪至C盘
		Hannoi(val-1,B, A, C); 
	}
	return 0;

}

int main(){
	int val;
	char ch1='A', ch2 = 'B', ch3 = 'C';
	
	printf("请输入你所放入的汉诺塔层数：");
	printf("\n"); 
	
	scanf("%d", &val);
	
	Hannoi(val, ch1, ch2, ch3);
} 
