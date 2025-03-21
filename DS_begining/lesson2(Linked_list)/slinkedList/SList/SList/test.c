#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"


void TestSList1()
{
	//SListDataType* phead = NULL;
	//头指针
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	//尾删验证
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);

	//头插验证
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPrint(pList);

	//头删验证
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);

	//查找验证
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPrint(pList);
	SListNode* pos = SListFind(pList, 3);

	//修改验证
	SListUpdata(pos, 30);//我们将其改为30
	SListPrint(pList);


	//插入验证
	SListInsertAfter(pos, 40); //pos后插入40
	SListPrint(pList);

	SListEraseAfter(pos);   //删除pos后的节点
	SListPrint(pList);

	//销毁
    SListDestroy(pList);
}

int main()
{
	TestSList1();
	return 0;
}