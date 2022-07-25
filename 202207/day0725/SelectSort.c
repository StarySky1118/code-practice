/*
	代码实现了堆排序。堆排序时间复杂度为O(nlog2n)，堆排序非常适合在大量数据中选取少量最大/最小的数据，
	因为维护一个小根堆/大根堆比对全体数据进行排序工作量小很多。堆排序不涉及元素两两相互比较，故是非稳
	定排序。 
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

Status BuildMaxHeap(int a[], int n)
{// 为数组a[]1~n项建立大根堆
 /*
 	基本思想：从n/2到1，调整以他为根子树为大根堆。 
 */ 
 	int i;
 	
 	for(i=n/2;i>=1;i--)
 	{
 		HeadMaxAdjust(a, i, n);	
	}// for
	
	return OK;	
}// BuildMaxHeap()

Status BuildMinHeap(int a[], int n)
{// 为数组a[]1~n建立小根堆
 /*
 	基本思想：从n/2到1，将每个结点为根结点的子树调整为小根堆。 
 */ 
	int i;
	
	for(i=n/2;i>=1;i--)
	{
		HeadMinAdjust(a, i, n);
	}// for
	
	return OK;
}// BuildMinHeap()

Status HeadMaxAdjust(int a[], int v, int n)
{// 调整a[]中以v为根的子树为大根堆
 /*
 	基本思想：若出现了孩子父结点交换，那么也需要再次调整换下的父结点为根的子树。 
 */ 
	int i;
	
	for(i=2*v;i<=n;i*=2)
	{
		if(i<n && a[i]<a[i+1]) // 定位孩子中较大者
			i++;
		if(a[v]>=a[i]) // 根结点更大，无需交换 
			break; 
		// 交换
		a[0] = a[v];
		a[v] = a[i];
		a[i] = a[0];
		v = i; // 下移 
	}// for
	
	return OK;
}// HeadMaxAdjust()

Status HeadMinAdjust(int a[], int v, int n)
{// 调整以数组a[]中以v为根的子树为小根堆
	int i;
	
	for(i=2*v;i<=n;i*=2)
	{
		if(i<n && a[i]>a[i+1]) // 选取孩子中较小者
			i++;
		if(a[i]>=a[v]) // 若根结点更小，无需交换 
			return;
		// 交换
		a[0] = a[v];
		a[v] = a[i];
		a[i] = a[0];
		v = i; // 下移 
	}// for
	
	return OK; 
}// HeadMinAdjust()

Status HeapSort_A(int a[], int n)
{// 对a[]1~n进行升序堆排序
	int i;
	
	if(!BuildMaxHeap(a, n)) // 建立大根堆
		return ERROR;
	for(i=n;i>1;i--)
	{
		// 交换
		a[0] = a[1];
		a[1] = a[i];
		a[i] = a[0];	
		
		// 调整
		HeadMaxAdjust(a, 1, i-1); 
	}// for
	
	return OK;
}// HeapSort_A()

Status HeapSort_D(int a[], int n)
{// 对a[]1~n进行降序堆排序
	int i;
	
	BuildMinHeap(a, n); // 建立小根堆
	for(i=n;i>1;i--)
	{
		// 交换
		a[0] = a[i];
		a[i] = a[1];
		a[1] = a[0];
		
		// 调整
		HeadMinAdjust(a, 1, i-1);	
	}// for
	
	return OK;
}// HeapSort_D()

Status Max(int a[], int n, int v)
{// 选取a[]1~n范围内最大的v个数放到a[]1~v范围内
 /*
 	基本思想：首先建立小根堆，依次扫描后面的元素，若比根大则替换根并重新进行调整。 
 */ 
 	int i;
 	
	if(v<1 || v>n) // 非法
		return ERROR;
	BuildMinHeap(a, v); // 建立小根堆 
	for(i=v+1;i<=n;i++)
	{
		if(a[i]>a[1]) // 元素比根结点更小
		{
			// 交换
			a[0] = a[i];
			a[i] = a[1];
			a[1] = a[0];
			
			// 调整
			HeadMinAdjust(a, 1, v); 
		}// if
	}// for
	
	return OK;
}// Max()

void main()
{
	int a[SIZE+1] = {0, 1, 3, 5, 7, 2, 4, 6};
	int i;
	
	if(Max(a, SIZE, 3))
	{
		printf("选取成功！\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);			
		}

	}
	
}
