#include<stdio.h>
#include<stdlib.h>

// 函数状态代码
#define TRUE 1 // 逻辑1
#define FALSE 0 // 逻辑0
#define OK 1 // 程序运行无误
#define ERROR 0 // 程序运行有误
#define INFEASIBLE -1 
#define OVERFLOW -2 // 结果溢出
typedef int Status; // 函数状态类型
typedef int Boolean; // 布尔类型

// 二叉结点数据元素类型
typedef int BiElem; // int型

// 二叉链表存储结构
typedef struct BiNode
{
	BiElem data; // 数据域
	struct BiNode *lchild, *rchild; // 左右孩子
}BiNode, *BiTree;

// 辅助数据结构数据元素类型
typedef BiNode* AElem; // 二叉结点指针

// 辅助栈存储结构
typedef struct SNode
{
	AElem data; // 数据域
	struct SNode *next; // 指针域
}SNode, *Stack;

// 辅助栈操作
Status InitStack(Stack *S)
{// 初始化辅助栈S
	SNode *s; // 工作指针
	s = (SNode*)malloc(sizeof(SNode)); // 新建表头结点
	s->data = NULL; // 初始化数据域
	s->next = NULL; // 初始化指针域
	*S = s;
	return OK;
}// InitStack()

Boolean StackIsEmpty(Stack S)
{// 判断栈S是否为空
	if(S->next==NULL)
		return TRUE;
	return FALSE;
}// StackIsEmpty()

// 二叉树操作
Status Example(BiTree *T)
{// 加载案例
	BiNode *s, *p, *q; // 工作指针

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 1; // 数据域赋值
	s->lchild = NULL; // 指针域初始化
	s->rchild = NULL;

	*T = s; // 根结点指针指向
	p = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 2; // 数据域赋值
	s->lchild = NULL; // 指针域初始化
	s->rchild = NULL;

	p->lchild = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 3; // 数据域赋值
	s->lchild = NULL; // 指针域初始化
	s->rchild = NULL;

	p->rchild = s;

	q = p->rchild;
	p = p->lchild;

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 4; // 数据域赋值
	s->lchild = NULL; // 指针域初始化
	s->rchild = NULL;
	
	p->lchild = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 5; // 数据域赋值
	s->lchild = NULL; // 指针域初始化
	s->rchild = NULL;

	p->rchild = s;
	
	q = p->rchild;

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 6; // 数据域赋值
	s->lchild = NULL; // 指针域初始化
	s->rchild = NULL;

	q->lchild = s;

	return OK;

}// Example()

Status visit(BiNode *p)
{// 访问指针p指向结点的数据域
	if(p==NULL)
		return ERROR;
	else
		printf("%d ", p->data);
	return OK;
}// visit()

Status PreOrder_r(BiTree T)
{// 递归方式先序遍历二叉树T
	if(T==NULL) // 二叉树为空
		return ERROR;
	else
	{
		visit(T); // 访问根结点
		PreOrder_r(T->lchild); // 访问左子树
		PreOrder_r(T->rchild); // 访问右子树
	}// else
	return OK;
}// PreOrder_r()

// 主函数
void main()
{
	BiTree T;
	Example(&T);
	
}
