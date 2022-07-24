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
	G->edge[1][5] = 1;
	G->edge[5][1] = 1;
	G->edge[2][4] = 1;
	G->edge[4][2] = 1;
	G->edge[2][5] = 1;
	G->edge[5][2] = 1;
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
{// ������ȱ���ͼG
 /*
 	����˼�룺����һ���ѷ�������visited[]�����ڱ�ǽ��ķ����������ÿ����㣬����һ�����в�α����� 
 */ 
	int i;
	boolean visited[G.vexnum+1]; // �ѷ�������	
	
	for(i=1;i<=G.vexnum;i++) // ��ʼ���ѷ������� 
	{
		visited[i] = FALSE;
	}// for
	for(i=1;i<=G.vexnum;i++) // ��ÿ����㣬����Ϊ�������ò�α���������һ��ѭ�����Ա���һ����ͨ���� 
	{
		if(!visited[i]) // ��iδ�����ʹ�
		{
			BFS(G, i, visited);
		} // if 
	} //for
	
	return OK;
}// BFS_Traverse()

Status BFS(MGraph G, int v, boolean visited[])
{// ��ͼ��v��㣬����Ϊ�������ò�α���
 /*
 	����˼�룺���ȷ��ʸ���㲢���������ӡ��ڶ��зǿյ�����½�������ѭ�������ӣ����ڳ���Ԫ��ÿһ��
	δ�����ʹ������ڽӵ㣬����֮��������ӡ� 
 */ 
	linkQueue Q; // ��������
	AElem x; // ���ճ���Ԫ��
	int i; 
	
	InitQueue(&Q); // ��ʼ������Q
	printf("%d ", v); // ���ʸ����
	visited[v] = TRUE;
	EnQueue(&Q, v); // ��������
	while(!QueueIsEmpty(Q)) // ���зǿ������
	{
		DeQueue(&Q, &x); // ����
		for(i=v+1;i<=G.vexnum;i++)
		{
			if(G.edge[x][i]==1 && (!visited[i])) // ���iδ�����ʹ�������x���� 
			{
				printf("%d ", i);
				visited[i] = TRUE;
				EnQueue(&Q, i);
			}// if
		}// for
	}// while 
	
	return OK;
}// BFS()

Status DFS_Traverse(MGraph G)
{// ������ȱ���ͼG
/*
	����˼�룺��������ʼ��һ���ѷ�������visited[]����ͼ�е�ÿ����㣬��δ�����ʹ�������Ϊ��������һ��
	����������ȱ����� 
*/
	boolean visited[G.vexnum+1]; // �ѷ������� 
	int i;
	
	for(i=1;i<=G.vexnum;i++) // ��ʼ���ѷ������� 
	{
		visited[i] = FALSE;
	}// for
	for(i=1;i<=G.vexnum;i++)
	{
		if(!visited[i]) // ���δ�����ʹ�
		{
			DFS(G, i, visited);	
		}// if
	}// for
	
	return OK;
}// DFS_Traverse()

Status DFS(MGraph G, int v, boolean visited[])
{// ��ͼG�еĽ��vΪ����㣬����������ȱ�����
 /*
 	����˼�룺���ȷ��ʽ��v�������v�����ڽӵ�δ�����ʵĽ�㣬�ݹ����DFS�� 
 */ 
	int i;
	printf("%d ", v); // ���ʽ��v
	visited[v] = TRUE;
	for(i=1;i<=G.vexnum;i++)
	{
		if(G.edge[v][i]==1 && !(visited[i])) // ���iδ�����ʹ�������v�ڽ� 
		{
			DFS(G, i, visited); // �ݹ���� 
		}// if
	}// for
	
	return OK;
}// DFS()

// ������
void main()
{
	MGraph G;
	if(InitGraph(&G, 5))
	{
		printf("ͼG�ѳ�ʼ����\n");
	}
	if(Example(&G))
	{
		printf("ͼG�����Ѽ��أ�\n");
	}
	DisplayGraph(G);
	DFS_Traverse(G);
} 
 
 
