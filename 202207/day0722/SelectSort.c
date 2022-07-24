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
 	基本思想：从第一个到倒数第二个位置，选择其后最大的元素进行交换。 
 */ 
 	int i, j;
 	int imax;
 
 	for(i=1;i<=SIZE-1;i++)
 	{	
 		imax = i;
 		for(j=i+1;j<=SIZE;j++)
		{
			if(a[j]>a[imax])
			{
				imax = j;	
			}
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

Status BuildMaxHeap(int a[])
{// 为数组a[]建立大根堆
 /*
 	基本思想：实质上是使用数组存储二叉树，从最后一个有孩子的结点开始调整到根结点。 
 */ 
	int i;
	for(i=SIZE/2;i>=1;i--)
	{
		HeadAdjust(a, i);
	}// for
	
	return OK;
}// BuildMaxHeap()

Status HeadAdjust(int a[], int v)
{// 调整父节点v及其孩子的位置
 /*
 	基本思想：找到v子结点中较大者，与v进行比较，大者与v交换。 
 */ 
 	int i; 
 	int imax; // 记录孩子中较大者坐标 
 	
	for(i=2*v;i<=SIZE;i++) // v的所有子结点 
	{
		if(a[i]>a[v])
		{
			imax = i;
		}
	}
	
}

// 主函数
void main()
{
	int i;
	int a[SIZE+1] = {0, 1, 3, 5, 7, 9, 11, 13};	
	if(SelectSort(a))
	{
		printf("选择排序成功！\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
