#include<stdio.h>
#include<stdlib.h>
#define MAX_VEX_NUM 4 // ������������ 

// ����״̬
#define TRUE 1 // �߼�1
#define FALSE 0 // �߼�0
#define OK 1 // ������������
#define ERROR 0 // ������������
#define INFEASIBLE -1
#define OVERFLOW -2 // ������
typedef int Status; // ����״̬����
typedef int boolean; // �������� 


// ͼ���ڽӱ�洢��ʽ 
typedef struct EdgeNode
{// �߱��� 
	int adjvex; // ���ڽӵĽ��
	struct EdgeNode *nextEdge; // ��һ���� 
}EdgeNode;
typedef struct VexNode
{// ������ 
	int vextex; // �������
	EdgeNode *firstEdge; // ָ���һ���ߵ�ָ�� 
}VexNode;
typedef struct
{// ͼ
	VexNode* vex[MAX_VEX_NUM+1]; // ��������
	int vexnum; // ������� 
}ALGraph;

// �ڽӱ�ͼ��ز���
Status Example(ALGraph *G)
{// ���������ص�ͼG
 /*
 	����˼�룺���Ƚ��г�ʼ�������������0�����ж�����ָ�����ÿա�Ȼ��ͼ���ص����롣 
 */ 
	int i; // ѭ������ 
	G->vexnum = 4; // �������
	for(i=1;i<=MAX_VEX_NUM;i++) // ���ж�����ָ�����ÿ� 
	{
		G->vex[i]->firstEdge = NULL;
	}// for
	
	return OK;
	 
} 


void main()
{

}
