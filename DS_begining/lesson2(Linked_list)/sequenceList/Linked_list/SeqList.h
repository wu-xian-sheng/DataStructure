#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//静态顺序表

//typedef int SLDataType;   //顺序表数据类型
//
//#define N 10  //顺序表的大小
//
//struct SeqList
//{
//	SLDataType a[N];  //定长数组
//	int size;         //有效数据的个数
//};


//动态数据表

typedef int SLDataType;


typedef struct SeqList
{
	SLDataType* arr;
	size_t size;
	size_t capacity;
}SL, SeqList;


//检查扩容函数
void SLCheckCapacity(SeqList* psl);
//打印函数
void SeqListPrint(SeqList* psl);
// 顺序表初始化
void SeqListInit(SeqList* psl);
// 检查空间，如果满了，进行增容
void SLCheckCapacity(SeqList* psl);
// 顺序表尾插
void SeqListPushBack(SeqList* psl, SLDataType x);
// 顺序表尾删
void SeqListPopBack(SeqList* psl);
// 顺序表头插
void SeqListPushFront(SeqList* psl, SLDataType x);
// 顺序表头删
void SeqListPopFront(SeqList* psl);
// 顺序表查找
int SeqListFind(SeqList* psl, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos);
// 顺序表销毁
void SeqListDestory(SeqList* psl);
// 顺序表打印
void SeqListPrint(SeqList* psl);

//顺序表的排序
void SeqListSort(SeqList* psl);

//二分查找 
int SeqBinarySearch(SeqList* psl, size_t left, size_t right, SLDataType x);