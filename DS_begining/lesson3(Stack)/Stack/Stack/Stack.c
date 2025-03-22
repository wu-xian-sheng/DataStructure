#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"


//栈的初始化
void StackInit(Stack* pst)
{
	assert(pst);
	//这样会给后面扩容造成麻烦
	/*pst->_a = NULL;
	pst->_top = 0;
	pst->_capacity = 0;*/

	pst->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
	pst->_top = 0;
	pst->_capacity = 4;
}

//栈的销毁
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a); //释放开辟的空间
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}

//入栈
void StackPush(Stack* pst, STDataType x)
{
	//检查是否需要扩容
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (tmp == NULL)
		{
			perror("relloc");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}

	pst->_a[pst->_top] = x;
	pst->_top++;
}

//出栈
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	//只需要将top一走，可以不用初始化出栈的值
	//pst->_a[pst->_top] = 0;
	pst->_top--;
}

//获取数据的个数
int StackSize(Stack* pst)   //考虑到内存和统一性问题我们这里也传一级指针
{
	assert(pst);
	return pst->_top;
}

//判空，1是空，0是非空
int StackEmpty(Stack* pst)
{
	assert(pst);
	//return pst->_top == 0 ? 1 : 0;
	return !pst->_top;
}

//获取栈顶数据
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);

	return pst->_a[pst->_top-1];
}