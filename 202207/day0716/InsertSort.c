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
{// ��a[]����ֱ�Ӳ�������
 /*
 	����˼�룺�ӵڶ����������һ��������������ѭ����ʹ�á��ڱ�����¼�������Ӵ���֮ǰ������ʼ�Ƚϣ������ڱ���
	 ��С����������������һλ������ڱ��������λ�á� 
 */ 
	int i, j;
 	for(i=2;i<=SIZE;i++)
 	{
 		a[0] = a[i]; // ʹ���ڱ���¼����
		for(j=i-1;a[0]<a[j];j--) // ǰ�� 
		{
			a[j+1] = a[j];
		}// for
		a[j+1] = a[0]; // ����	
	}// for
	return OK;
}// InsertSort()

Status InsertSort_BS(int a[])
{// ��a[]����ֱ�Ӳ�������Ԫ�ز���λ�õĲ���ʹ�ö��ַ���
	int low, high, mid;
	int i, j;
	
	for(i=2;i<=SIZE;i++) // �ӵڶ��������һ��Ԫ�� 
	{
		a[0] = a[i];
		// ���Ҳ���λ�ã�����λ�ü�Ϊhigh+1 
		low = 1;
		high = i-1;
		while(low<=high)
		{
			mid = (low + high) / 2;
			if(a[mid]<a[0])
			{
				low = mid + 1;
			}else 
			{
				high = mid - 1;
			}// else
		}// while
		
		// ����λ�ú�����Ԫ�غ��� 
		for(j=i-1;j>=high+1;j--)
		{
			a[j+1] = a[j];
		}// for
		
		a[high+1] = a[0];
	}// for
	return OK;
}// InsertSort_BS()

Status ShellSort(int a[])
{// ��a[]����ϣ������
 /*
 	����˼�룺ȡ��С��������dk=SIZE/2,SIZE/4,.....1����ÿ��������Ӧ��������Ӧ��ֱ�Ӳ������� 
 */ 
	int dk, i, j, k;
	
	for(dk=SIZE/2;dk>=1;dk=dk/2) // ��С�������У�3,1 
	{
		for(i=1;i<=dk;i++) // ��Ҫ����������и���ҲΪdk
		{
			for(j=i+dk;j<=SIZE;j+=dk) // �ӵڶ���Ԫ�ص����һ��Ԫ��
			{
				a[0] = a[j]; // ��¼Ԫ��
				for(k=j-dk;a[0]<a[k]&&k>=0;k-=dk)	
				{
					a[k+dk] = a[k];
				}// for
				a[k+dk] = a[0];
			}// for	
		} // for
	} //for
	
	return OK;
}// ShellSort()

// ������
void main()
{
	int i;
	int a[SIZE+1] = {0, 13, 11, 9, 7, 5, 3, 1};
	if(ShellSort(a))
	{
		printf("ֱ�Ӳ���������ϣ�\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}// for
	}
	printf("\n");
} 
