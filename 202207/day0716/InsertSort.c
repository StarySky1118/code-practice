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
{// 对a[]进行直接插入排序
 /*
 	基本思想：从第二个数到最后一个数，进行如下循环：使用“哨兵”记录此数，从此数之前的数开始比较，若“哨兵”
	 更小，将遇到的数后移一位，最后将哨兵填入空余位置。 
 */ 
	int i, j;
 	for(i=2;i<=SIZE;i++)
 	{
 		a[0] = a[i]; // 使用哨兵记录此数
		for(j=i-1;a[0]<a[j];j--) // 前移 
		{
			a[j+1] = a[j];
		}// for
		a[j+1] = a[0]; // 填入	
	}// for
	return OK;
}// InsertSort()

Status InsertSort_BS(int a[])
{// 对a[]进行直接插入排序，元素插入位置的查找使用二分法。
	int low, high, mid;
	int i, j;
	
	for(i=2;i<=SIZE;i++) // 从第二个到最后一个元素 
	{
		a[0] = a[i];
		// 查找插入位置，插入位置即为high+1 
		low = 1;
		high = i-1;
		while(low<=high)
		{
			mid = (low + high) / 2;
			if(a[mid]<a[0])
			{
				low = mid + 1;
			}else 
			{
				high = mid - 1;
			}// else
		}// while
		
		// 插入位置后所有元素后移 
		for(j=i-1;j>=high+1;j--)
		{
			a[j+1] = a[j];
		}// for
		
		a[high+1] = a[0];
	}// for
	return OK;
}// InsertSort_BS()

Status ShellSort(int a[])
{// 对a[]进行希尔排序
 /*
 	基本思想：取缩小增量序列dk=SIZE/2,SIZE/4,.....1。对每个增量对应的子序列应用直接插入排序。 
 */ 
	int dk, i, j, k;
	
	for(dk=SIZE/2;dk>=1;dk=dk/2) // 缩小增量序列：3,1 
	{
		for(i=1;i<=dk;i++) // 需要排序的子序列个数也为dk
		{
			for(j=i+dk;j<=SIZE;j+=dk) // 从第二个元素到最后一个元素
			{
				a[0] = a[j]; // 记录元素
				for(k=j-dk;a[0]<a[k]&&k>=0;k-=dk)	
				{
					a[k+dk] = a[k];
				}// for
				a[k+dk] = a[0];
			}// for	
		} // for
	} //for
	
	return OK;
}// ShellSort()

// 主函数
void main()
{
	int i;
	int a[SIZE+1] = {0, 13, 11, 9, 7, 5, 3, 1};
	if(ShellSort(a))
	{
		printf("直接插入排序完毕！\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}// for
	}
	printf("\n");
} 
