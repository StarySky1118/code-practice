/*
	代码实现了选择排序中的简单选择排序和堆排序。选择排序基于选择与交换，简单选择排序每次选择其后最大/最小
	的元素与该位置元素交换，堆排序基于“通过选择孩子中较大/较小者并进行交换”这一机制进行排序。简单选择排序
	时间复杂度为O(n2)，由于简单选择排序并非任何两个元素均进行比较，故为不稳定排序。堆排序时间复杂度为O(log2n)
	非常适合大量数据中寻找最大/最小的若干元素，因为堆排序可以维持一个拥有若干元素的大根堆，而不需要对大量数据
	全部进行排序。堆排序非稳定排序。 
	 
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

Status SelectSort(int a[])
{// 对a[]应用选择排序
 /*
 	基本思想：从第一到倒数第二个位置，选择其后最大的元素交换。 
 */ 
	int i, j;
	int imax;
	
	for(i=1;i<=SIZE-1;i++)
	{
		imax = i;
		for(j=i;j<=SIZE;j++)
		{
			if(a[j]>a[imax])
				imax = j;
		}// for
		if(i!=imax)
		{
			a[0] = a[imax];
			a[imax] = a[i];
			a[i] = a[0];
		}// if
	}// for
	
	return OK; 
}// SelectSort()

Status BuildMaxHeap(int a[], int n)
{// 为数组a[]建立大根堆
 /*
 	基本思想：调整以SIZE/2到1为根的所有子树为大根堆。 
 */ 
 	int i;
 	
 	for(i=n/2;i>=1;i--)
 	{
 		HeadAdjust(a, i, n);	
	}// for
	
	return OK;
}// BuildMaxHeap()

Status HeadAdjust(int a[], int v, int n)
{// 调整v，使以v为根的子树为大根堆。
 /*
 	基本思想：首先将v的左右子树较大者与v进行比较，如果未进行交换，建立完成；如果进行了交换，
	仍需考虑将以交换孩子为根的子树转换为大根堆。 
 */ 
 
 	int i;
 	
	for(i=2*v;i<=n;i*=2)
	{
		a[0] = a[v];
		if(i<n && a[i]<a[i+1]) // 选取孩子中较大者
		{
			i++;	
		}// if
		if(a[0]>=a[i]) // 以v为根的树本身就是大根堆
		{
			break;
		}else { // 与孩子交换 
			a[v] = a[i];
			a[i] = a[0]; 
			v = i;
		}// else 
	}// for
	
	return OK;
}// HeadAdjust()

Status HeapSort(int a[], int n)
{// 对a[]应用堆排序
 /*
 	基本思想：对每一个元素，首先输出堆顶元素，与最后一个元素交换，重新调整堆。 
 */ 
	int i;
	
	BuildMaxHeap(a, SIZE);
	for(i=n;i>=1;i--)
	{
		printf("%d ", a[1]);
		if(i>1)
		{
			a[0] = a[1];
			a[1] = a[i];
			a[i] = a[0];
			HeadAdjust(a, 1, i-1);
		}
	}// for
	
	return OK;
}

void main()
{
	int a[SIZE+1] = {0, 1, 3, 5, 7, 2, 4, 6};
	int i;
	
}
