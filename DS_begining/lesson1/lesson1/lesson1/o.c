#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


long long Fib(int N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}



// 请计算一下Func1中++count语句总共执行了多少次？
void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			++count;
		}
	}

	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}
	int M = 10;
	while (M--)
	{
		++count;
	}

	printf("%d\n", count);
}
