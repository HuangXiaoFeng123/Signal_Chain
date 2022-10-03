#define _CRT_SECURE_NO_DEPRECATE
#include "signal_chain.h"

typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;
void MyPrint(void* data)
{
	Person* p = (Person*)data;
	printf("name =%s, age=%d, score=%d\n", p->name, p->age, p->score);
}
int main(void)
{
	LinkList* list = Init_LinkList();
	Person p1 = { "aaa",18,100 };
	Person p2 = { "bbb",17,86 };
	Person p3 = { "ccc",23,73 };
	Person p4 = { "ddd",45,40 };
	Person p5 = { "eee",12,59 };
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Print_LinkList(list, MyPrint);
	printf("=========================\n");
	RemoveByPos_LinkList(list, 3);
	Print_LinkList(list, MyPrint);
	printf("=========================\n");
	Person* ret = (Person*)Front_LinkList(list);
	printf("name =%s, age=%d, score=%d\n", ret->name, ret->age, ret->score);
	FreeSpace_LinkList(list);
	return 0;
}