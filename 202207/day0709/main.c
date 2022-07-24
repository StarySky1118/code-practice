#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 4 // ��������4 

// ����״̬����
#define TRUE 1 // �߼�1
#define FALSE 0 // �߼�0
#define OK 1 // ������������
#define ERROR 0 // ������������
#define INFEASIBLE -1
#define OVERFLOW -2 // ������
typedef int Status; // ����״̬����
typedef int boolean; // �������� 

// ͼ���ڽӾ���洢�ṹ
typedef int VexType; // ������ͣ�int
typedef int EdgeType; // �����ͣ�int 
typedef struct 
{
	VexType vertex[MAX_VERTEX_NUM+1]; // �����Ϣ 
	EdgeType edge[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1]; // �ڽӾ���
	int vexnum;
}MGraph;

// ͼ����ز���
Status example(MGraph *G)
{// ���ذ�����ͼG
 /*
 	����˼�룺���Ƚ��ڵ���Ϣ��ֵ��Ȼ���ڽӾ���ֵ�����ı������ͱ����� 
 */ 
	int i, j; // ѭ������
	for(i=1;i<=MAX_VERTEX_NUM;i++) // ����Ӧ�ý��ڽӾ����ʼ�� 
	{
		for(j=1;j<=MAX_VERTEX_NUM;j++)
		{
			G->edge[i][j] = 0;
		}// for
	}// for
	
	// �����Ϣ
	G->vertex[1] = 1;
	G->vertex[2] = 2;
	G->vertex[3] = 3;
	G->vertex[4] = 4;
	
	// �ڽӾ���
	G->edge[1][2] = 1;
	G->edge[2][1] = 1;
	G->edge[1][3] = 1;
	G->edge[3][1] = 1;
	G->edge[2][4] = 1;
	G->edge[4][2] = 1;
	G->edge[3][4] = 1;
	G->edge[4][3] = 1;
	G->edge[2][3] = 1;
	G->edge[3][2] = 1;
	
	// ������ͱ���
	G->vexnum = MAX_VERTEX_NUM;
}// example()

int edgeNum(MGraph G)
{// ����ͼG�ı���
 /* 
	����˼�룺�����ڽӾ��������Ƿ�Χ��1�ĸ�����
*/ 
	int i=1, j=1; // ����ѭ������
	int count=0; // �������� 
	for(i=1;i<=MAX_VERTEX_NUM;i++) // �����ڽӾ���ÿһ�� 
	{
		for(j=1;j<=i;j++) // ÿһ�������Ƿ�Χ�ڵ�ÿ����
		{
			if(G.edge[i][j]==1)
			{
				count++;
			}// if
		}// for	
	} // for 
	return count; 	
}// edgeNum()

Status display(MGraph G)
{// ���ͼG��������Ϣ

	int i, j; // ѭ������ 
 	printf("ͼ�Ľ����Ϊ%d������Ϊ%d\n", G.vexnum, edgeNum(G));
 	
	 printf("���н����ϢΪ��\n");
 	for(i=1;i<=G.vexnum;i++) // ��������Ϣ 
 	{
 		printf("%d ", G.vertex[i]); 
	}// for
	printf("\n");
	
	printf("�ڽӾ������£�\n");
	printf("  ");
	for(i=1;i<=G.vexnum;i++)
	{
		printf("%d ", G.vertex[i]);
	}// for
	printf("\n");
	printf("  -------\n");
	for(i=1;i<=G.vexnum;i++)
	{
		printf("%d|", G.vertex[i]);
		for(j=1;j<=G.vexnum;j++)
		{
			printf("%d ", G.edge[i][j]);
		}// for
		printf("\n");
	}// for
	
	return 0;
}


// ������ 
int main(int argc, char *argv[]) {
	MGraph G;
	example(&G);
	display(G);
	return 0;
}// main 
