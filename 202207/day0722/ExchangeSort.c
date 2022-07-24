/*
	����ʵ�������ֽ�������ð������Ϳ������򡣽�������Ļ���˼����ÿ������ĳ��Ԫ�طŵ�������λ���ϡ�
	ð������ʱ�临�Ӷ�ΪO(n2)������Ԫ�������Ƚϣ����Ԫ�����λ�ò���ı䣬���ð���������ȶ�����
	��������ʱ�临�Ӷ�ΪO(nlog2n)�����������������ڲ������㷨��������õġ����������ǲ��ȶ��������㷨��
	��211��ԭ����ÿ������ֻ��������бȽϡ� 
	 
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

Status BubbleSort(int a[])
{// ��a[]Ӧ��ð������
 /*
 	����˼�룺�����һ��λ�õ��ڶ���λ�ã���ǰԪ�������Ƚ���С�򽻻��� 
 */ 
	int i, j;
	boolean flag; // �����Ƿ���н����ı�־ 
	
	for(i=SIZE;i>=2;i--) // �����һ��λ�õ��ڶ���λ��
	{
		flag = FALSE;
		for(j=1;j<=i-1;j++)
		{	
			if(a[j]<a[j+1])
			{
				a[0] = a[j];
				a[j] = a[j+1];
				a[j+1] = a[0];
				flag = TRUE;
			}// if
		}// for
		if(!flag) // ������δ���н���
		{
			return OK;	
		}// if 
	}// for
	
	return OK;
}// BubbleSort()

Status QuickSort(int a[], int low, int high)
{// ��a[]���±귶Χ�ڵ�����Ӧ�ÿ�������
 /*
 	����˼�룺ʹ�õݹ鷽ʽ�����׸�Ԫ����Ϊ������õ�����λ�ã��ٷֱ��������������ݹ���á� 
 */ 
	int pivotpos;
	
	if(low<high) // �ݹ��������
	{
		pivotpos = partition(a, low, high);
		QuickSort(a, low, pivotpos-1);
		QuickSort(a, pivotpos+1, high);	
	}// while 
	
	return OK;
}// QuickSort()

int partition(int a[], int low, int high)
{// ��a[]��һ�����֣������������±�
	a[0] = a[low]; // ��¼����Ԫ��
	while(low<high)
	{
		while(a[high]<=a[0] && low<high) // ��high��ʼ���׸�������Ԫ�ش��Ԫ�� 
	 	{
	 		high--;	
		}// while
		a[low] = a[high];
		while(a[low]>=a[0] && low<high) // ��low��ʼ����Ѱ���׸�������С��Ԫ��
		{
			low++;	
		}// while
		a[high] = a[low]; 
	}// while
	a[low] = a[0]; // ����
	
	return low; 	
}// partition()

// ������
void main()
{
	int a[SIZE+1] = {0, 1, 3, 5, 7, 9, 11, 13};
	int i;
	if(QuickSort(a, 1, SIZE))
	{
		printf("ð������ɹ���\n");
		for(i=1;i<=SIZE;i++)
		{
			printf("%d ", a[i]);
		}
	}
} 
