#ifndef SIGNAL_CHAIN__H
#define SIGNAL_CHAIN__H

#include <stdio.h>
#include <malloc.h>
typedef struct LINKNODE
{
	void* data;
	struct LISTNODE* next;
}LinkNode;

typedef struct LINKLIST
{
	LinkNode* head;
	int size;
}LinkList;

typedef void(*PRINTLINKNODE)(void*);

LinkList* Init_LinkList(void);									//��ʼ������
void Insert_LinkList(LinkList* list, int pos, void* data);		//��������
void RemoveByPos_LinkList(LinkList* list, int pos);             //ɾ������
int Size_LinkList(LinkList* list);                              //���������
int Find_LinkList(LinkList* list, void* data);                  //����
void* Front_LinkList(LinkList* list);                           //��������һ������
void Print_LinkList(LinkList* list, PRINTLINKNODE print);		//��ӡ����
void FreeSpace_LinkList(LinkList* list);						//�ͷſռ�
#endif

