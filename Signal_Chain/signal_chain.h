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

LinkList* Init_LinkList(void);									//初始化链表
void Insert_LinkList(LinkList* list, int pos, void* data);		//插入数据
void RemoveByPos_LinkList(LinkList* list, int pos);             //删除数据
int Size_LinkList(LinkList* list);                              //获得链表长度
int Find_LinkList(LinkList* list, void* data);                  //查找
void* Front_LinkList(LinkList* list);                           //获得链表第一个数据
void Print_LinkList(LinkList* list, PRINTLINKNODE print);		//打印链表
void FreeSpace_LinkList(LinkList* list);						//释放空间
#endif

