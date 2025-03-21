#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"






void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);    //��ʼ��
	SeqListPushBack(&s, 1);    //β��1
	SeqListPushBack(&s, 2);    //β��2
	SeqListPushBack(&s, 3);    //β��3
	SeqListPushBack(&s, 3);    //β��3
	SeqListPushBack(&s, 3);    //β��3
	SeqListPushBack(&s, 3);    //β��3
	SeqListPushBack(&s, 3);    //β��3
	SeqListPopBack(&s);        //βɾ
	SeqListPopBack(&s);        //βɾ
	SeqListPopBack(&s);       //βɾ
	SeqListPopBack(&s);       //βɾ
	SeqListPrint(&s);      //��ӡ���˳���


	SeqListPushFront(&s, 6);      //ͷ��6
	SeqListPushFront(&s, 7);      //ͷ��7
	SeqListPushFront(&s, 8);      //ͷ��8
	SeqListPrint(&s);      //��ӡ���˳���

	SeqListPopFront(&s);      //ͷɾ
	SeqListPopFront(&s);      //ͷɾ
	SeqListPopFront(&s);      //ͷɾ
	SeqListPrint(&s);      //��ӡ���˳���
	
	printf("%d\n", SeqListFind(&s, 2));     //��2��˳����λ��


	SeqListInsert(&s, 1, 6);     //���±�Ϊ1�ĵط�����6
	SeqListPrint(&s);      //��ӡ���˳���

	SeqListErase(&s, 2);    //ɾ��˳����±�Ϊ2��λ��
	SeqListPrint(&s);       //��ӡ���˳���

	SeqListPushBack(&s, 10);     //β��10
	SeqListPushBack(&s, 4);      //β��4
  	SeqListSort(&s);            //����˳���
	SeqListPrint(&s);      //��ӡ���˳���
	printf("���ҵ��������±���%d\n", SeqBinarySearch(&s, 0, s.size - 1, 10));    //���ֲ���


	SeqListDestory(&s);  //����
}

int main()
{
	TestSeqList1();
	
	return 0;
}