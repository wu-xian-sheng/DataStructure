//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>

//剑指offer56——1，数组中数字出现的次数

//一个整型的数组nums里除了有两个数组之外，其他数组都出现了两次，请写程序找出
//这两个只出现一次的数字，要求时间复杂度是O(n),空间复杂度是O(1)



//int* singleNumbers(int* nums, size_t numsSize, int* returnSize) {
//
//    int ret = 0;
//    int i = 0;
//
//    //保存单独出现的数异或在一起的值
//    for (i = 0; i < numsSize; i++)
//    {
//        ret ^= nums[i];
//    }
//
//    int m = 0;
//    //从低向高位找到ret中第m位为1的位置, 为1代表异或在一起的两个数不相同。
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
//    int x = 0;//记录单独出现的数
//    int y = 0;//记录单独出现的数
//    for (i = 0; i < numsSize; i++)
//    {
//        if (nums[i] & (1 << m)) //&为1的为一组 直接全部异或到一起记录其值
//        {
//            x ^= nums[i];
//        }
//        else  //为0的为一组
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

//线性表


