#include<stdio.h>
#include<malloc.h>
#include<string.h>

struct Student{
	int age;
	char name[100];
};
struct Student *  CreateStudent();
void ShowStudent (struct Student* pst);

int main() {
	struct Student * ps;
	ps = CreateStudent();
	ShowStudent(ps);
	return 0;
}

struct Student *  CreateStudent() {
	struct Student * p = (struct Student*)malloc(sizeof(struct Student));

	p->age = 20;
	strcpy(p->name, "����");
	return p;
}

void ShowStudent (struct Student* pst){
	printf("����Ϊ�� %d, ����Ϊ : %s",(*pst).age, pst->name);
}


