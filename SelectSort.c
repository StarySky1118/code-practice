/*
	����ʵ����ѡ�������еļ�ѡ������Ͷ�����ѡ���������ѡ���뽻������ѡ������ÿ��ѡ��������/��С
	��Ԫ�����λ��Ԫ�ؽ�������������ڡ�ͨ��ѡ�����нϴ�/��С�߲����н�������һ���ƽ������򡣼�ѡ������
	ʱ�临�Ӷ�ΪO(n2)�����ڼ�ѡ�����򲢷��κ�����Ԫ�ؾ����бȽϣ���Ϊ���ȶ����򡣶�����ʱ�临�Ӷ�ΪO(log2n)
	�ǳ��ʺϴ���������Ѱ�����/��С������Ԫ�أ���Ϊ���������ά��һ��ӵ������Ԫ�صĴ���ѣ�������Ҫ�Դ�������
	ȫ���������򡣶�������ȶ����� 
	 
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

Status SelectSort(int a[])
{// ��a[]Ӧ��ѡ������
 /*
 	����˼�룺�ӵ�һ�������ڶ���λ�ã�ѡ���������Ԫ�ؽ����� 
 */ 
	int i, j;
	int imax;
	
	for(i=1;i<=SIZE-1;i++)
	{
		imax = i;
		for(j=i;j<=SIZE;j++)
		{
			if(a[j]>a[imax])
				imax = j;
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

Status BuildMaxHeap(int a[], int n)
{// Ϊ����a[]���������
 /*
 	����˼�룺������SIZE/2��1Ϊ������������Ϊ����ѡ� 
 */ 
 	int i;
 	
 	for(i=n/2;i>=1;i--)
 	{
 		HeadAdjust(a, i, n);	
	}// for
	
	return OK;
}// BuildMaxHeap()

Status HeadAdjust(int a[], int v, int n)
{// ����v��ʹ��vΪ��������Ϊ����ѡ�
 /*
 	����˼�룺���Ƚ�v�����������ϴ�����v���бȽϣ����δ���н�����������ɣ���������˽�����
	���迼�ǽ��Խ�������Ϊ��������ת��Ϊ����ѡ� 
 */ 
 
 	int i;
 	
	for(i=2*v;i<=n;i*=2)
	{
		a[0] = a[v];
		if(i<n && a[i]<a[i+1]) // ѡȡ�����нϴ���
		{
			i++;	
		}// if
		if(a[0]>=a[i]) // ��vΪ������������Ǵ����
		{
			break;
		}else { // �뺢�ӽ��� 
			a[v] = a[i];
			a[i] = a[0]; 
			v = i;
		}// else 
	}// for
	
	return OK;
}// HeadAdjust()

Status HeapSort(int a[], int n)
{// ��a[]Ӧ�ö�����
 /*
 	����˼�룺��ÿһ��Ԫ�أ���������Ѷ�Ԫ�أ������һ��Ԫ�ؽ��������µ����ѡ� 
 */ 
	int i;
	
	BuildMaxHeap(a, SIZE);
	for(i=n;i>=1;i--)
	{
		printf("%d ", a[1]);
		if(i>1)
		{
			a[0] = a[1];
			a[1] = a[i];
			a[i] = a[0];
			HeadAdjust(a, 1, i-1);
		}
	}// for
	
	return OK;
}

void main()
{
	int a[SIZE+1] = {0, 1, 3, 5, 7, 2, 4, 6};
	int i;
	
}
