/*
	代码实现了两种交换排序：冒泡排序和快速排序。
	冒泡排序时间复杂度为O(n2)，由于元素相等时不会交换元素，且整个比较过程相当于每个元素均
	进行了比较，故冒泡排序是稳定排序。
	快速排序时间复杂度为O(nlog2n)，快速排序是所有内部排序算法中性能最好的。由于元素只和枢轴
	进行比较，因此快速排序是非稳定排序。 
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
{// 对数组a[]应用冒泡排序
 /*
 	基本思想：从最后一个位置到第二个位置，每趟排序相邻元素进行比较，左小则交换。每趟排序
	可使当前最小元素置于其最终位置。 
 */ 
	int i, j;
	boolean flag; // 是否进行交换的标志，若某趟排序未进行交换，整个序列便已经有序。 
	
	for(i=SIZE;i>=2;i--)
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
		if(flag==FALSE)
		{
			return OK;
		}// if
	}// for
	
	return OK;
}// BubbleSort()

Status QuickSort(int a[], int low, int high)
{// 对a[]应用快速排序
 /*
 	基本思想：使用递归方式，首先将枢轴放置到最终位置，再对枢轴前序列和枢轴后序列递归调用。 
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
{// 对数组a[]进行划分，返回枢轴下标
	int pivot = a[low]; // 记录枢轴
	while(low<high)
	{
		while(a[high]<=pivot && low<high)
		{
			high--;
		}// while
		a[low] = a[high];
		while(a[low]>=pivot && low<high)
		{
			low++;
		}// while
		a[high] = a[low];
	}// while
	a[high] = pivot;
	
	return high;
}// partition()

// 主函数
void main()
{
	int i;
	int a[SIZE+1] = {0, 1, 3, 5, 7, 9, 11, 13};	
	if(QuickSort(a, 1, SIZE))
	{
		printf("冒泡排序完成!\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
