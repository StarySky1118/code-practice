#include<stdio.h>
#include<stdlib.h>
#define SIZE 7

// ����״̬
#define TRUE 1 // �߼�1
#define FALSE 0 // �߼�0
#define OK 1 // ������������
#define ERROR 0 // ������������
#define INFEASIBLE -1 
#define OVERFLOW -2 // ������
typedef int Status; // ����״̬����
typedef int boolean; // ��������

Status BubbleSort(int a[])
{// ��a[]ʹ��ð������
 /*
 	����˼�룺�����һ��λ�õ��ڶ���λ�ã�ÿ������ĳ��Ԫ�ط��õ�������λ�á� 
 */ 
	int i, j;
	boolean flag = FALSE;
	for(i=SIZE;i>=2;i--) // �����һ��λ�õ��ڶ���λ�� 
	{
		for(j=1;j<=i-1;j++)
		{
			if(a[j]<a[j+1]) // �����С 
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
{// ��a[]ʹ�ÿ�������
 /*
 	����˼�룺ʹ�õݹ�ķ�ʽ����a[low]Ԫ��������ȷλ�ú��ٶ�ǰ������кͺ������зֱ���ÿ������� 
 */ 
	int pivotpos;
	if(low<high) // �ݹ���������
	{
		pivotpos = partition(a, low, high);
		QuickSort(a, low, pivotpos-1);
		QuickSort(a, pivotpos+1, high);
	}// if
	return OK;
}// QuickSort()

int partition(int a[], int low, int high)
{// ��a[low]������ȷ��λ�ã�������λ���±ꡣ
	int pivot = a[low];
	while(low<high)
	{
		while(a[high]<=pivot && low<high) // ��high��ʼ�ҵ��׸�����pivot��Ԫ�� 
		{
			high--;
		}// while
		a[low] = a[high];
		while(a[low]>=pivot && low<high) // ��low��ʼ�ҵ��׸�С��pivot��Ԫ�� 
		{
			low++;
		}// while
		a[high] = a[low];
	}// if 
	a[low] = pivot; 
	return low;
}// partition()

// ������
void main()
{
	int i;
	int a[SIZE+1] = {0, 1, 3, 5, 7, 9, 11, 13};
	if(QuickSort(a, 1, SIZE))
	{
		printf("ð���������!\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
