#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"


//������ӡ�ӿ�
void SListPrint(SListNode* phead)
{
	//�����������ǿ�������ͷָ�����ָ��NULL�����Դ˴�����Ӷ���
	SListNode* cur = phead;
	if (cur == NULL)
	{
		printf("������!");
	}
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//β��
void SListPushBack(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = CreateSListNode(x);
	//���pheadΪ��
	if (*pphead == NULL)
	{
		//̫���࣬��װΪ����
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
		//��β
		SListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//̫���࣬��װΪ����
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

//����ڵ㺯��
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
	//1.��
	if (*pphead == NULL)
	{
		return;
	}
	//2.ֻ��һ��
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//3.һ������
	else
	{
		SListNode* prev = NULL;  //�����ָ��prev��ָ��tailָ��Ľڵ��ǰһ���ڵ㣻
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


//ͷ��
void SListPushFront(SListNode** pphead, SListDataType x)
{
	SListNode* newNode = CreateSListNode(x);
	newNode->next = *pphead;
	*pphead = newNode;
}


//ͷɾ
void SListPopFront(SListNode** pphead)
{
	//1.Ϊ�ղ�ɾ
	if (*pphead == NULL)  //��ֹ���ǶԿ�ָ����н�����
	{
		return;
	}
	//2.���ֻ��1���ڵ� �� 3.��һ�����ϵĽڵ�
	else
	{
		SListNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//����
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

//�޸�
void SListUpdata(SListNode* pos, SListDataType x)
{
	assert(pos);
	pos->data = x;
}



//���루�ں��棩
void SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos);
	SListNode* newNode = CreateSListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}


//ɾ��posλ�õĽڵ�
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->next;  //��һ���ڵ�ĵ�ַ
	SListNode* nextnext = next->next;  //����һ���ڵ��ַ
	pos->next = nextnext;
	free(next);
}


//����
void SListDestroy(SListNode* plist)
{
	assert(plist);  //��ֹplistΪNULL
	SListNode* cur = plist;
	while (cur)
	{
		plist = plist->next;
		free(cur);
		cur = plist;
	}
}