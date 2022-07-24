#include<stdio.h>
#include<stdlib.h>
#define MAX_VEX_NUM 4 // 定义最大结点个数 

// 函数状态
#define TRUE 1 // 逻辑1
#define FALSE 0 // 逻辑0
#define OK 1 // 程序运行无误
#define ERROR 0 // 程序运行有误
#define INFEASIBLE -1
#define OVERFLOW -2 // 结果溢出
typedef int Status; // 函数状态类型
typedef int boolean; // 布尔类型 


// 图的邻接表存储方式 
typedef struct EdgeNode
{// 边表结点 
	int adjvex; // 边邻接的结点
	struct EdgeNode *nextEdge; // 下一条边 
}EdgeNode;
typedef struct VexNode
{// 顶点结点 
	int vextex; // 顶点序号
	EdgeNode *firstEdge; // 指向第一条边的指针 
}VexNode;
typedef struct
{// 图
	VexNode* vex[MAX_VEX_NUM+1]; // 顶点数组
	int vexnum; // 顶点个数 
}ALGraph;

// 邻接表图相关操作
Status Example(ALGraph *G)
{// 将案例加载到图G
 /*
 	基本思想：首先进行初始化：顶点个数置0，所有顶点结点指针域置空。然后将图的特点填入。 
 */ 
	int i; // 循环变量 
	G->vexnum = 4; // 顶点个数
	for(i=1;i<=MAX_VEX_NUM;i++) // 所有顶点结点指针域置空 
	{
		G->vex[i]->firstEdge = NULL;
	}// for
	
	return OK;
	 
} 


void main()
{

}
