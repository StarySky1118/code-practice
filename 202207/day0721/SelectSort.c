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
{// ������a[]Ӧ��ѡ������
 /*
 	����˼�룺�ӵ�һ���������ڶ���λ�ã�ѡ���������Ԫ�ط����ڴˡ� 
 */ 
 	int i, j;
	int imax; // ��¼i֮�����ֵ�±� 
 	
 	for(i=1;i<=SIZE-1;i++) // �ӵ�һ���������ڶ���λ��
	{
		imax = i;
		for(j=i;j<=SIZE;j++)
		{
			if(a[j]>a[imax])
			{
				imax = j;
			}// if
		}// for
		if(imax!=i) // ���ֵ�±��Ĭ��ֵ���н��� 
		{
			a[0] = a[imax];
			a[imax] = a[i];
			a[i] = a[0];
		}// if
	}// for
	
	return OK;	
}// SelectSort()

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
