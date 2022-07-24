/*
	������ʵ�����ֲ�������ֱ�Ӳ��������۰���������ϣ������ֱ�Ӳ��������ʱ�临�Ӷ�Ϊ
	O(n2)���۰������������˱Ƚϴ���������������δ���٣���ʱ�临�Ӷ�ҲΪO(n2)��ϣ��������n����
	ĳ��Χ֮��ʱʱ�临�Ӷ�ΪO(n1.3)�� 
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

Status InsertSort(int a[])
{// ��a[]ʹ��ֱ�Ӳ�������
	int i, j;
	
	for(i=2;i<=SIZE;i++) // ���ڶ������һ��Ԫ�ز��뵽���ź����������
	{
		a[0] = a[i]; // ��¼ֵ
		for(j=i-1;a[0]<a[j];j--) // �߱Ƚϱ߽��� 
		{
			a[j+1] = a[j];
		} // for
		a[j+1] = a[0]; // ��ֵ������ȷλ�� 
	} // for
	
	return OK;
}// InsertSort()

Status InsertSort_BS(int a[])
{// ��a[]ʹ��ֱ�Ӳ�������
 /*
 	����λ�ò��Ҳ��ö��ַ��� 
 */ 
	int i, j;
	int low, high, mid;
	
	for(i=2;i<=SIZE;i++) // ���ڶ����������һ������������������� 
	{
		a[0] = a[i];
		low = 1;
		high = i-1;
		while(low<=high) // ʹ�ö��ַ����Ҳ���λ�� 
		{
			mid = (low + high) / 2;
			if(a[0]<a[mid])
			{
				high = mid - 1;
			}else 
			{
				low = mid + 1;
			}// else
		}// while
		for(j=i-1;j>=high+1;j--) // �ڳ��±�Ϊhigh+1��λ��
		{
			a[j+1] = a[j];
		}// for
		a[high+1] = a[0];
	}// for
	
	return OK;
}// InsertSort_BS()

Status ShellSort(int a[])
{// ��a[]ʹ��ϣ������
 /*
 	����˼�룺ѡȡһ��С�������У������б�Ϊ����������ٶ���������Ӧ��ֱ�Ӳ������� 
 */ 
	int dk;
	int i, j, k;
	
	for(dk=SIZE/2;dk>=1;dk=dk/2) // ѡȡ����С��������Ϊ3,1 
	{
		for(i=1;i<=dk;i++) // ������С=��Ҫ����������и���
		{
			for(j=i+dk;j<=SIZE;j+=dk) // �����дӵڶ��������һ��Ԫ��
			{
				a[0] = a[j]; // ��¼Ԫ��
				for(k=j-dk;a[0]<a[k]&&k>=0;k-=dk) // �߱Ƚϱ��ƶ�
				{
					a[k+dk] = a[k];	
				}// for
				a[k+dk] = a[0]; // ���� 
			}// for	
		}// for 
	}// for
	
	return OK;
}// ShellSort()

// ������
void main()
{
	int i;
	int a[SIZE+1] = {0, 13, 11, 9, 7, 5, 3, 1};	
	if(ShellSort(a))
	{
		printf("ϣ��������ϣ�\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
