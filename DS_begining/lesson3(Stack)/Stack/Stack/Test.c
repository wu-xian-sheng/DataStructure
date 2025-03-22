#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

void Test1() {
	Stack st;
	StackInit(&st); //初始化
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	//遍历
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);   //出栈
	}
	printf("\n");

	printf("%d ", StackSize(&st)); //打印大小，已经全部出栈，size为0；
	StackDestory(&st);  //销毁
}

int main()
{
	Test1();
	return 0;
}