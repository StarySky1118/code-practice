/*
	������ʾ�����ֽ�������ð������Ϳ������򡣽���������ڽ�����ÿ������ĳ��Ԫ�ط�����������λ�á�
	ð������ʱ�临�Ӷ�ΪO(n2)������Ԫ��ֵ���ʱ������н��������ð���������ȶ�����
	���������������ڲ������㷨��ƽ���������ŵ��㷨��ʱ�临�Ӷ�O(nlog2n)�������������ȶ�������2,1,1��
	����λ��1,1,2�� 
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
{// ��a[]Ӧ��ð������
 /*
 	����˼�룺ð������ÿһ�˻Ὣ��ǰ�����е����/��СԪ�ط��õ�������λ�á� 
 */ 
 	int i, j;
 	boolean flag; // ��־�ڸ���ð�������Ƿ�����˽�������δ���н�����˵���Ѿ��������
	 
	for(i=SIZE;i>=2;i--) // ����󵽵ڶ���λ��
	{
		flag = FALSE;
		for(j=1;j<=SIZE-1;j++) // �����ȽϽ���
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
{// ��a[]Ӧ�ÿ�������
 /*
 	����˼�룺��������ÿһ�˻Ὣһ��Ԫ�ط�����������λ�á� 
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
{// ��a[]���л��֣�������������±�
	int pivot = a[low]; //��¼����Ԫ�� 
	while(low<high) // �ƶ�Ԫ�� 
	{
		while(a[high]>=pivot && low<high)// ��high����Ѱ���׸�С�������Ԫ��
		{
			high--;
		}// while
		a[low] = a[high];
		while(a[low]<=pivot && low<high) // ��low����Ѱ���׸����������Ԫ��
		{
			low++;
		}// while 
		a[high] = a[low];
	}// while 
	
	a[low] = pivot; // ��������
	return low; 	
}// partition()

void main()
{
	int i;
	int a[SIZE+1] = {0, 13, 11, 9, 7, 5, 3, 1};
	if(QuickSort(a, 1, SIZE))
	{
		printf("��������ɹ���\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
}
