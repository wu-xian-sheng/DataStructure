#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;

//#define N 1000
//
////�����ľ�̬ջ
//typedef struct Stack
//{
//	STDataType a[N];
//	int _top; //ջ��
//}Stack;


// ֧�ֶ�̬������ջ
typedef struct Stack
{
	STDataType* _a;
	int _top;  //ջ��ָ��
	int _capacity; //��̬����
}Stack;


//ջ�ĳ�ʼ��
void StackInit(Stack* pst);

//ջ������
void StackDestory(Stack* pst);

//��ջ
void StackPush(Stack* pst, STDataType x);

//��ջ
void StackPop(Stack* pst);

//��ȡ���ݵĸ���
int StackSize(Stack* pst);    //���ǵ��ڴ��ͳһ��������������Ҳ��һ��ָ��

//�пգ�1�ǿգ�0�Ƿǿ�
int StackEmpty(Stack* pst);

//��ȡջ������
STDataType StackTop(Stack* pst);