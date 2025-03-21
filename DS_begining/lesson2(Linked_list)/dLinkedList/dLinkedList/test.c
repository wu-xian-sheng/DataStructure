#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

void TestDList1()
{
	ListNode* plist = NULL;
	ListCreate(&plist);

	//β��
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);

	

	//ͷ��
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPushFront(plist, 6);
	ListPushFront(plist, 7);
	ListPrint(plist);



	// ˫��������pos��ǰ����в���
	ListNode* pos = ListFind(plist,2);   //����ListFind�ҵ�Ŀ��ڵ�
	ListInsert(pos, 8);
	ListPrint(plist);



	//�޸�pos��ָ�ڵ��ֵ
	ListUpData(pos, 4);
	ListPrint(plist);


	// ˫����������������,����ͷ�����Լ���ʹ��
	ListClear(plist);

	
	/*printf("%d\n", pos->data);*/

	ListPrint(plist);

	// ˫����������
	ListDestory(&plist);


}


void TestDList2() 
{
	ListNode* plist = NULL;
	ListCreate(&plist);

	//β��
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);

	//ͷɾ
	ListPopFront(plist);
	ListPopFront(plist);
	ListPopFront(plist);
	ListPrint(plist);

	//βɾ
	/*ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);*/


	//β��
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 3);

	// ˫������ɾ��posλ�õĽ��
	ListErase(pos);
	ListPrint(plist);


	// ˫����������
	ListDestory(&plist);
}


int main()
{
	TestDList2();
	return 0;
}