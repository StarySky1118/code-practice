/*
	代码实现了两种交换排序：冒泡排序和快速排序。交换排序的基本思想是每趟排序将某个元素放到其最终位置上。
	冒泡排序时间复杂度为O(n2)，由于元素两两比较，相等元素相对位置不会改变，因此冒泡排序是稳定排序。
	快速排序时间复杂度为O(nlog2n)，快速排序是所有内部排序算法中性能最好的。快速排序是不稳定的排序算法，
	例211。原因是每趟排序只和枢轴进行比较。 
	 
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
 	基本思想：从最后一个位置到第二个位置，其前元素两两比较左小则交换。 
 */ 
	int i, j;
	boolean flag; // 本趟是否进行交换的标志 
	
	for(i=SIZE;i>=2;i--) // 从最后一个位置到第二个位置
	{
		flag = FALSE;
		for(j=1;j<=i-1;j++)
		{	
			if(a[j]<a[j+1])
			{
				a[0] = a[j];
				a[j] = a[j+1];
				a[j+1] = a[0];
				flag = TRUE;
			}// if
		}// for
		if(!flag) // 若本趟未进行交换
		{
			return OK;	
		}// if 
	}// for
	
	return OK;
}// BubbleSort()

Status QuickSort(int a[], int low, int high)
{// 对a[]上下标范围内的数组应用快速排序
 /*
 	基本思想：使用递归方式，将首个元素作为枢轴放置到合适位置，再分别对枢轴左右两侧递归调用。 
 */ 
	int pivotpos;
	
	if(low<high) // 递归结束条件
	{
		pivotpos = partition(a, low, high);
		QuickSort(a, low, pivotpos-1);
		QuickSort(a, pivotpos+1, high);	
	}// while 
	
	return OK;
}// QuickSort()

int partition(int a[], int low, int high)
{// 对a[]作一个划分，并返回枢轴下标
	a[0] = a[low]; // 记录枢轴元素
	while(low<high)
	{
		while(a[high]<=a[0] && low<high) // 从high开始找首个比枢轴元素大的元素 
	 	{
	 		high--;	
		}// while
		a[low] = a[high];
		while(a[low]>=a[0] && low<high) // 从low开始向右寻找首个比枢轴小的元素
		{
			low++;	
		}// while
		a[high] = a[low]; 
	}// while
	a[low] = a[0]; // 填入
	
	return low; 	
}// partition()

// 主函数
void main()
{
	int a[SIZE+1] = {0, 1, 3, 5, 7, 9, 11, 13};
	int i;
	if(QuickSort(a, 1, SIZE))
	{
		printf("冒泡排序成功！\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
