#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"


//ջ�ĳ�ʼ��
void StackInit(Stack* pst)
{
	assert(pst);
	//�������������������鷳
	/*pst->_a = NULL;
	pst->_top = 0;
	pst->_capacity = 0;*/

	pst->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
	pst->_top = 0;
	pst->_capacity = 4;
}

//ջ������
void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a); //�ͷſ��ٵĿռ�
	pst->_a = NULL;
	pst->_top = pst->_capacity = 0;
}

//��ջ
void StackPush(Stack* pst, STDataType x)
{
	//����Ƿ���Ҫ����
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

//��ջ
void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	//ֻ��Ҫ��topһ�ߣ����Բ��ó�ʼ����ջ��ֵ
	//pst->_a[pst->_top] = 0;
	pst->_top--;
}

//��ȡ���ݵĸ���
int StackSize(Stack* pst)   //���ǵ��ڴ��ͳһ��������������Ҳ��һ��ָ��
{
	assert(pst);
	return pst->_top;
}

//�пգ�1�ǿգ�0�Ƿǿ�
int StackEmpty(Stack* pst)
{
	assert(pst);
	//return pst->_top == 0 ? 1 : 0;
	return !pst->_top;
}

//��ȡջ������
STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top);

	return pst->_a[pst->_top-1];
}