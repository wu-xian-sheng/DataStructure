#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;


//�ṹ���ӣ�������
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

// �������������ͷ���.
void ListCreate(ListNode** plist);

//����һ���ڵ�
ListNode* BuyListNode(LTDataType x);

// ˫����������
void ListDestory(ListNode** plist);

// ˫�������ӡ
void ListPrint(ListNode* plist);

// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x);

// ˫������βɾ
void ListPopBack(ListNode* plist);

// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x);

// ˫������ͷɾ
void ListPopFront(ListNode* plist);

// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x);

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);

// ˫������ɾ��posλ�õĽ��
void ListErase(ListNode* pos);

// ˫����������������,����ͷ�����Լ���ʹ��
void ListClear(ListNode* plist);

//˫�������޸����ݽӿ�
void ListUpData(ListNode* pos, LTDataType x);