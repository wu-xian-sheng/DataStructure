#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;


//结构复杂，操作简单
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

// 创建返回链表的头结点.
void ListCreate(ListNode** plist);

//申请一个节点
ListNode* BuyListNode(LTDataType x);

// 双向链表销毁
void ListDestory(ListNode** plist);

// 双向链表打印
void ListPrint(ListNode* plist);

// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x);

// 双向链表尾删
void ListPopBack(ListNode* plist);

// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x);

// 双向链表头删
void ListPopFront(ListNode* plist);

// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x);

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);

// 双向链表删除pos位置的结点
void ListErase(ListNode* pos);

// 双向链表清理但不销毁,保留头结点可以继续使用
void ListClear(ListNode* plist);

//双向链表修改数据接口
void ListUpData(ListNode* pos, LTDataType x);