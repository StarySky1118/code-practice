/*
	����ʵ����ֱ�Ӳ��������۰���������ϣ�������������������ڲ������򣬲�������Ļ���˼���ǲ��Ͻ�
	�����Ԫ�ز��뵽���ź��������֮�С�ֱ�Ӳ�������߱Ƚϱ��ƶ�Ԫ�أ��۰������������ʹ���۰���ң�����
	��Ԫ��Ӧ�ò����λ�ã����ƶ�Ԫ�ء������л�������ʱ��ֱ�Ӳ��������ƶ��������٣�������ȶ�������Ӧ��ֱ
	�Ӳ�����������ٶ�������ֱ�Ӳ����������������ڽ���ʱ�临�Ӷȣ������ϣ������
	ֱ�Ӳ���������۰���������ʱ�临�Ӷ�ΪO(n2)��ϣ������ʱ�临�Ӷȿɽ���O(n1.3)�����������򷽷�������
	��������Ϊ����Ԫ����ȣ������Ԫ�ز��ύ����ǰ�档  	
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
 /*
 	����˼�룺���Ͻ������Ԫ�ز��������������С� 
 */ 
 	int i, j;
 	
 	for(i=2;i<=SIZE;i++) // �ӵڶ���Ԫ�ؿ�ʼ
	{
		a[0] = a[i]; // �ڱ���¼
		for(j=i-1;a[0]>a[j];j--) // �߱Ƚϱ��ƶ�Ԫ�� 
		{
			a[j+1] = a[j];
		}// for
		a[j+1] = a[0]; // Ԫ�ز���λ����a[j+1] 
	}// for
	
	return OK;
}// InsertSort()

Status InsertSort_BS(int a[])
{// ��a[]Ӧ���۰��������
 /*
 	����˼�룺����λ�õĲ��Ҳ����۰���ҡ� 
 */ 
	int i, j;
	int low, high, mid;
	
	for(i=2;i<=SIZE;i++) // �ӵڶ���Ԫ�ص����һ��Ԫ��
	{
		a[0] = a[i]; // ��¼Ԫ��
		low = 1;
		high = i - 1;
		while(low<=high) // ����Ԫ�ز���λ�� 
		{
			mid = (high + low) / 2;
			if(a[0]>a[mid])
			{
				high = mid - 1;
			}else
			{
				low = mid + 1;
			}// else
		}// while
		for(j=i-1;j>=high+1;j--) // �ƶ�Ԫ��
		{
			a[j+1] = a[j];	
		}// for 
		
		a[high+1] = a[0]; // ���� 
	}// for
	
	return OK; 
}// InsertSort_BS()

Status ShellSort(int a[])
{// ��a[]ʹ��ϣ������
 /*
 	����˼�룺ѡȡĳ����С�������У�������������Ӧ��ֱ�Ӳ������򣬴���������ʱ����ȫ��Ԫ��ʹ��ֱ�Ӳ������� 
 */
 	int dk; // ĳ������
	int i, j, k;
	
	for(dk=SIZE/2;dk>=1;dk=dk/2) // ��������Ϊ3,1
	{
		for(i=1;i<=dk;i++) // ��ĳ������ÿ��������ʹ��ֱ�Ӳ�������
		{
			for(j=i+dk;j<=SIZE;j+=dk) // �ӵڶ���Ԫ�ص����һ��Ԫ�� 
			{
				a[0] = a[j]; // ��¼Ԫ��
				for(k=j-dk;a[0]>a[k]&&k>0;k-=dk) // �߱Ƚϱ��ƶ�
				{
					a[k+dk] = a[k];
				}// for
				a[k+dk] = a[0]; // ����λ��a[k+dk] 
			}// for
		}// for
	}// for
	
	return OK; 
}// ShellSort()

// ������
void main()
{
	int a[SIZE+1] = {0, 1, 3, 5, 7, 9, 11, 13};
	int i;
	if(ShellSort(a))
	{
		printf("ϣ���������!\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
