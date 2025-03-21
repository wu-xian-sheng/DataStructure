#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

//申请一个节点
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

// 创建返回链表的头结点.
void ListCreate(ListNode** pplist) {
	*pplist = BuyListNode(0);
	(*pplist)->next = *pplist;
	(*pplist)->prev = *pplist;
}

// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	//防止plist为空
	assert(plist);

	//ListNode* tail = plist->prev;
	//
	//ListNode* newNode = BuyListNode(x);

	////链接
	//tail->next = newNode;
	//newNode->prev = tail;

	//newNode->next = plist;
	//plist->prev = newNode;
	ListInsert(plist, x);
}


// 双向链表打印
void ListPrint(ListNode* plist) {
	assert(plist);
	ListNode* cur = plist->next;
	if (cur == plist)
		printf("空链表");
	while (cur != plist)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

// 双向链表尾删
// 
// 
//void ListPopBack(ListNode* plist) {
//	assert(plist);
//
//	//找到尾节点
//	ListNode* tail = plist->prev;
//	
//	//可行，但可读性不强
//	
//	//改变头指针的prev
//	plist->prev = tail->prev;
//
//	//改变尾指针上一个节点的next
//	tail->prev->next = plist;
//
//	free(tail);
//  tail = NULL;//防止野指针，函数内部局部变量，不置空也可以
//}


//上面的代码不利于可读性，我们可以这样写
void ListPopBack(ListNode* plist) {
	assert(plist);
	
	assert(plist->next != plist);//防止对空链表进行删除
	
	//ListNode* tail = plist->prev;
	//ListNode* tailPrev = tail->prev;

	//tailPrev->next = plist;
	//plist->prev = tailPrev;

	//free(tail);
	//tail = NULL;//防止野指针，函数内部局部变量，不置空也可以

	ListErase(plist->prev);
}


// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x) {
	assert(plist);

	////创建新节点
	//ListNode* cur = BuyListNode(x);
	////找到插入后的下一个节点
	//ListNode* curNext = plist->next;

	////解决头指针与新节点的链接
	//plist->next = cur;
	//cur->prev = plist;

	////解决下一个节点与新节点的链接
	//curNext->prev = cur;
	//cur->next = curNext;

	ListInsert(plist->next, x);
}

// 双向链表头删
void ListPopFront(ListNode* plist) {
	assert(plist);
	assert(plist != plist->next);//防止对空链表删除，free了头指针

	////指向被删节点
	//ListNode* cur = plist->next;
	////被删节点的下个节点
	//ListNode* curNext = cur->next;

	////取消头结点与第一个节点链接
	//plist->next = curNext;
	//curNext->prev = plist;

	////释放空间
	//free(cur);
	//cur = NULL;

	ListErase(plist->next);
}


// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x) {
	assert(plist);

	ListNode* cur = plist->next;
	while(cur != plist)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	//没找到

	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	//申请新的节点
	ListNode* cur = BuyListNode(x);
	ListNode* curPrev = pos->prev;

	//解决cur与前面的节点的链接
	curPrev->next = cur;
	cur->prev = curPrev;

	//解决cur与后面的节点的链接
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


// 双向链表销毁,利用二级指针，将plist置为空，防止野指针
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

// 双向链表清理但不销毁,保留头结点可以继续使用
void ListClear(ListNode* plist){
	assert(plist);
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		ListNode* next = cur->next; //记录下一个节点的地址
		free(cur);  //释放目标节点
		cur = next; //指向下一个节点
	}
	plist->next = plist;
	plist->prev = plist;
}


//双向链表修改数据接口
void ListUpData(ListNode* pos, LTDataType x){
	assert(pos);
	pos->data = x;
}