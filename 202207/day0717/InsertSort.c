/*
	本代码实现三种插入排序：直接插入排序、折半插入排序和希尔排序。直接插入排序的时间复杂度为
	O(n2)，折半插入排序减少了比较此数，但交换次数未减少，故时间复杂度也为O(n2)。希尔排序在n处于
	某范围之内时时间复杂度为O(n1.3)。 
*/ 

#include<stdio.h>
#include<stdlib.h>
#define SIZE 7

// 函数状态
#define TRUE 1 // 逻辑1
#define FALSE 0 // 逻辑0
#define OK 1 // 程序运行无误
#define ERROR 0 // 程序运行有误
#define INFEASIBLE -1 
#define OVERFLOW -2 // 结果溢出
typedef int Status; // 函数状态类型
typedef int boolean; // 布尔类型

Status InsertSort(int a[])
{// 对a[]使用直接插入排序
	int i, j;
	
	for(i=2;i<=SIZE;i++) // 将第二到最后一个元素插入到已排好序的序列中
	{
		a[0] = a[i]; // 记录值
		for(j=i-1;a[0]<a[j];j--) // 边比较边交换 
		{
			a[j+1] = a[j];
		} // for
		a[j+1] = a[0]; // 将值填入正确位置 
	} // for
	
	return OK;
}// InsertSort()

Status InsertSort_BS(int a[])
{// 对a[]使用直接插入排序
 /*
 	插入位置查找采用二分法。 
 */ 
	int i, j;
	int low, high, mid;
	
	for(i=2;i<=SIZE;i++) // 将第二个数到最后一个数插入已排序的序列 
	{
		a[0] = a[i];
		low = 1;
		high = i-1;
		while(low<=high) // 使用二分法查找插入位置 
		{
			mid = (low + high) / 2;
			if(a[0]<a[mid])
			{
				high = mid - 1;
			}else 
			{
				low = mid + 1;
			}// else
		}// while
		for(j=i-1;j>=high+1;j--) // 腾出下标为high+1的位置
		{
			a[j+1] = a[j];
		}// for
		a[high+1] = a[0];
	}// for
	
	return OK;
}// InsertSort_BS()

Status ShellSort(int a[])
{// 对a[]使用希尔排序
 /*
 	基本思想：选取一缩小增量序列，将序列变为基本有序后，再对整个序列应用直接插入排序。 
 */ 
	int dk;
	int i, j, k;
	
	for(dk=SIZE/2;dk>=1;dk=dk/2) // 选取的缩小增量序列为3,1 
	{
		for(i=1;i<=dk;i++) // 增量大小=需要排序的子序列个数
		{
			for(j=i+dk;j<=SIZE;j+=dk) // 子序列从第二个到最后一个元素
			{
				a[0] = a[j]; // 记录元素
				for(k=j-dk;a[0]<a[k]&&k>=0;k-=dk) // 边比较边移动
				{
					a[k+dk] = a[k];	
				}// for
				a[k+dk] = a[0]; // 填入 
			}// for	
		}// for 
	}// for
	
	return OK;
}// ShellSort()

// 主函数
void main()
{
	int i;
	int a[SIZE+1] = {0, 13, 11, 9, 7, 5, 3, 1};	
	if(ShellSort(a))
	{
		printf("希尔排序完毕！\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
