#include "signal_chain.h"

LinkList* Init_LinkList(void)									//��ʼ������
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->size = 0;
	list->head = (LinkNode*)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;
	return list;
}
void Insert_LinkList(LinkList* list, int pos, void* data)		//��������
{
	if (list == NULL || data == NULL)
	{
		return;
	}
	if (pos<0 || pos>=list->size)
	{
		pos = list->size;
	}
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));   //�����½ڵ�
	newNode->data = data;
	newNode->next = NULL;
	LinkNode* pCurrent = list->head;                           //������ʱ�ڵ�
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;							   //�����������
	}
	newNode->next = pCurrent->next;
	pCurrent->next = newNode;
	list->size++;
}
void RemoveByPos_LinkList(LinkList* list, int pos)             //ɾ������
{
	if (list == NULL || pos < 0 || pos >= list->size)
	{
		return;
	}
	LinkNode* pCurrent = list->head;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}
	LinkNode* pDel = pCurrent->next;
	pCurrent->next = pDel->next;
	free(pDel);
	list->size--;
}
int Size_LinkList(LinkList* list)                              //���������
{
	return list->size;
}
int Find_LinkList(LinkList* list, void* data)                  //����
{
	if (list == NULL || data == NULL)
	{
		return -1;
	}
	LinkNode* pCurrent = list->head->next;
	int i = 0;
	while (pCurrent != NULL)
	{
		if (pCurrent->data == data)
		{
			break;
		}
		pCurrent = pCurrent->next;
		i++;
	}
	return i;
}
void* Front_LinkList(LinkList* list)                           //��������һ������
{
	LinkNode* temp = list->head->next;
	return temp->data;
}
void Print_LinkList(LinkList* list, PRINTLINKNODE print)	  //��ӡ����
{
	if (list == NULL)
	{
		return;
	}
	LinkNode* pCurrent = list->head->next;
	while (pCurrent != NULL)
	{
		print(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}
void FreeSpace_LinkList(LinkList* list) 					  //�ͷſռ�
{
	if (list == NULL)
	{
		return;
	}
	LinkNode* pCurrent = list->head;
	while (pCurrent != NULL)
	{
		LinkNode* pNext = pCurrent->next;
		free(pCurrent);
		pCurrent = pNext;
	}
	free(list);
}