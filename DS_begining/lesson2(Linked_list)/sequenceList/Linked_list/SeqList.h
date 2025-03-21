#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//��̬˳���

//typedef int SLDataType;   //˳�����������
//
//#define N 10  //˳���Ĵ�С
//
//struct SeqList
//{
//	SLDataType a[N];  //��������
//	int size;         //��Ч���ݵĸ���
//};


//��̬���ݱ�

typedef int SLDataType;


typedef struct SeqList
{
	SLDataType* arr;
	size_t size;
	size_t capacity;
}SL, SeqList;


//������ݺ���
void SLCheckCapacity(SeqList* psl);
//��ӡ����
void SeqListPrint(SeqList* psl);
// ˳����ʼ��
void SeqListInit(SeqList* psl);
// ���ռ䣬������ˣ���������
void SLCheckCapacity(SeqList* psl);
// ˳���β��
void SeqListPushBack(SeqList* psl, SLDataType x);
// ˳���βɾ
void SeqListPopBack(SeqList* psl);
// ˳���ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);
// ˳���ͷɾ
void SeqListPopFront(SeqList* psl);
// ˳������
int SeqListFind(SeqList* psl, SLDataType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* psl, size_t pos);
// ˳�������
void SeqListDestory(SeqList* psl);
// ˳����ӡ
void SeqListPrint(SeqList* psl);

//˳��������
void SeqListSort(SeqList* psl);

//���ֲ��� 
int SeqBinarySearch(SeqList* psl, size_t left, size_t right, SLDataType x);