#include<stdio.h>
#include<string.h>

struct Student{
	int sid;
	char name[200];
	int age;
};
//��ǰ������ main�����������������ں�����Ҫ������ 
void g(struct Student *pst);
void f(struct Student *pst);

int main(void){
	struct Student st = {100, "����", 22};
	strcpy(st.name , "������");
	printf("%d  %s %d \n", st.sid, st.name, st.age); 
	
	struct Student * pst;
	 pst = &st;
	 pst ->sid = 99;  //�ȼ��� (*pst).sid �ȼ��� st.sod
//	 pst  ָ��ṹ��ĳ�Ա sid 

	struct Student st1; //δ��ֵ�� st1�洢��Ϊ������ֵ
	g(&st1);
	f(&st1);
	 
}

void g(struct Student * pst){
	(*pst).sid = 1998;
	strcpy(pst->name, "�Ը�");
	(*pst).age = 20; 
} 
void f(struct Student * pst){
	printf("\n Ϊ������Ը����Ϣ�� %d %s %d \n", pst->sid, pst->name, pst->age);
}

