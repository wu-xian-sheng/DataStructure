#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

void TestDList1()
{
	ListNode* plist = NULL;
	ListCreate(&plist);

	//尾插
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);

	

	//头插
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPushFront(plist, 6);
	ListPushFront(plist, 7);
	ListPrint(plist);



	// 双向链表在pos的前面进行插入
	ListNode* pos = ListFind(plist,2);   //利用ListFind找到目标节点
	ListInsert(pos, 8);
	ListPrint(plist);



	//修改pos所指节点的值
	ListUpData(pos, 4);
	ListPrint(plist);


	// 双向链表清理但不销毁,保留头结点可以继续使用
	ListClear(plist);

	
	/*printf("%d\n", pos->data);*/

	ListPrint(plist);

	// 双向链表销毁
	ListDestory(&plist);


}


void TestDList2() 
{
	ListNode* plist = NULL;
	ListCreate(&plist);

	//尾插
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);

	//头删
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	//尾删
	/*ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);*/


	//尾插
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 3);

	// 双向链表删除pos位置的结点
	ListErase(pos);
	ListPrint(plist);


	// 双向链表销毁
	ListDestory(&plist);
}


int main()
{
	TestDList2();
	return 0;
}