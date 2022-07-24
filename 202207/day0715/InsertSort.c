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
{// ��a����ֱ�Ӳ�������(����)
 /*
 	����˼�룺�ӵڶ��������һ�����ݣ���������ѭ������λ��Ԫ����Ҫ�����λ�ã�������λ�ú󵽸�Ԫ��֮ǰ
	 ����Ԫ�غ���һλ�����Ԫ�ز��롣 
 */ 
 	int i, j, k;
 	int temp;
	  
	for(i=2;i<=SIZE;i++)
	{
		if(a[i]<a[i-1]) // ֻ��a[i]��a[i-1]С������²���Ҫ����
		{
			a[0] = a[i]; // �ڱ���¼
			for(j=i-1;a[0]<a[j];j--)
			{
				a[j+1] = a[j];
			}
			a[j+1] = a[0];
		}// if 
	}// for
}// InsertSort()
void main()
{
	int a[SIZE+1] = {0, 13, 11, 9, 7, 5, 3, 1};
	int i;
	if(InsertSort(a))
	{
		printf("ֱ�Ӳ���������ϣ�");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}// for
		printf("\n");
	}// if
}
