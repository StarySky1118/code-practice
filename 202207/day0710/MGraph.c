#include<stdio.h>
#include<stdlib.h>

#define MAX_VEX_NUM 4 // �������� 

// ����״̬����
#define TRUE 1 // �߼�1
#define FALSE 0 // �߼�0
#define OK 1 // ������������
#define ERROR 0 // ������������
#define INFEASIBLE -1
#define OVERFLOW -2 // ������
typedef int Status; // ����״̬����
typedef int boolean; // ��������

typedef int vexType; // ������ͣ�int
typedef int edgeType; // ������:int  

// ͼ���ڽӾ���洢�ṹ
typedef struct
{// �ṹ�ڰ�������㼯���ڽӾ���ͽ����� 
	vexType vertex[MAX_VEX_NUM+1]; // ��㼯
	edgeType edge[MAX_VEX_NUM+1][MAX_VEX_NUM+1]; // �߼�
	int vexnum; // ������ 
}MGraph;

// ͼ�ĸ������ݽ�����������
typedef vexType AElem; // ���������ͣ�vexType

// ���и������ݽṹ�洢����
typedef struct QNode 
{// ���н�� 
	AElem data; // ������
	struct QNode* next; // ָ����  
}QNode;
typedef struct
{// ���� 
	QNode *front, *rear; // ���ס���βָ�� 
}linkQueue;

// ���и������ݽṹ��ز��� 
Status InitQueue(linkQueue *Q)
{// ��ʼ������Q
 /*
 	����˼�룺�½���ͷ��㣬�ö��׺Ͷ�βָ���ָ��˽�㡣 
 */ 
	QNode *s = NULL; // ����ָ��
	s = (QNode*)malloc(sizeof(QNode)); // �½����
	s->data = 0;
	s->next = NULL;
	Q->front = s;
	Q->rear = s;
	return OK; 
}// InitQueue()

boolean QueueIsEmpty(linkQueue Q)
{// �ж϶���Q�Ƿ�Ϊ��
	if(Q.front==Q.rear)
		return TRUE;
	return FALSE;
}// QueueIsEmpty()

Status QueueDisplay(linkQueue Q)
{// ���ӻ��������Q���н���������
	QNode *p=Q.front->next; // ����ָ��
	printf("||");
	while(p!=NULL)
	{
		printf("%d ", p->data);	
		p = p->next;
	}// while 
	printf("\n");
	return OK;
}// QueueDisplay()

Status EnQueue(linkQueue *Q, AElem x)
{// ������Ԫ��x�������Q
/*
	����˼�룺�½���㲢��β�巨��ʽ������С� 
*/ 
	QNode *s=NULL; // ����ָ��
	s = (QNode*)malloc(sizeof(QNode)); // �½����
	s->data = x;
	s->next = Q->rear->next; // ������� 
	Q->rear->next = s;
	Q->rear = s; // ��βָ�����
	return OK; 
}// EnQueue()

Status GetHead(linkQueue Q, AElem *x)
{// ��ȡ����Q����Ԫ��
	if(Q.front->next==NULL) // ����Ϊ��
		return ERROR;
	*x = Q.front->next->data; // ��ȡ����Ԫ��
	return OK; 
}// GetHead()

Status DeQueue(linkQueue *Q, AElem *x)
{// ����
 /*
	����˼�룺���Ƚ��׸�����߼�ɾ�������ж϶�βָ���Ƿ�Ҳָ��˽�㡣 
 */ 
	QNode *s = Q->front->next; // ָ���ɾ�����
	if(s==NULL) // ����Ϊ��
		return ERROR;
	*x = s->data; // ȡֵ
	Q->front->next = s->next; // �߼�ɾ��
	if(s==Q->rear) // ��βָ��Ҳָ��˽��
	{
		Q->rear = Q->front; // ��βָ��ָ���ͷ��� 
	} // if
	free(s); // ����ɾ��s
	return OK;  
}// DeQueue()

// ͼ�Ļ�������
Status example(MGraph *G)
{// ���������ص�ͼG
 /*
 	����˼�룺���ȳ�ʼ��ͼG�������㼯��������������ȷֵ���ڽӾ����ʼ�������Ȼ��
	������ȷ���� 
 */
	int i, j; // ѭ������
	G->vexnum = MAX_VEX_NUM;
	G->vertex[1] = 1;
	G->vertex[2] = 2;
	G->vertex[3] = 3;
	G->vertex[4] = 4;
	
	for(i=1;i<=MAX_VEX_NUM;i++) // �ڽӾ����ʼ�� 
	{
		for(j=1;j<=MAX_VEX_NUM;j++)
		{
			G->edge[i][j] = 0;
		} // for
	}// for
	
	G->edge[1][3] = 1;
	G->edge[3][1] = 1;
	G->edge[1][2] = 1;
	G->edge[2][1] = 1;
	G->edge[2][4] = 1;
	G->edge[4][2] = 1;
	G->edge[3][4] = 1;
	G->edge[4][3] = 1;
	G->edge[1][4] = 1;
	G->edge[4][1] = 1;
	
	return OK;	
} // example()

int edgeNum(MGraph G)
{// ���G�ı���
 /*
 	����˼�룺ֻ���ڽӾ�����������1�ĸ����� 
 */ 
	int i, j;
	int count = 0;
	
	for(i=1;i<=MAX_VEX_NUM;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(G.edge[i][j]==1)
			{
				count++;
			}// if
		}// for
	}// for
	
	return count;
}// edgeNum()

Status display(MGraph G)
{// ���ͼG��������Ϣ

	int i, j;
	
	// ������н����Ϣ
	printf("ͼ�����н��Ϊ��\n");
	for(i=1;i<=MAX_VEX_NUM;i++)
	{
		printf("%d ", G.vertex[i]);
	}// for
	printf("\n");
	
	// ��������ͽ����
	printf("ͼ�н������Ϊ%d,ͼ�б���Ϊ%d\n", G.vexnum, edgeNum(G));
	
	// ����ڽӾ���
	printf("ͼ�ڽӾ������£�\n");
	printf("  ");
	for(i=1;i<=MAX_VEX_NUM;i++)
	{
		printf("%d ", G.vertex[i]);
	}// for
	printf("\n");
	printf("  ");
	for(i=1;i<=MAX_VEX_NUM;i++)
	{
		printf("--");
	}// for
	printf("\n");
	for(i=1;i<=MAX_VEX_NUM;i++)
	{
		printf("%d|", G.vertex[i]);
		for(j=1;j<=MAX_VEX_NUM;j++)
		{
			printf("%d ", G.edge[i][j]);
		}// for
		printf("\n");
	}// for
	
	return OK;
	
} // display()

// ������
void main()
{
	linkQueue Q;
	int i;
	AElem x;
	if(InitQueue(&Q))
	{
		printf("����Q�ѳ�ʼ����\n");
	}
	for(i=1;i<=10;i++)
	{
		EnQueue(&Q, i);
	}
		for(i=1;i<=10;i++)
	{
		DeQueue(&Q, &x);
	}
	QueueDisplay(Q);
} 
