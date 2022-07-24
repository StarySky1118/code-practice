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
{// 对a[]使用冒泡排序
 /*
 	基本思想：从最后一个位置到第二个位置，每趟排序将某个元素放置到其最终位置。 
 */ 
	int i, j;
	boolean flag = FALSE;
	for(i=SIZE;i>=2;i--) // 从最后一个位置到第二个位置 
	{
		for(j=1;j<=i-1;j++)
		{
			if(a[j]<a[j+1]) // 左比右小 
			{
				a[0] = a[j+1];
				a[j+1] = a[j];
				a[j] = a[0];
				flag = TRUE;
			}// if
			if(!flag)
			{
				return OK;
			}
		}// for
	}// for
	
	return OK;
}// BubbleSort()

Status QuickSort(int a[], int low, int high)
{// 对a[]使用快速排序
 /*
 	基本思想：使用递归的方式，将a[low]元素填入正确位置后，再对前半段序列和后半段序列分别调用快速排序。 
 */ 
	int pivotpos;
	if(low<high) // 递归跳出条件
	{
		pivotpos = partition(a, low, high);
		QuickSort(a, low, pivotpos-1);
		QuickSort(a, pivotpos+1, high);
	}// if
	return OK;
}// QuickSort()

int partition(int a[], int low, int high)
{// 将a[low]填入正确的位置，并返回位置下标。
	int pivot = a[low];
	while(low<high)
	{
		while(a[high]<=pivot && low<high) // 从high开始找到首个大于pivot的元素 
		{
			high--;
		}// while
		a[low] = a[high];
		while(a[low]>=pivot && low<high) // 从low开始找到首个小于pivot的元素 
		{
			low++;
		}// while
		a[high] = a[low];
	}// if 
	a[low] = pivot; 
	return low;
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
