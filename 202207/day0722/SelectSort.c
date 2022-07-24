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

Status SelectSort(int a[])
{// ��a[]Ӧ��ѡ������
 /*
 	����˼�룺�ӵ�һ���������ڶ���λ�ã�ѡ���������Ԫ�ؽ��н����� 
 */ 
 	int i, j;
 	int imax;
 
 	for(i=1;i<=SIZE-1;i++)
 	{	
 		imax = i;
 		for(j=i+1;j<=SIZE;j++)
		{
			if(a[j]>a[imax])
			{
				imax = j;	
			}
		}// for
		if(i!=imax)
		{
			a[0] = a[imax];
			a[imax] = a[i];
			a[i] = a[0];	
		}// if
	}// for
	
	return OK; 
}// SelectSort()

Status BuildMaxHeap(int a[])
{// Ϊ����a[]���������
 /*
 	����˼�룺ʵ������ʹ������洢�������������һ���к��ӵĽ�㿪ʼ����������㡣 
 */ 
	int i;
	for(i=SIZE/2;i>=1;i--)
	{
		HeadAdjust(a, i);
	}// for
	
	return OK;
}// BuildMaxHeap()

Status HeadAdjust(int a[], int v)
{// �������ڵ�v���亢�ӵ�λ��
 /*
 	����˼�룺�ҵ�v�ӽ���нϴ��ߣ���v���бȽϣ�������v������ 
 */ 
 	int i; 
 	int imax; // ��¼�����нϴ������� 
 	
	for(i=2*v;i<=SIZE;i++) // v�������ӽ�� 
	{
		if(a[i]>a[v])
		{
			imax = i;
		}
	}
	
}

// ������
void main()
{
	int i;
	int a[SIZE+1] = {0, 1, 3, 5, 7, 9, 11, 13};	
	if(SelectSort(a))
	{
		printf("ѡ������ɹ���\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
