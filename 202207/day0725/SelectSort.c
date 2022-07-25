/*
	����ʵ���˶����򡣶�����ʱ�临�Ӷ�ΪO(nlog2n)��������ǳ��ʺ��ڴ���������ѡȡ�������/��С�����ݣ�
	��Ϊά��һ��С����/����ѱȶ�ȫ�����ݽ�����������С�ܶࡣ�������漰Ԫ�������໥�Ƚϣ����Ƿ���
	������ 
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

Status BuildMaxHeap(int a[], int n)
{// Ϊ����a[]1~n��������
 /*
 	����˼�룺��n/2��1����������Ϊ������Ϊ����ѡ� 
 */ 
 	int i;
 	
 	for(i=n/2;i>=1;i--)
 	{
 		HeadMaxAdjust(a, i, n);	
	}// for
	
	return OK;	
}// BuildMaxHeap()

Status BuildMinHeap(int a[], int n)
{// Ϊ����a[]1~n����С����
 /*
 	����˼�룺��n/2��1����ÿ�����Ϊ��������������ΪС���ѡ� 
 */ 
	int i;
	
	for(i=n/2;i>=1;i--)
	{
		HeadMinAdjust(a, i, n);
	}// for
	
	return OK;
}// BuildMinHeap()

Status HeadMaxAdjust(int a[], int v, int n)
{// ����a[]����vΪ��������Ϊ�����
 /*
 	����˼�룺�������˺��Ӹ���㽻������ôҲ��Ҫ�ٴε������µĸ����Ϊ���������� 
 */ 
	int i;
	
	for(i=2*v;i<=n;i*=2)
	{
		if(i<n && a[i]<a[i+1]) // ��λ�����нϴ���
			i++;
		if(a[v]>=a[i]) // �����������轻�� 
			break; 
		// ����
		a[0] = a[v];
		a[v] = a[i];
		a[i] = a[0];
		v = i; // ���� 
	}// for
	
	return OK;
}// HeadMaxAdjust()

Status HeadMinAdjust(int a[], int v, int n)
{// ����������a[]����vΪ��������ΪС����
	int i;
	
	for(i=2*v;i<=n;i*=2)
	{
		if(i<n && a[i]>a[i+1]) // ѡȡ�����н�С��
			i++;
		if(a[i]>=a[v]) // ��������С�����轻�� 
			return;
		// ����
		a[0] = a[v];
		a[v] = a[i];
		a[i] = a[0];
		v = i; // ���� 
	}// for
	
	return OK; 
}// HeadMinAdjust()

Status HeapSort_A(int a[], int n)
{// ��a[]1~n�������������
	int i;
	
	if(!BuildMaxHeap(a, n)) // ���������
		return ERROR;
	for(i=n;i>1;i--)
	{
		// ����
		a[0] = a[1];
		a[1] = a[i];
		a[i] = a[0];	
		
		// ����
		HeadMaxAdjust(a, 1, i-1); 
	}// for
	
	return OK;
}// HeapSort_A()

Status HeapSort_D(int a[], int n)
{// ��a[]1~n���н��������
	int i;
	
	BuildMinHeap(a, n); // ����С����
	for(i=n;i>1;i--)
	{
		// ����
		a[0] = a[i];
		a[i] = a[1];
		a[1] = a[0];
		
		// ����
		HeadMinAdjust(a, 1, i-1);	
	}// for
	
	return OK;
}// HeapSort_D()

Status Max(int a[], int n, int v)
{// ѡȡa[]1~n��Χ������v�����ŵ�a[]1~v��Χ��
 /*
 	����˼�룺���Ƚ���С���ѣ�����ɨ������Ԫ�أ����ȸ������滻�������½��е����� 
 */ 
 	int i;
 	
	if(v<1 || v>n) // �Ƿ�
		return ERROR;
	BuildMinHeap(a, v); // ����С���� 
	for(i=v+1;i<=n;i++)
	{
		if(a[i]>a[1]) // Ԫ�رȸ�����С
		{
			// ����
			a[0] = a[i];
			a[i] = a[1];
			a[1] = a[0];
			
			// ����
			HeadMinAdjust(a, 1, v); 
		}// if
	}// for
	
	return OK;
}// Max()

void main()
{
	int a[SIZE+1] = {0, 1, 3, 5, 7, 2, 4, 6};
	int i;
	
	if(Max(a, SIZE, 3))
	{
		printf("ѡȡ�ɹ���\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);			
		}

	}
	
}
