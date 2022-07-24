/*
	����ʵ����ֱ�Ӳ��������۰���������ϣ������ֱ�Ӳ���������۰���������ʱ�临�ӶȾ�ΪO(n2)��ϣ��
	������n��һ����Χ��ʱ�临�Ӷ�ΪO(n1.3)���������򷽷���Ϊ�ȶ�������Ϊ��Ԫ�����ʱ�����ύ��λ�á� 
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
{// ��a[]Ӧ��ֱ�Ӳ�������
 // ���Ƚ���һ��Ԫ����Ϊ�������У����ν��ڶ������һ��Ԫ�ز����������С�
 	int i, j;
	 
	for(i=2;i<=SIZE;i++) // �ӵڶ���Ԫ�ؿ�ʼ 
	{
		a[0] = a[i]; // �ڱ���¼Ԫ��
		for(j=i-1;a[0]<a[j];j--) // �߱Ƚϱ��ƶ� 
		{
			a[j+1] = a[j];	
		}// for
		a[j+1] = a[0]; // ���� 
	}// for
	
	return OK; 
}// InsertSort()

Status InsertSort_BS(int a[])
{// ��a[]ʹ���۰��������
 /*
 	����˼�룺��Ϊֱ�Ӳ������򣬵�����λ�õĲ���ʹ�ö��ֲ��� 
 */ 
	int i, j;
	int low, high, mid;
	
	for(i=2;i<=SIZE;i++) // �ӵڶ������һ��Ԫ�� 
	{
		a[0] = a[i];
		// ���Ҳ���λ��
		low = 1;
		high = i-1;
		while(low<=high)
		{
			//  9 11 13 7
			//  1 2  3
			mid = (low + high) / 2;
			if(a[0]<a[mid])
			{
				high = mid - 1;
			}else
			{
				low = mid + 1;
			}// else
		}// while()
		
		// ����λ��֮��Ԫ�غ���
		for(j=i-1;j>=high+1;j--)
		{
			a[j+1] = a[j];
		}// for
		
		// ���� 
		a[high+1] = a[0]; 
	}// for
	
	return OK;
}// InsertSort_BS()

Status ShellSort(int a[])
{// ��a[]Ӧ��ϣ������
 /*
 	ѡȡĳ����С�������У��ȶ�ÿ�������н���ֱ�Ӳ������������������ֱ�Ӳ������� 
 */ 
	int dk, i, j, k;
	
	for(dk=SIZE/2;dk>=1;dk=dk/2) // ��С�������У�3,1
	{
		for(i=1;i<=dk;i++) // ��ÿ��������
		{
			for(j=i+dk;j<=SIZE;j+=dk) // ���ڶ������һ��Ԫ�ز��뵽����������
			{
				a[0] = a[j]; // ��¼Ԫ��
				for(k=j-dk;a[0]<a[k]&&k>0;k-=dk) // �߱Ƚϱ��ƶ� 
				{
					a[k+dk] = a[k];
				}// for
				a[k+dk] = a[0];
			}// for
		}// for	
	}// for 
	
	return OK;
}// ShellSort()


// ������
void main()
{
	int i;
	int a[SIZE+1] = {0, 13, 15, 17, 7, 5, 3, 1};
	if(ShellSort(a))
	{
		printf("ϣ������ɹ���\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
