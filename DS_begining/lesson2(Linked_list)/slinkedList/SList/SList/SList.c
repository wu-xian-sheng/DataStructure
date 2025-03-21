#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"


//遍历打印接口
void SListPrint(SListNode* phead)
{
	//如果这个链表是空链表，那头指针就是指向NULL，所以此处无需加断言
	SListNode* cur = phead;
	if (cur == NULL)
	{
		printf("空链表!");
	}
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//尾插
void SListPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = CreateSListNode(x);
	//如果phead为空
	if (*pphead == NULL)
	{
		//太冗余，封装为函数
		/*SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
		if (newNode == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		newNode->data = x;
		newNode->next = NULL;*/
		*pphead = newNode;
	}
	else
	{
		//找尾
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//太冗余，封装为函数
		/*SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
		if (newNode == NULL)
		{
			perror("malloc");
			exit(-1);
		}
		newNode->data = x;
		newNode->next = NULL;*/
		tail->next = newNode;
	}
	
}

//创造节点函数
SListNode* CreateSListNode(SListDataType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void SListPopBack(SListNode** pphead)
{
	//1.空
	if (*pphead == NULL)
	{
		return;
	}
	//2.只有一个
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3.一个以上
	else
	{
		SListNode* prev = NULL;  //定义个指针prev来指向tail指向的节点的前一个节点；
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}


//头插
void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = CreateSListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}


//头删
void SListPopFront(SListNode** pphead)
{
	//1.为空不删
	if (*pphead == NULL)  //防止我们对空指针进行解引用
	{
		return;
	}
	//2.如果只有1个节点 或 3.有一个以上的节点
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//查找
SListNode* SListFind(SListNode* plist, SListDataType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//修改
void SListUpdata(SListNode* pos, SListDataType x)
{
	assert(pos);
	pos->data = x;
}



//插入（在后面）
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* newNode = CreateSListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}


//删除pos位置的节点
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->next;  //下一个节点的地址
	SListNode* nextnext = next->next;  //下下一个节点地址
	pos->next = nextnext;
	free(next);
}


//销毁
void SListDestroy(SListNode* plist)
{
	assert(plist);  //防止plist为NULL
	SListNode* cur = plist;
	while (cur)
	{
		plist = plist->next;
		free(cur);
		cur = plist;
	}
}