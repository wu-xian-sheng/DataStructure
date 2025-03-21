#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

//typedef struct SListNode
//{
//	SListNode* head;
//	SListNode* tail;
//};

//��ӡ���
void SListPrint(SListNode* phead);
//�����ռ�
SListNode* CreateSListNode(SListDataType x);
//β��
void SListPushBack(SListNode** phead, SListDataType x);
//βɾ
void SListPopBack(SListNode** phead);

//ͷ��
void SListPushFront(SListNode** pphead, SListDataType x);
//ͷɾ
void SListPopFront(SListNode** pphead);

//����
SListNode* SListFind(SListNode* plist, SListDataType x);

//�޸�
void SListUpdata(SListNode* pos, SListDataType x);

//����
void SListInsertAfter(SListNode* pos, SListDataType x);

//ɾ��
void SListEraseAfter(SListNode* pos);

//����
void SListDestroy(SListNode* plist);