#include<stdio.h>
#include<stdlib.h>

#define MaxVexNum 4 // 结点数量 

// 函数状态代码
#define TRUE 1 // 逻辑1
#define FALSE 0 // 逻辑0
#define OK 1 // 程序运行无误
#define ERROR 0 // 程序运行有误
#define INFEASIBLE -1 
#define OVERFLOW -2 // 结果溢出
typedef int Status; // 函数状态类型
typedef int boolean; // 布尔类型 

// 邻接矩阵存储结构
typedef int Vextype; // 结点类型：int
typedef int Edgetype; // 边类型：int
typedef struct
{
	Vextype Vex[MaxVexNum+1]; // 结点数组
	Edgetype Edge[MaxVexNum+1][MaxVexNum+1]; // 邻接矩阵
	int vexnum, edgenum; // 结点数、边数 
}MGraph;

// 邻接矩阵相关操作 
Status InitGraph(MGraph *G)
{// 初始化图G
	int i, j; // 循环变量
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
{// 为图加载案例
	int i; // 循环变量
	for(i=1;i<=MaxVexNum;i++) // 结点数组赋值 
	{
		G->Vex[i] = i; 	
	}// for
	
	// 边赋值 
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
{// 输出图G所有信息
	int i, j; // 循环变量
	printf("\n");
	printf("------------\n");
	printf("图结点个数为：%d\n", G.vexnum);
	printf("图边条数为：%d\n", G.edgenum);
	printf("图中结点为：\n");
	
	// 输出结点 
	for(i=1;i<=G.vexnum;i++)
	{
		printf("%d ", G.Vex[i]);
	}
	printf("\n");
	
	// 输出邻接矩阵
	printf("图的邻接矩阵如下：\n");
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


// 主函数 
void main()
{
	MGraph G;
	InitGraph(&G);
	if(Example(&G))
	{
		printf("图已经初始化完成！\n");
	}// if
	GraphDisplay(G);
}
