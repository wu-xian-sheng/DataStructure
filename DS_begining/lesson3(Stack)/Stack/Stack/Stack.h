#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;

//#define N 1000
//
////定长的静态栈
//typedef struct Stack
//{
//	STDataType a[N];
//	int _top; //栈顶
//}Stack;


// 支持动态增长的栈
typedef struct Stack
{
	STDataType* _a;
	int _top;  //栈顶指针
	int _capacity; //动态容量
}Stack;


//栈的初始化
void StackInit(Stack* pst);

//栈的销毁
void StackDestory(Stack* pst);

//入栈
void StackPush(Stack* pst, STDataType x);

//出栈
void StackPop(Stack* pst);

//获取数据的个数
int StackSize(Stack* pst);    //考虑到内存和统一性问题我们这里也传一级指针

//判空，1是空，0是非空
int StackEmpty(Stack* pst);

//获取栈顶数据
STDataType StackTop(Stack* pst);