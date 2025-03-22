#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

void Test1() {
	Stack st;
	StackInit(&st); //��ʼ��
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	//����
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);   //��ջ
	}
	printf("\n");

	printf("%d ", StackSize(&st)); //��ӡ��С���Ѿ�ȫ����ջ��sizeΪ0��
	StackDestory(&st);  //����
}

int main()
{
	Test1();
	return 0;
}