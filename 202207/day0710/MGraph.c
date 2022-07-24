#include<stdio.h>
#include<stdlib.h>

#define MAX_VEX_NUM 4 // 最大结点个数 

// 函数状态代码
#define TRUE 1 // 逻辑1
#define FALSE 0 // 逻辑0
#define OK 1 // 程序运行无误
#define ERROR 0 // 程序运行有误
#define INFEASIBLE -1
#define OVERFLOW -2 // 结果溢出
typedef int Status; // 函数状态类型
typedef int boolean; // 布尔类型

typedef int vexType; // 结点类型：int
typedef int edgeType; // 边类型:int  

// 图的邻接矩阵存储结构
typedef struct
{// 结构内包含：结点集、邻接矩阵和结点个数 
	vexType vertex[MAX_VEX_NUM+1]; // 结点集
	edgeType edge[MAX_VEX_NUM+1][MAX_VEX_NUM+1]; // 边集
	int vexnum; // 结点个数 
}MGraph;

// 图的辅助数据结数据域类型
typedef vexType AElem; // 数据域类型：vexType

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

// 图的基本操作
Status example(MGraph *G)
{// 将案例加载到图G
 /*
 	基本思想：首先初始化图G：将顶点集、顶点数赋予正确值，邻接矩阵初始化零矩阵。然后
	填入正确矩阵。 
 */
	int i, j; // 循环变量
	G->vexnum = MAX_VEX_NUM;
	G->vertex[1] = 1;
	G->vertex[2] = 2;
	G->vertex[3] = 3;
	G->vertex[4] = 4;
	
	for(i=1;i<=MAX_VEX_NUM;i++) // 邻接矩阵初始化 
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
{// 输出G的边数
 /*
 	基本思想：只计邻接矩阵下三角中1的个数。 
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
{// 输出图G的所有信息

	int i, j;
	
	// 输出所有结点信息
	printf("图中所有结点为：\n");
	for(i=1;i<=MAX_VEX_NUM;i++)
	{
		printf("%d ", G.vertex[i]);
	}// for
	printf("\n");
	
	// 输出边数和结点数
	printf("图中结点数量为%d,图中边数为%d\n", G.vexnum, edgeNum(G));
	
	// 输出邻接矩阵
	printf("图邻接矩阵如下：\n");
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

// 主函数
void main()
{
	linkQueue Q;
	int i;
	AElem x;
	if(InitQueue(&Q))
	{
		printf("队列Q已初始化！\n");
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
