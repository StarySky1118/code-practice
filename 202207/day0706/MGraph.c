#include<stdio.h>
#include<stdlib.h>

#define MaxVexNum 4 // ������� 

// ����״̬����
#define TRUE 1 // �߼�1
#define FALSE 0 // �߼�0
#define OK 1 // ������������
#define ERROR 0 // ������������
#define INFEASIBLE -1 
#define OVERFLOW -2 // ������
typedef int Status; // ����״̬����
typedef int boolean; // �������� 

// �ڽӾ���洢�ṹ
typedef int Vextype; // ������ͣ�int
typedef int Edgetype; // �����ͣ�int
typedef struct
{
	Vextype Vex[MaxVexNum+1]; // �������
	Edgetype Edge[MaxVexNum+1][MaxVexNum+1]; // �ڽӾ���
	int vexnum, edgenum; // ����������� 
}MGraph;

// �ڽӾ�����ز��� 
Status InitGraph(MGraph *G)
{// ��ʼ��ͼG
	int i, j; // ѭ������
	for(i=1;i<=MaxVexNum;i++)
	{
		for(j=1;j<=MaxVexNum;j++)
		{
			G->Edge[i][j] = 0;
		}// for
	}// for
	return OK;
}// InitGraph()

Status Example(MGraph *G)
{// Ϊͼ���ذ���
	int i; // ѭ������
	for(i=1;i<=MaxVexNum;i++) // ������鸳ֵ 
	{
		G->Vex[i] = i; 	
	}// for
	
	// �߸�ֵ 
	G->Edge[1][2] = 1; 
	G->Edge[1][3] = 1;
	G->Edge[2][4] = 1;
	G->Edge[3][4] = 1;
	G->Edge[2][1] = 1; 
	G->Edge[3][1] = 1;
	G->Edge[4][2] = 1;
	G->Edge[4][3] = 1;
	
	G->vexnum = MaxVexNum;
	G->edgenum = 4;
	
	return OK;
}// Example()

Status GraphDisplay(MGraph G)
{// ���ͼG������Ϣ
	int i, j; // ѭ������
	printf("\n");
	printf("------------\n");
	printf("ͼ������Ϊ��%d\n", G.vexnum);
	printf("ͼ������Ϊ��%d\n", G.edgenum);
	printf("ͼ�н��Ϊ��\n");
	
	// ������ 
	for(i=1;i<=G.vexnum;i++)
	{
		printf("%d ", G.Vex[i]);
	}
	printf("\n");
	
	// ����ڽӾ���
	printf("ͼ���ڽӾ������£�\n");
	for(i=1;i<=G.vexnum;i++)
	{
		for(j=1;j<=G.vexnum;j++)
		{
			printf("%d ", G.Edge[i][j]);
		}// for
		printf("\n");
	}// for
	printf("------------\n");
	
	return OK; 
}// GraphDisplay()


// ������ 
void main()
{
	MGraph G;
	InitGraph(&G);
	if(Example(&G))
	{
		printf("ͼ�Ѿ���ʼ����ɣ�\n");
	}// if
	GraphDisplay(G);
}
