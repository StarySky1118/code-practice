/*
	代码实现了直接插入排序、折半插入排序和希尔排序。这三种排序都属于插入排序，插入排序的基本思想是不断将
	后面的元素插入到已排好序的序列之中。直接插入排序边比较边移动元素，折半插入排序首先使用折半查找，查找
	出元素应该插入的位置，再移动元素。当序列基本有序时，直接插入排序移动此数较少，因此首先对子序列应用直
	接插入排序，最后再对整体作直接插入排序，这样有助于降低时间复杂度，这就是希尔排序。
	直接插入排序和折半插入排序的时间复杂度为O(n2)，希尔排序时间复杂度可将至O(n1.3)。这三种排序方法都是稳
	定排序，因为若两元素相等，后面的元素不会交换到前面。  	
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
 /*
 	基本思想：不断将后面的元素插入已排序序列中。 
 */ 
 	int i, j;
 	
 	for(i=2;i<=SIZE;i++) // 从第二个元素开始
	{
		a[0] = a[i]; // 哨兵记录
		for(j=i-1;a[0]>a[j];j--) // 边比较边移动元素 
		{
			a[j+1] = a[j];
		}// for
		a[j+1] = a[0]; // 元素插入位置是a[j+1] 
	}// for
	
	return OK;
}// InsertSort()

Status InsertSort_BS(int a[])
{// 对a[]应用折半插入排序
 /*
 	基本思想：插入位置的查找采用折半查找。 
 */ 
	int i, j;
	int low, high, mid;
	
	for(i=2;i<=SIZE;i++) // 从第二个元素到最后一个元素
	{
		a[0] = a[i]; // 记录元素
		low = 1;
		high = i - 1;
		while(low<=high) // 查找元素插入位置 
		{
			mid = (high + low) / 2;
			if(a[0]>a[mid])
			{
				high = mid - 1;
			}else
			{
				low = mid + 1;
			}// else
		}// while
		for(j=i-1;j>=high+1;j--) // 移动元素
		{
			a[j+1] = a[j];	
		}// for 
		
		a[high+1] = a[0]; // 填入 
	}// for
	
	return OK; 
}// InsertSort_BS()

Status ShellSort(int a[])
{// 对a[]使用希尔排序
 /*
 	基本思想：选取某个缩小增量序列，对所有子序列应用直接插入排序，待基本有序时，对全体元素使用直接插入排序。 
 */
 	int dk; // 某个增量
	int i, j, k;
	
	for(dk=SIZE/2;dk>=1;dk=dk/2) // 增量序列为3,1
	{
		for(i=1;i<=dk;i++) // 对某增量的每个子序列使用直接插入排序
		{
			for(j=i+dk;j<=SIZE;j+=dk) // 从第二个元素到最后一个元素 
			{
				a[0] = a[j]; // 记录元素
				for(k=j-dk;a[0]>a[k]&&k>0;k-=dk) // 边比较边移动
				{
					a[k+dk] = a[k];
				}// for
				a[k+dk] = a[0]; // 插入位置a[k+dk] 
			}// for
		}// for
	}// for
	
	return OK; 
}// ShellSort()

// 主函数
void main()
{
	int a[SIZE+1] = {0, 1, 3, 5, 7, 9, 11, 13};
	int i;
	if(ShellSort(a))
	{
		printf("希尔排序完成!\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
