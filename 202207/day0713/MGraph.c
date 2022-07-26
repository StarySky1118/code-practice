#include<stdio.h>
#include<stdlib.h>

#define MAX_VeX_NUM 10 // 图最大结点个数 

// 函数状态
#define TRUE 1 // 逻辑1
#define FALSE 0 // 逻辑0
#define OK 1 // 程序运行无误
#define ERROR 0 // 程序运行有误
#define INFEASIBLE -1 
#define OVERFLOW -2 // 结果溢出
typedef int Status; // 函数状态类型
typedef int boolean; // 布尔类型

// 图的邻接矩阵存储方式描述
typedef int vextype; // 结点类型：int
typedef int edgetype; // 边类型：int
typedef struct
{
	vextype vertex[MAX_VeX_NUM+1]; // 结点表
	edgetype edge[MAX_VeX_NUM+1][MAX_VeX_NUM+1]; // 邻接矩阵
	int vexnum; // 结点个数 
}MGraph;

// 图的辅助数据结数据域类型
typedef vextype AElem; // 数据域类型：vexType

// 队列辅助数据结构存储描述
typedef struct QNode 
{// 队列结点 
	AElem data; // 数据域
	struct QNode* next; // 指针域  
}QNode;
typedef struct
{// 队列 
	QNode *front, *rear; // 队首、队尾指针 
}linkQueue;

// 队列辅助数据结构相关操作 
Status InitQueue(linkQueue *Q)
{// 初始化队列Q
 /*
 	基本思想：新建表头结点，让队首和队尾指针均指向此结点。 
 */ 
	QNode *s = NULL; // 工作指针
	s = (QNode*)malloc(sizeof(QNode)); // 新建结点
	s->data = 0;
	s->next = NULL;
	Q->front = s;
	Q->rear = s;
	return OK; 
}// InitQueue()

boolean QueueIsEmpty(linkQueue Q)
{// 判断队列Q是否为空
	if(Q.front==Q.rear)
		return TRUE;
	return FALSE;
}// QueueIsEmpty()

Status QueueDisplay(linkQueue Q)
{// 可视化输出队列Q所有结点的数据域
	QNode *p=Q.front->next; // 遍历指针
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
{// 将数据元素x插入队列Q
/*
	基本思想：新建结点并按尾插法方式插入队列。 
*/ 
	QNode *s=NULL; // 工作指针
	s = (QNode*)malloc(sizeof(QNode)); // 新建结点
	s->data = x;
	s->next = Q->rear->next; // 链入队列 
	Q->rear->next = s;
	Q->rear = s; // 队尾指针后移
	return OK; 
}// EnQueue()

Status GetHead(linkQueue Q, AElem *x)
{// 获取队列Q队首元素
	if(Q.front->next==NULL) // 队列为空
		return ERROR;
	*x = Q.front->next->data; // 获取队首元素
	return OK; 
}// GetHead()

Status DeQueue(linkQueue *Q, AElem *x)
{// 出队
 /*
	基本思想：首先将首个结点逻辑删除，并判断队尾指针是否也指向此结点。 
 */ 
	QNode *s = Q->front->next; // 指向待删除结点
	if(s==NULL) // 队列为空
		return ERROR;
	*x = s->data; // 取值
	Q->front->next = s->next; // 逻辑删除
	if(s==Q->rear) // 队尾指针也指向此结点
	{
		Q->rear = Q->front; // 队尾指针指向表头结点 
	} // if
	free(s); // 物理删除s
	return OK;  
}// DeQueue() 

// 图操作描述
Status InitGraph(MGraph *G, int v)
{// 初始化结点个数为v的图G
 /*
 	基本思想：初始化结点表、邻接矩阵和结点个数。 
 */ 
 	int i, j;
	G->vexnum = v;
	for(i=1;i<=G->vexnum;i++) // 结点表初始化 
	{
		G->vertex[i] = i;
	}// for
	for(i=1;i<=G->vexnum;i++) // 邻接矩阵初始化 
	{
		for(j=1;j<=G->vexnum;j++)
		{
			G->edge[i][j] = 0;
		}// for
	}// for
	return OK;
}// InitGraph()

Status DisplayGraph(MGraph G)
{// 可视化输出图G
 /*
 	基本思想：首先输出结点个数，然后输出结点表，最后输出边表。 
 */ 
 	int i, j;
	printf("图结点个数为%d，边条数为%d\n", G.vexnum, edge_num(G));
	printf("图中所有结点：");
	for(i=1;i<=G.vexnum;i++)
	{
		printf("%d ", G.vertex[i]);
	}// for
	printf("\n");
	printf("图的邻接矩阵为：\n");
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
{// 将具体案例加载到图G 
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
{// 返回图G边数
 /*
 	基本思想：只需记录下三角中1的个数。 
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
{// 广度优先遍历图G
 /*
 	基本思想：设立一个已访问数组visited[]，用于标记结点的访问情况。对每个结点，像树一样进行层次遍历。 
 */ 
	int i;
	boolean visited[G.vexnum+1]; // 已访问数组	
	
	for(i=1;i<=G.vexnum;i++) // 初始化已访问数组 
	{
		visited[i] = FALSE;
	}// for
	for(i=1;i<=G.vexnum;i++) // 对每个结点，视其为根，运用层次遍历方法，一次循环可以遍历一个连通分量 
	{
		if(!visited[i]) // 若i未被访问过
		{
			BFS(G, i, visited);
		} // if 
	} //for
	
	return OK;
}// BFS_Traverse()

Status BFS(MGraph G, int v, boolean visited[])
{// 对图的v结点，视其为根，运用层次遍历
 /*
 	基本思想：首先访问根结点并将根结点入队。在队列非空的情况下进行如下循环：出队，对于出队元素每一个
	未被访问过的相邻接点，访问之并将其入队。 
 */ 
	linkQueue Q; // 辅助队列
	AElem x; // 接收出队元素
	int i; 
	
	InitQueue(&Q); // 初始化队列Q
	printf("%d ", v); // 访问根结点
	visited[v] = TRUE;
	EnQueue(&Q, v); // 根结点入队
	while(!QueueIsEmpty(Q)) // 队列非空情况下
	{
		DeQueue(&Q, &x); // 出队
		for(i=v+1;i<=G.vexnum;i++)
		{
			if(G.edge[x][i]==1 && (!visited[i])) // 结点i未被访问过且与结点x相邻 
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
{// 深度优先遍历图G
/*
	基本思想：建立并初始化一个已访问数组visited[]。对图中的每个结点，若未被访问过，视其为根，像树一样
	进行深度优先遍历。 
*/
	boolean visited[G.vexnum+1]; // 已访问数组 
	int i;
	
	for(i=1;i<=G.vexnum;i++) // 初始化已访问数组 
	{
		visited[i] = FALSE;
	}// for
	for(i=1;i<=G.vexnum;i++)
	{
		if(!visited[i]) // 结点未被访问过
		{
			DFS(G, i, visited);	
		}// if
	}// for
	
	return OK;
}// DFS_Traverse()

Status DFS(MGraph G, int v, boolean visited[])
{// 视图G中的结点v为根结点，进行深度优先遍历。
 /*
 	基本思想：首先访问结点v，若结点v仍有邻接但未被访问的结点，递归调用DFS。 
 */ 
	int i;
	printf("%d ", v); // 访问结点v
	visited[v] = TRUE;
	for(i=1;i<=G.vexnum;i++)
	{
		if(G.edge[v][i]==1 && !(visited[i])) // 结点i未被访问过且与结点v邻接 
		{
			DFS(G, i, visited); // 递归调用 
		}// if
	}// for
	
	return OK;
}// DFS()

// 主函数
void main()
{
	MGraph G;
	if(InitGraph(&G, 5))
	{
		printf("图G已初始化！\n");
	}
	if(Example(&G))
	{
		printf("图G案例已加载！\n");
	}
	DisplayGraph(G);
	DFS_Traverse(G);
} 
 
 
