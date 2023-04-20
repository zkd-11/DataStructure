#include<stdio.h>
#include<string.h>

struct Student{
	int sid;
	char name[200];
	int age;
};
//提前声明， main后定义了两个方法（在后面需要声明） 
void g(struct Student *pst);
void f(struct Student *pst);

int main(void){
	struct Student st = {100, "韩绝", 22};
	strcpy(st.name , "韩绝哥");
	printf("%d  %s %d \n", st.sid, st.name, st.age); 
	
	struct Student * pst;
	 pst = &st;
	 pst ->sid = 99;  //等价于 (*pst).sid 等价于 st.sod
//	 pst  指向结构体的成员 sid 

	struct Student st1; //未赋值， st1存储的为垃圾数值
	g(&st1);
	f(&st1);
	 
}

void g(struct Student * pst){
	(*pst).sid = 1998;
	strcpy(pst->name, "赵哥");
	(*pst).age = 20; 
} 
void f(struct Student * pst){
	printf("\n 为您输出赵哥的信息： %d %s %d \n", pst->sid, pst->name, pst->age);
}

