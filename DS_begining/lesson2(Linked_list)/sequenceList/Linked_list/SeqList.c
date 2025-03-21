#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"



//打印函数
void SeqListPrint(SeqList* psl)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}



void SeqListInit(SeqList* s)
{
	/*s.size = 0;
	s.arr = NULL;
	s.capacity = 0;*/

	s->arr = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (s->arr == NULL)
	{
		perror("malloc");
		exit(-1);   //退出程序
	}
	s->size = 0;
	s->capacity = 4;
}


void SLCheckCapacity(SeqList* psl)
{
	assert(psl);
	// 检查容量
	if (psl->size == psl->capacity)
	{
		// 开辟空间时注意，当capacity初始化为 0 时，直接相乘的结果还是 0 ！！
		// 所以要先判断一下, 并且需要做 申请空间是否成功的判断，
		// 还不能直接将申请的空间赋值给 目标数组，先给一个 临时变量
		size_t newCapcity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->arr, newCapcity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
			//exit(-1);
			
		}
		psl->arr = tmp;
		psl->capacity = newCapcity;
	}
}

void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	//如果满了需要增容
	//一般我们增2倍
	SLCheckCapacity(psl);
	psl->arr[psl->size] = x;
	psl->size++;
}


void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	//psl->arr[psl->size - 1] = 0;   //可以不加，没什么意义
	psl->size--;
}


void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);
	SLCheckCapacity(psl);
	int end = (int)psl->size - 1;
	while (end >= 0)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}
	psl->arr[0] = x;
	psl->size++;
}


void SeqListPopFront(SeqList* psl)
{
	assert(psl);
	int start = 0;
	while (start < psl->size)
	{
		psl->arr[start] = psl->arr[start + 1];
		start++;
	}
	psl->size--;
}


int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == x)
		{
			return i;  //返回数组下标
		}
	}

	return -1;  //没找到
}




//在pos位置插入x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos <= psl->size);
	SLCheckCapacity(psl);    //插入前先检查一下满了没。
	

	//向后挪位置
	size_t end = psl->size;
	while (pos < end)
	{
		psl->arr[end] = psl->arr[end - 1];
		end--;
	}
	psl->arr[pos] = x;
	psl->size++;
}



// 顺序表删除pos位置的值
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);

	size_t end = --psl->size;
	while (pos < end)
	{
		psl->arr[pos] = psl->arr[pos + 1];
		end--;
	}
}


// 顺序表销毁
void SeqListDestory(SeqList* psl)
{
	if (psl != NULL)
	{
		free(psl->arr);
		psl->arr = NULL;
		psl->size = psl->capacity = 0;
	}
	
}




//顺序表的排序
void SeqListSort(SeqList* psl)
{
	if (psl->size < 2) return;
	bool swapped = false;
	for (int i = 0; i < psl->size - 1; i++)
	{
		for (int j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->arr[j] > psl->arr[j + 1])
			{
				int temp = psl->arr[j];
				psl->arr[j] = psl->arr[j + 1];
				psl->arr[j + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}


//二分查找
int SeqBinarySearch(SeqList* psl, size_t left, size_t right, SLDataType x)
{
	size_t mid = 0;
	size_t find = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (psl->arr[mid] > x)
		{
			right = mid - 1;
		}
		else if (psl->arr[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			find = 1;
			break;
		}
	}
	if (1 == find)
	{
		return mid;
	}
	else
	{
		return -1; //没找到
	}
}
