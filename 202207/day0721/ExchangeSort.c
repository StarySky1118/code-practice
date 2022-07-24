/*
	����ʵ�������ֽ�������ð������Ϳ�������
	ð������ʱ�临�Ӷ�ΪO(n2)������Ԫ�����ʱ���ύ��Ԫ�أ��������ȽϹ����൱��ÿ��Ԫ�ؾ�
	�����˱Ƚϣ���ð���������ȶ�����
	��������ʱ�临�Ӷ�ΪO(nlog2n)�����������������ڲ������㷨��������õġ�����Ԫ��ֻ������
	���бȽϣ���˿��������Ƿ��ȶ����� 
*/

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
{// ������a[]Ӧ��ð������
 /*
 	����˼�룺�����һ��λ�õ��ڶ���λ�ã�ÿ����������Ԫ�ؽ��бȽϣ���С�򽻻���ÿ������
	��ʹ��ǰ��СԪ������������λ�á� 
 */ 
	int i, j;
	boolean flag; // �Ƿ���н����ı�־����ĳ������δ���н������������б��Ѿ����� 
	
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
{// ��a[]Ӧ�ÿ�������
 /*
 	����˼�룺ʹ�õݹ鷽ʽ�����Ƚ�������õ�����λ�ã��ٶ�����ǰ���к���������еݹ���á� 
 */ 
	int pivotpos; // ����λ�� 
	if(low<high) // �ݹ�������� 
	{
		pivotpos = partition(a, low, high);
		QuickSort(a, low, pivotpos-1);
		QuickSort(a, pivotpos+1, high);
	}// if
	return OK;
}// QuickSort()

int partition(int a[], int low, int high)
{// ������a[]���л��֣����������±�
	int pivot = a[low]; // ��¼����
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
