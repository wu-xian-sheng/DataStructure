#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"






void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);    //初始化
	SeqListPushBack(&s, 1);    //尾插1
	SeqListPushBack(&s, 2);    //尾插2
	SeqListPushBack(&s, 3);    //尾插3
	SeqListPushBack(&s, 3);    //尾插3
	SeqListPushBack(&s, 3);    //尾插3
	SeqListPushBack(&s, 3);    //尾插3
	SeqListPushBack(&s, 3);    //尾插3
	SeqListPopBack(&s);        //尾删
	SeqListPopBack(&s);        //尾删
	SeqListPopBack(&s);       //尾删
	SeqListPopBack(&s);       //尾删
	SeqListPrint(&s);      //打印输出顺序表


	SeqListPushFront(&s, 6);      //头插6
	SeqListPushFront(&s, 7);      //头插7
	SeqListPushFront(&s, 8);      //头插8
	SeqListPrint(&s);      //打印输出顺序表

	SeqListPopFront(&s);      //头删
	SeqListPopFront(&s);      //头删
	SeqListPopFront(&s);      //头删
	SeqListPrint(&s);      //打印输出顺序表
	
	printf("%d\n", SeqListFind(&s, 2));     //找2在顺序表的位置


	SeqListInsert(&s, 1, 6);     //在下标为1的地方插入6
	SeqListPrint(&s);      //打印输出顺序表

	SeqListErase(&s, 2);    //删除顺序表下标为2的位置
	SeqListPrint(&s);       //打印输出顺序表

	SeqListPushBack(&s, 10);     //尾插10
	SeqListPushBack(&s, 4);      //尾插4
  	SeqListSort(&s);            //排序顺序表
	SeqListPrint(&s);      //打印输出顺序表
	printf("已找到！数组下标是%d\n", SeqBinarySearch(&s, 0, s.size - 1, 10));    //二分查找


	SeqListDestory(&s);  //销毁
}

int main()
{
	TestSeqList1();
	
	return 0;
}