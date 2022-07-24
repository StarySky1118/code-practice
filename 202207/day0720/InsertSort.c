/*
	代码实现了直接插入排序、折半插入排序和希尔排序。直接插入排序和折半插入排序的时间复杂度均为O(n2)，希尔
	排序在n的一定范围内时间复杂度为O(n1.3)。三种排序方法均为稳定排序，因为两元素相等时并不会交换位置。 
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
{// 对a[]应用直接插入排序
 // 首先将第一个元素视为有序序列，依次将第二到最后一个元素插入有序序列。
 	int i, j;
	 
	for(i=2;i<=SIZE;i++) // 从第二个元素开始 
	{
		a[0] = a[i]; // 哨兵记录元素
		for(j=i-1;a[0]<a[j];j--) // 边比较边移动 
		{
			a[j+1] = a[j];	
		}// for
		a[j+1] = a[0]; // 填入 
	}// for
	
	return OK; 
}// InsertSort()

Status InsertSort_BS(int a[])
{// 对a[]使用折半插入排序
 /*
 	基本思想：仍为直接插入排序，但插入位置的查找使用二分查找 
 */ 
	int i, j;
	int low, high, mid;
	
	for(i=2;i<=SIZE;i++) // 从第二到最后一个元素 
	{
		a[0] = a[i];
		// 查找插入位置
		low = 1;
		high = i-1;
		while(low<=high)
		{
			//  9 11 13 7
			//  1 2  3
			mid = (low + high) / 2;
			if(a[0]<a[mid])
			{
				high = mid - 1;
			}else
			{
				low = mid + 1;
			}// else
		}// while()
		
		// 插入位置之后元素后移
		for(j=i-1;j>=high+1;j--)
		{
			a[j+1] = a[j];
		}// for
		
		// 填入 
		a[high+1] = a[0]; 
	}// for
	
	return OK;
}// InsertSort_BS()

Status ShellSort(int a[])
{// 对a[]应用希尔排序
 /*
 	选取某个缩小增量序列，先对每个子序列进行直接插入排序，最后对整体进行直接插入排序。 
 */ 
	int dk, i, j, k;
	
	for(dk=SIZE/2;dk>=1;dk=dk/2) // 缩小增量序列：3,1
	{
		for(i=1;i<=dk;i++) // 对每个子序列
		{
			for(j=i+dk;j<=SIZE;j+=dk) // 将第二到最后一个元素插入到有序序列中
			{
				a[0] = a[j]; // 记录元素
				for(k=j-dk;a[0]<a[k]&&k>0;k-=dk) // 边比较边移动 
				{
					a[k+dk] = a[k];
				}// for
				a[k+dk] = a[0];
			}// for
		}// for	
	}// for 
	
	return OK;
}// ShellSort()


// 主函数
void main()
{
	int i;
	int a[SIZE+1] = {0, 13, 15, 17, 7, 5, 3, 1};
	if(ShellSort(a))
	{
		printf("希尔排序成功！\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
