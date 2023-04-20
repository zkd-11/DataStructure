#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include <cstdlib>

struct Arr{
	int * pBase; //存储数组首元素的地址
	int len; // 数组容纳的最大元素的个数 
	int cnt; //当前数组有效元素个数 
//	int increment 自动增长因子， 拿空间换时间，提高效率 
// 举例： 插入1时会自动插入5的空间  需要用到动态扩充的知识
};

void init_arr(struct Arr *pArr, int length);
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
  
void show_arr(struct Arr * pArr);
bool reset_arr(struct Arr *pArr, int cnt,int var);
bool append_arr(struct Arr *pArr, int index);
bool insert_arr(struct Arr *pArr, int index,int var);

//可视化 操作优化-- 生成数组 

int main(){
	struct Arr arr;
	init_arr(&arr, 6); //将构造的数组 通过传地址 调用函数初始化 
	
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
			printf("报告赵哥，空间分配失败"); 
			exit(-1);
		}
	pArr->	len = length;
	pArr->  cnt = 0; 
}

//判断数组元素是否为空 
bool is_empty(struct Arr * pArr){
	if(pArr-> cnt == NULL)
		return true;
	else
		return false;
} 

//判断数组元素是否为满 
bool is_full(struct Arr * pArr){
	if(pArr-> cnt == pArr->len)
		return true;
	else
		return false;
} 

// 将数组元素输出 
void show_arr(struct Arr * pArr){
	printf(" \n   数组元素的个数为: %d \n", pArr->cnt); 
	if(is_empty(pArr)){
		printf("数组元素个数为0，无法为您输出！ \n");
	}else{
		for(int i=0; i<(pArr->cnt); i++){
			printf("数组中第%d的元素为： %d  \n", i+1, pArr->pBase[i] ); 
		}	
	}
	return ;
} 

// 从数组尾部 插入元素 
bool append_arr(struct Arr *pArr, int var){
		if(is_full(pArr)){
		printf("数组元素个数已满，无法添加 \n");
		return false;
	}else{
		pArr->pBase[pArr->cnt] = var;
		pArr->cnt++;
		return true;
	}
}

// 替换指定下标的元素 
bool reset_arr(struct Arr *pArr, int index,int var){

	if(pArr->cnt >= index+1 && !is_empty(pArr)){
		pArr->pBase[index] = var;
		return true;
		}
	else
		return false;

}

// 指定位置插入元素 
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









