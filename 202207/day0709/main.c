#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 4 // 结点个数：4 

// 函数状态代码
#define TRUE 1 // 逻辑1
#define FALSE 0 // 逻辑0
#define OK 1 // 函数运行无误
#define ERROR 0 // 函数运行有误
#define INFEASIBLE -1
#define OVERFLOW -2 // 结果溢出
typedef int Status; // 函数状态类型
typedef int boolean; // 布尔类型 

// 图的邻接矩阵存储结构
typedef int VexType; // 结点类型：int
typedef int EdgeType; // 边类型：int 
typedef struct 
{
	VexType vertex[MAX_VERTEX_NUM+1]; // 结点信息 
	EdgeType edge[MAX_VERTEX_NUM+1][MAX_VERTEX_NUM+1]; // 邻接矩阵
	int vexnum;
}MGraph;

// 图的相关操作
Status example(MGraph *G)
{// 加载案例到图G
 /*
 	基本思想：首先将节点信息赋值，然后邻接矩阵赋值，最后改变结点数和边数。 
 */ 
	int i, j; // 循环变量
	for(i=1;i<=MAX_VERTEX_NUM;i++) // 首先应该将邻接矩阵初始化 
	{
		for(j=1;j<=MAX_VERTEX_NUM;j++)
		{
			G->edge[i][j] = 0;
		}// for
	}// for
	
	// 结点信息
	G->vertex[1] = 1;
	G->vertex[2] = 2;
	G->vertex[3] = 3;
	G->vertex[4] = 4;
	
	// 邻接矩阵
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
	
	// 结点数和边数
	G->vexnum = MAX_VERTEX_NUM;
}// example()

int edgeNum(MGraph G)
{// 返回图G的边数
 /* 
	基本思想：查找邻接矩阵下三角范围内1的个数。
*/ 
	int i=1, j=1; // 内外循环变量
	int count=0; // 边数计数 
	for(i=1;i<=MAX_VERTEX_NUM;i++) // 对于邻接矩阵每一层 
	{
		for(j=1;j<=i;j++) // 每一层下三角范围内的每个数
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
{// 输出图G的所有信息

	int i, j; // 循环变量 
 	printf("图的结点数为%d，边数为%d\n", G.vexnum, edgeNum(G));
 	
	 printf("所有结点信息为：\n");
 	for(i=1;i<=G.vexnum;i++) // 输出结点信息 
 	{
 		printf("%d ", G.vertex[i]); 
	}// for
	printf("\n");
	
	printf("邻接矩阵如下：\n");
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


// 主函数 
int main(int argc, char *argv[]) {
	MGraph G;
	example(&G);
	display(G);
	return 0;
}// main 
