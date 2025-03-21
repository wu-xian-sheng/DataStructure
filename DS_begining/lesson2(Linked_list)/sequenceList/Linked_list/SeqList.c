#define _CRT_SECURE_NO_WARNINGS
#include "SeqList.h"



//��ӡ����
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
		exit(-1);   //�˳�����
	}
	s->size = 0;
	s->capacity = 4;
}


void SLCheckCapacity(SeqList* psl)
{
	assert(psl);
	// �������
	if (psl->size == psl->capacity)
	{
		// ���ٿռ�ʱע�⣬��capacity��ʼ��Ϊ 0 ʱ��ֱ����˵Ľ������ 0 ����
		// ����Ҫ���ж�һ��, ������Ҫ�� ����ռ��Ƿ�ɹ����жϣ�
		// ������ֱ�ӽ�����Ŀռ丳ֵ�� Ŀ�����飬�ȸ�һ�� ��ʱ����
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
	//���������Ҫ����
	//һ��������2��
	SLCheckCapacity(psl);
	psl->arr[psl->size] = x;
	psl->size++;
}


void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	//psl->arr[psl->size - 1] = 0;   //���Բ��ӣ�ûʲô����
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
			return i;  //���������±�
		}
	}

	return -1;  //û�ҵ�
}




//��posλ�ò���x
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl);
	assert(pos <= psl->size);
	SLCheckCapacity(psl);    //����ǰ�ȼ��һ������û��
	

	//���Ųλ��
	size_t end = psl->size;
	while (pos < end)
	{
		psl->arr[end] = psl->arr[end - 1];
		end--;
	}
	psl->arr[pos] = x;
	psl->size++;
}



// ˳���ɾ��posλ�õ�ֵ
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


// ˳�������
void SeqListDestory(SeqList* psl)
{
	if (psl != NULL)
	{
		free(psl->arr);
		psl->arr = NULL;
		psl->size = psl->capacity = 0;
	}
	
}




//˳��������
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


//���ֲ���
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
		return -1; //û�ҵ�
	}
}
