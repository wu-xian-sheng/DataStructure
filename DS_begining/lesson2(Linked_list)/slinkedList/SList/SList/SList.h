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

//打印输出
void SListPrint(SListNode* phead);
//创建空间
SListNode* CreateSListNode(SListDataType x);
//尾插
void SListPushBack(SListNode** phead, SListDataType x);
//尾删
void SListPopBack(SListNode** phead);

//头插
void SListPushFront(SListNode** pphead, SListDataType x);
//头删
void SListPopFront(SListNode** pphead);

//查找
SListNode* SListFind(SListNode* plist, SListDataType x);

//修改
void SListUpdata(SListNode* pos, SListDataType x);

//插入
void SListInsertAfter(SListNode* pos, SListDataType x);

//删除
void SListEraseAfter(SListNode* pos);

//销毁
void SListDestroy(SListNode* plist);