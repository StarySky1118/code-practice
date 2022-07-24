#include<stdio.h>
#include<stdlib.h>

#define MAX_VeX_NUM 10 // ͼ�������� 

// ����״̬
#define TRUE 1 // �߼�1
#define FALSE 0 // �߼�0
#define OK 1 // ������������
#define ERROR 0 // ������������
#define INFEASIBLE -1 
#define OVERFLOW -2 // ������
typedef int Status; // ����״̬����
typedef int boolean; // ��������

// ͼ���ڽӾ���洢��ʽ����
typedef int vextype; // ������ͣ�int
typedef int edgetype; // �����ͣ�int
typedef struct
{
	vextype vertex[MAX_VeX_NUM+1]; // ����
	edgetype edge[MAX_VeX_NUM+1][MAX_VeX_NUM+1]; // �ڽӾ���
	int vexnum; // ������ 
}MGraph;

// ͼ�ĸ������ݽ�����������
typedef vextype AElem; // ���������ͣ�vexType

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

// ͼ��������
Status InitGraph(MGraph *G, int v)
{// ��ʼ��������Ϊv��ͼG
 /*
 	����˼�룺��ʼ�������ڽӾ���ͽ������� 
 */ 
 	int i, j;
	G->vexnum = v;
	for(i=1;i<=G->vexnum;i++) // �����ʼ�� 
	{
		G->vertex[i] = i;
	}// for
	for(i=1;i<=G->vexnum;i++) // �ڽӾ����ʼ�� 
	{
		for(j=1;j<=G->vexnum;j++)
		{
			G->edge[i][j] = 0;
		}// for
	}// for
	return OK;
}// InitGraph()

Status DisplayGraph(MGraph G)
{// ���ӻ����ͼG
 /*
 	����˼�룺���������������Ȼ����������������߱� 
 */ 
 	int i, j;
	printf("ͼ������Ϊ%d��������Ϊ%d\n", G.vexnum, edge_num(G));
	printf("ͼ�����н�㣺");
	for(i=1;i<=G.vexnum;i++)
	{
		printf("%d ", G.vertex[i]);
	}// for
	printf("\n");
	printf("ͼ���ڽӾ���Ϊ��\n");
	printf("  ");
	for(i=1;i<=G.vexnum;i++)
	{
		printf("%d ", G.vertex[i]);
	}// for
	printf("\n");
	printf("  ");
	for(i=1;i<=G.vexnum;i++)
	{
		printf("--");
	}// for
	printf("\n");
	for(i=1;i<=G.vexnum;i++)
	{
		printf("%d|", i);
		for(j=1;j<=G.vexnum;j++)
		{
			printf("%d ", G.edge[i][j]);
		}// for
		printf("\n");
	}// for
	return OK;
}

Status Example(MGraph *G)
{// �����尸�����ص�ͼG 
	G->edge[1][2] = 1;
	G->edge[2][1] = 1;
	G->edge[1][3] = 1;
	G->edge[3][1] = 1;
	G->edge[2][4] = 1;
	G->edge[4][2] = 1;
	G->edge[3][4] = 1;
	G->edge[4][3] = 1;
	G->edge[1][4] = 1;
	G->edge[4][1] = 1;
	return OK; 
	
}// Example()

int edge_num(MGraph G)
{// ����ͼG����
 /*
 	����˼�룺ֻ���¼��������1�ĸ����� 
 */ 
	int i, j;
	int count = 0;
	for(i=1;i<=G.vexnum;i++)
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
}// edge_num()

Status BFS_Traverse(MGraph G)
{// ʹ�ù�����Ȳ��Ա���ͼG
 /*
 	����˼�룺ʹ������visit[]��¼ͼ�н���Ƿ񱻷��ʹ�����ÿ����㣬����BFS()��BFS()
	�������ǴӴ˽�㿪ʼ���й�����ȱ����� 
 */ 
	int i;
	boolean visited[G.vexnum+1]; // ��������
	for(i=1;i<=G.vexnum;i++) // ��ʼ����������
	{
		visited[i] = FALSE;
	}// for
	for(i=1;i<G.vexnum;i++) // ����ͼ��ÿ�����
	{
		BFS(G, i, visited);
	} 
	return OK;
}// BFS_Traverse()

Status BFS(MGraph G, int v, boolean visited[])
{// ��ͼG���vʹ�ù�����ȱ���
 /*
 	����˼�룺���Ƚ�v��ӣ��ڶ��зǿյ�����½�������ѭ�������Ӳ����ʣ��÷������飬�������ڵ�
	���δ�����ʹ�����������ӡ� 
 */ 
	linkQueue Q; // ��������
	AElem x; // ��ʱ���� 
	int i;
	
	InitQueue(&Q); // ��ʼ����������
	printf("%d ", v);
	visited[v] = TRUE;
	EnQueue(&Q, v); // ���v���
	while(!QueueIsEmpty(Q)) // ���зǿ�ʱ
	{
		DeQueue(&Q, &x); // ����
		for(i=x;i<=G.vexnum;i++) // �������Ԫ���ڽ���δ�����ʵĽ�����
		{
			if(G.edge[x][i]==1&&visited[i]==FALSE)
			{
				printf("%d ", i);
				visited[i] = TRUE;
				EnQueue(&Q, i);
			}// if
		}// if
	}// while
	
	return OK;
}

// ������
void main()
{
	MGraph G;
	if(InitGraph(&G, 4))
	{
		printf("ͼG�ѳ�ʼ����\n");
	}
	if(Example(&G))
	{
		printf("ͼG�ѳ�ʼ����\n");
	}
	DisplayGraph(G);
	BFS_Traverse(G);
} 
 
 
