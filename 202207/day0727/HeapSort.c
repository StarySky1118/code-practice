/*
	代码实现了堆排序。堆排序的时间复杂度为O(nlog2n)。由于堆排序不会两两比较元素值，因此堆排序是
	非稳定排序。堆排序非常适合寻找大量数据中的最大/最小的若干值，因为只要维持一个小/大根堆即可，
	不需要对全体数据进行排序。 
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
{// 为数组a[]1~n建立大根堆
	int i;
	
	for(i=n/2;i>=1;i--) // 将每个子树调整为大根堆
	{
		HeadMaxAdjust(a, i, n);	
	}// for
	
	return OK; 
}// BuildMaxHeap()

Status BuildMinHeap(int a[], int n)
{// 为数组a[]1~n建立小根堆
	int i;
	
	for(i=n/2;i>=1;i--) // 调整每个子树为小根堆
	{
		HeadMinAdjust(a, i, n);	
	}// for
	
	return OK; 	
}// BuildMinHeap()

Status HeadMaxAdjust(int a[], int v, int n)
{// 将数组a[]中以v为根的子树调整为大根堆，数组最大下标为n
	int i;
	
	for(i=2*v;i<=n;i*=2)
	{
		if(i<n && a[i]<a[i+1]) // 选取孩子中较大者 
		{
			i++;	
		}// if
		if(a[v]>=a[i]) // 根结点本来就是大的
		{
			break; // 无需任何操作	
		}
		// 交换 
		a[0] = a[v];	
		a[v] = a[i];
		a[i] = a[0];
		v = i; // 下移目标 
	}// for 
	
	return OK;
}// HeadMaxAdjust()

Status HeadMinAdjust(int a[], int v, int n)
{// 将以v为根的子树调整为小根堆
	int i;
	
	for(i=2*v;i<=n;i*=2)
	{
		if(i<n && a[i]>a[i+1]) // 选取孩子中更小的 
			i++;	
		if(a[v]<=a[i]) // 该子树本身就是小根堆，无需交换
			break;	
		// 交换 
		a[0] = a[v];
		a[v] = a[i];
		a[i] = a[0];
		v = i; // 下移 
	}// for
	
	return OK; 
}// HeadMinAdjust()

Status HeapSort_D(int a[], int n)
{// 对a[]应用降序堆排序
	int i;
	
	if(!BuildMinHeap(a, n)) // 建立小根堆
		return ERROR;
	for(i=n;i>1;i--)
	{
		// 交换
		a[0] = a[1];
		a[1] = a[i];
		a[i] = a[0];
		// 调整
		HeadMinAdjust(a, 1, i-1); 
	}// for
	 
	return OK;
}// HeapSort_D()

Status HeapSort_A(int a[], int n)
{// 对a[]进行升序堆排序
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

Status Max(int a[], int v, int n)
{// 选出a[]最大的v个数，数的个数为n 
	int i;
	
	if(v<1 || v>n) // 非法输入 
		return ERROR; 
	if(!BuildMinHeap(a, v)) // 建立小根堆
		return ERROR;
	for(i=v+1;i<=n;i++) // 扫描后面的数
	{
		if(a[i]>a[1]) // 应该插入
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

// 主函数 
void main()
{
	int a[SIZE+1] = {0, 1, 3, 4, 2, 5, 6, 7}; 
	int i;
	
	if(Max(a, 3, SIZE))
	{
		printf("查找成功！\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
}
