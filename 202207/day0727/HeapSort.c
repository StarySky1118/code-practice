/*
	����ʵ���˶����򡣶������ʱ�临�Ӷ�ΪO(nlog2n)�����ڶ����򲻻������Ƚ�Ԫ��ֵ����˶�������
	���ȶ����򡣶�����ǳ��ʺ�Ѱ�Ҵ��������е����/��С������ֵ����ΪֻҪά��һ��С/����Ѽ��ɣ�
	����Ҫ��ȫ�����ݽ������� 
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
{// Ϊ����a[]1~n���������
	int i;
	
	for(i=n/2;i>=1;i--) // ��ÿ����������Ϊ�����
	{
		HeadMaxAdjust(a, i, n);	
	}// for
	
	return OK; 
}// BuildMaxHeap()

Status BuildMinHeap(int a[], int n)
{// Ϊ����a[]1~n����С����
	int i;
	
	for(i=n/2;i>=1;i--) // ����ÿ������ΪС����
	{
		HeadMinAdjust(a, i, n);	
	}// for
	
	return OK; 	
}// BuildMinHeap()

Status HeadMaxAdjust(int a[], int v, int n)
{// ������a[]����vΪ������������Ϊ����ѣ���������±�Ϊn
	int i;
	
	for(i=2*v;i<=n;i*=2)
	{
		if(i<n && a[i]<a[i+1]) // ѡȡ�����нϴ��� 
		{
			i++;	
		}// if
		if(a[v]>=a[i]) // ����㱾�����Ǵ��
		{
			break; // �����κβ���	
		}
		// ���� 
		a[0] = a[v];	
		a[v] = a[i];
		a[i] = a[0];
		v = i; // ����Ŀ�� 
	}// for 
	
	return OK;
}// HeadMaxAdjust()

Status HeadMinAdjust(int a[], int v, int n)
{// ����vΪ������������ΪС����
	int i;
	
	for(i=2*v;i<=n;i*=2)
	{
		if(i<n && a[i]>a[i+1]) // ѡȡ�����и�С�� 
			i++;	
		if(a[v]<=a[i]) // �������������С���ѣ����轻��
			break;	
		// ���� 
		a[0] = a[v];
		a[v] = a[i];
		a[i] = a[0];
		v = i; // ���� 
	}// for
	
	return OK; 
}// HeadMinAdjust()

Status HeapSort_D(int a[], int n)
{// ��a[]Ӧ�ý��������
	int i;
	
	if(!BuildMinHeap(a, n)) // ����С����
		return ERROR;
	for(i=n;i>1;i--)
	{
		// ����
		a[0] = a[1];
		a[1] = a[i];
		a[i] = a[0];
		// ����
		HeadMinAdjust(a, 1, i-1); 
	}// for
	 
	return OK;
}// HeapSort_D()

Status HeapSort_A(int a[], int n)
{// ��a[]�������������
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

Status Max(int a[], int v, int n)
{// ѡ��a[]����v���������ĸ���Ϊn 
	int i;
	
	if(v<1 || v>n) // �Ƿ����� 
		return ERROR; 
	if(!BuildMinHeap(a, v)) // ����С����
		return ERROR;
	for(i=v+1;i<=n;i++) // ɨ��������
	{
		if(a[i]>a[1]) // Ӧ�ò���
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

// ������ 
void main()
{
	int a[SIZE+1] = {0, 1, 3, 4, 2, 5, 6, 7}; 
	int i;
	
	if(Max(a, 3, SIZE))
	{
		printf("���ҳɹ���\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
}
