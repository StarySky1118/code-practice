/*
	代码演示了两种交换排序：冒泡排序和快速排序。交换排序基于交换，每趟排序将某个元素放置于其最终位置。
	冒泡排序时间复杂度为O(n2)，由于元素值相等时不会进行交换，因此冒泡排序是稳定排序。
	快速排序是所有内部排序算法中平均性能最优的算法，时间复杂度O(nlog2n)。快速排序不是稳定排序。例2,1,1↑
	最终位置1,1,2。 
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

Status BubbleSort(int a[])
{// 对a[]应用冒泡排序
 /*
 	基本思想：冒泡排序每一趟会将当前序列中的最大/最小元素放置到其最终位置。 
 */ 
 	int i, j;
 	boolean flag; // 标志在该趟冒泡排序是否进行了交换，若未进行交换，说明已经排序完成
	 
	for(i=SIZE;i>=2;i--) // 从最后到第二个位置
	{
		flag = FALSE;
		for(j=1;j<=SIZE-1;j++) // 两两比较交换
		{
			if(a[j]>a[j+1])
			{
				a[0] = a[j];
				a[j] = a[j+1];
				a[j+1] = a[0];
				flag = TRUE;
			}// if
			if(flag==FALSE)
			{
				return OK;
			}// if
		}// for
	}// for 
	
	return OK;
	
}// BubbleSort()

Status QuickSort(int a[], int low, int high)
{// 对a[]应用快速排序
 /*
 	基本思想：快速排序每一趟会将一个元素放置于其最终位置。 
 */ 
 	int pivotpos; // 枢轴位置 
 	if(low<high) // 递归结束条件
	{
		pivotpos = partition(a, low, high);
		QuickSort(a, low, pivotpos-1);
		QuickSort(a, pivotpos+1, high);
	}// if
	return OK;
}// QuickSort()

int partition(int a[], int low, int high)
{// 对a[]进行划分，并返回枢轴的下标
	int pivot = a[low]; //记录枢轴元素 
	while(low<high) // 移动元素 
	{
		while(a[high]>=pivot && low<high)// 从high向左寻找首个小于枢轴的元素
		{
			high--;
		}// while
		a[low] = a[high];
		while(a[low]<=pivot && low<high) // 从low向右寻找首个大于枢轴的元素
		{
			low++;
		}// while 
		a[high] = a[low];
	}// while 
	
	a[low] = pivot; // 枢轴填入
	return low; 	
}// partition()

void main()
{
	int i;
	int a[SIZE+1] = {0, 13, 11, 9, 7, 5, 3, 1};
	if(QuickSort(a, 1, SIZE))
	{
		printf("快速排序成功！\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
}
