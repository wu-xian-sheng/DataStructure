//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>

//��ָoffer56����1�����������ֳ��ֵĴ���

//һ�����͵�����nums���������������֮�⣬�������鶼���������Σ���д�����ҳ�
//������ֻ����һ�ε����֣�Ҫ��ʱ�临�Ӷ���O(n),�ռ临�Ӷ���O(1)



//int* singleNumbers(int* nums, size_t numsSize, int* returnSize) {
//
//    int ret = 0;
//    int i = 0;
//
//    //���浥�����ֵ��������һ���ֵ
//    for (i = 0; i < numsSize; i++)
//    {
//        ret ^= nums[i];
//    }
//
//    int m = 0;
//    //�ӵ����λ�ҵ�ret�е�mλΪ1��λ��, Ϊ1���������һ�������������ͬ��
//    //
//    while (m < 32)
//    {
//        if (ret & (1 << m))
//        {
//            break;
//        }
//        else
//        {
//            m++;
//        }
//    }
//
//    int x = 0;//��¼�������ֵ���
//    int y = 0;//��¼�������ֵ���
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & (1 << m)) //&Ϊ1��Ϊһ�� ֱ��ȫ�����һ���¼��ֵ
//        {
//            x ^= nums[i];
//        }
//        else  //Ϊ0��Ϊһ��
//        {
//            y ^= nums[i];
//        }
//    }
//
//    int* retArr = malloc(2 * sizeof(int));
//
//    retArr[0] = x;
//    retArr[1] = y;
//    *returnSize = 2;
//
//    return retArr;
//}
//
//
//int main()
//{
//    int p = 0;
//    int arr[] = { 1,2,55,55,66,66 };
//    int* a = singleNumbers(arr, sizeof(arr) / sizeof(int), &p);
//
//    printf("%d ", a[0]);
//    printf("%d ", a[1]);
//    free(a);
//    a = NULL;
//    printf("%d ", p);
//	return 0;
//}

//���Ա�


