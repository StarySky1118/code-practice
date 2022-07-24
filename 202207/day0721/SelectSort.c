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
{// 对数组a[]应用选择排序
 /*
 	基本思想：从第一个到倒数第二个位置，选择其后最大的元素放置于此。 
 */ 
 	int i, j;
	int imax; // 记录i之后最大值下标 
 	
 	for(i=1;i<=SIZE-1;i++) // 从第一个到倒数第二个位置
	{
		imax = i;
		for(j=i;j<=SIZE;j++)
		{
			if(a[j]>a[imax])
			{
				imax = j;
			}// if
		}// for
		if(imax!=i) // 最大值下标非默认值进行交换 
		{
			a[0] = a[imax];
			a[imax] = a[i];
			a[i] = a[0];
		}// if
	}// for
	
	return OK;	
}// SelectSort()

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
