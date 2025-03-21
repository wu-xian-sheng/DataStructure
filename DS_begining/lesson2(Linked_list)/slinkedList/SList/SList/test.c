#define _CRT_SECURE_NO_WARNINGS

#include"SList.h"


void TestSList1()
{
	//SListDataType* phead = NULL;
	//ͷָ��
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(pList);

	//βɾ��֤
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);

	//ͷ����֤
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPrint(pList);

	//ͷɾ��֤
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(pList);

	//������֤
	SListPushFront(&pList, 1);
	SListPushFront(&pList, 2);
	SListPushFront(&pList, 3);
	SListPushFront(&pList, 4);
	SListPrint(pList);
	SListNode* pos = SListFind(pList, 3);

	//�޸���֤
	SListUpdata(pos, 30);//���ǽ����Ϊ30
	SListPrint(pList);


	//������֤
	SListInsertAfter(pos, 40); //pos�����40
	SListPrint(pList);

	SListEraseAfter(pos);   //ɾ��pos��Ľڵ�
	SListPrint(pList);

	//����
    SListDestroy(pList);
}

int main()
{
	TestSList1();
	return 0;
}