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
{// 对a进行直接插入排序(升序)
 /*
 	基本思想：从第二个到最后一个数据，进行如下循环：定位该元素需要插入的位置，将插入位置后到该元素之前
	 所有元素后移一位，最后将元素插入。 
 */ 
 	int i, j, k;
 	int temp;
	  
	for(i=2;i<=SIZE;i++)
	{
		if(a[i]<a[i-1]) // 只有a[i]比a[i-1]小的情况下才需要插入
		{
			a[0] = a[i]; // 哨兵记录
			for(j=i-1;a[0]<a[j];j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = a[0];
		}// if 
	}// for
}// InsertSort()
void main()
{
	int a[SIZE+1] = {0, 13, 11, 9, 7, 5, 3, 1};
	int i;
	if(InsertSort(a))
	{
		printf("直接插入排序完毕！");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}// for
		printf("\n");
	}// if
}
