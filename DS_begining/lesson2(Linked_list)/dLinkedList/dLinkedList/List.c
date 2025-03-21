#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

//����һ���ڵ�
ListNode* BuyListNode(LTDataType x) {
	ListNode* newNode = malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

// �������������ͷ���.
void ListCreate(ListNode** pplist) {
	*pplist = BuyListNode(0);
	(*pplist)->next = *pplist;
	(*pplist)->prev = *pplist;
}

// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x)
{
	//��ֹplistΪ��
	assert(plist);

	//ListNode* tail = plist->prev;
	//
	//ListNode* newNode = BuyListNode(x);

	////����
	//tail->next = newNode;
	//newNode->prev = tail;

	//newNode->next = plist;
	//plist->prev = newNode;
	ListInsert(plist, x);
}


// ˫�������ӡ
void ListPrint(ListNode* plist) {
	assert(plist);
	ListNode* cur = plist->next;
	if (cur == plist)
		printf("������");
	while (cur != plist)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// ˫������βɾ
// 
// 
//void ListPopBack(ListNode* plist) {
//	assert(plist);
//
//	//�ҵ�β�ڵ�
//	ListNode* tail = plist->prev;
//	
//	//���У����ɶ��Բ�ǿ
//	
//	//�ı�ͷָ���prev
//	plist->prev = tail->prev;
//
//	//�ı�βָ����һ���ڵ��next
//	tail->prev->next = plist;
//
//	free(tail);
//  tail = NULL;//��ֹҰָ�룬�����ڲ��ֲ����������ÿ�Ҳ����
//}


//����Ĵ��벻���ڿɶ��ԣ����ǿ�������д
void ListPopBack(ListNode* plist) {
	assert(plist);
	
	assert(plist->next != plist);//��ֹ�Կ��������ɾ��
	
	//ListNode* tail = plist->prev;
	//ListNode* tailPrev = tail->prev;

	//tailPrev->next = plist;
	//plist->prev = tailPrev;

	//free(tail);
	//tail = NULL;//��ֹҰָ�룬�����ڲ��ֲ����������ÿ�Ҳ����

	ListErase(plist->prev);
}


// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x) {
	assert(plist);

	////�����½ڵ�
	//ListNode* cur = BuyListNode(x);
	////�ҵ���������һ���ڵ�
	//ListNode* curNext = plist->next;

	////���ͷָ�����½ڵ������
	//plist->next = cur;
	//cur->prev = plist;

	////�����һ���ڵ����½ڵ������
	//curNext->prev = cur;
	//cur->next = curNext;

	ListInsert(plist->next, x);
}

// ˫������ͷɾ
void ListPopFront(ListNode* plist) {
	assert(plist);
	assert(plist != plist->next);//��ֹ�Կ�����ɾ����free��ͷָ��

	////ָ��ɾ�ڵ�
	//ListNode* cur = plist->next;
	////��ɾ�ڵ���¸��ڵ�
	//ListNode* curNext = cur->next;

	////ȡ��ͷ������һ���ڵ�����
	//plist->next = curNext;
	//curNext->prev = plist;

	////�ͷſռ�
	//free(cur);
	//cur = NULL;

	ListErase(plist->next);
}


// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x) {
	assert(plist);

	ListNode* cur = plist->next;
	while(cur != plist)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	//û�ҵ�

	return NULL;
}

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	//�����µĽڵ�
	ListNode* cur = BuyListNode(x);
	ListNode* curPrev = pos->prev;

	//���cur��ǰ��Ľڵ������
	curPrev->next = cur;
	cur->prev = curPrev;

	//���cur�����Ľڵ������
	cur->next = pos;
	pos->prev = cur;
}




void ListErase(ListNode* pos) {
	assert(pos);
	/*assert(pos != plist);*/

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
	pos = NULL;
}


// ˫����������,���ö���ָ�룬��plist��Ϊ�գ���ֹҰָ��
void ListDestory(ListNode** plist) {
	assert(*plist);

	/*ListNode* cur = plist;
	while (cur != plist)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}*/
	ListClear(*plist);
	free(*plist);
	*plist = NULL;

}

// ˫����������������,����ͷ�����Լ���ʹ��
void ListClear(ListNode* plist){
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		ListNode* next = cur->next; //��¼��һ���ڵ�ĵ�ַ
		free(cur);  //�ͷ�Ŀ��ڵ�
		cur = next; //ָ����һ���ڵ�
	}
	plist->next = plist;
	plist->prev = plist;
}


//˫�������޸����ݽӿ�
void ListUpData(ListNode* pos, LTDataType x){
	assert(pos);
	pos->data = x;
}