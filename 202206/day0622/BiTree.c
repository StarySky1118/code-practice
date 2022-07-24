#include<stdio.h>
#include<stdlib.h>

// 函数状态代码
#define TRUE 1 // 逻辑1
#define FALSE 0 // 逻辑0
#define OK 1 // 程序运行无误
#define ERROR 0 // 程序运行有误
#define INFEASIBLE -1
#define OVERFLOW -2 // 结果溢出
typedef int Status; // 函数状态类型：int
typedef int boolean; // 布尔类型：int

// 二叉结点数据元素类型
typedef int TreeElem; // 二叉结点数据元素类型：int

// 二叉树存储结构
typedef struct BiNode
{
	TreeElem data; // 数据域
	struct BiNode *lchild, *rchild; // 左右孩子指针域
}BiNode, *BiTree;

// 辅助数据结构结点数据元素类型
typedef BiNode* AElem; // 辅助数据结构数据元素类型：二叉结点指针

// 辅助栈存储结构
typedef struct SNode
{
	AElem data; // 数据域
	struct SNode *next; // 指针域
}SNode, *linkStack;

// 辅助队列存储结构
typedef struct LNode 
{// 队列结点
	AElem data; // 数据域
	struct LNode *next; // 指针域
}LNode;
typedef struct
{// 队列
	LNode *front, *rear; // 队首队尾指针
}linkQueue;

// -----辅助栈操作描述-----
Status InitStack(linkStack *S)
{// 初始化栈S
	SNode *s; // 工作指针
	s = (SNode*)malloc(sizeof(SNode)); // 新建表头结点
	s->data = NULL; // 数据域赋初值
	s->next = NULL; // 指针域赋初值
	*S = s; // 栈指针指向此新建结点
	return OK;
}// InitStack()

boolean StackIsEmpty(linkStack S)
{// 判断栈S是否为空
	if(S->next==NULL)
		return TRUE;
	return FALSE;
}// StackIsEmpty()

Status DisplayStack(linkStack S)
{// 可视化输出链栈S
 /*
	使用遍历指针p依次输出从栈顶到栈底的所有元素	
 */
	SNode *p=S->next; // 遍历指针
	while(p!=NULL) // p非空时
	{
		visit(p->data); // 访问数据域
		printf("\n");
		p = p->next; // 继续遍历
	}// while
	return OK;
}// DisplayStack()

Status GetTop(linkStack S, AElem *x)
{// 获取栈顶元素并使用x返回
	if(S->next==NULL) // 栈为空
		return ERROR;
	else
		*x = S->next->data;
	return OK;
}// GetTop()

Status Push(linkStack S, AElem x)
{// 将数据元素x入栈
 /*
	基本思想：新建结点按头插法插入链栈中
 */
	SNode *s; // 工作指针
	s = (SNode*)malloc(sizeof(SNode)); // 新建结点
	s->data = x; // 数据域赋值
	s->next = S->next; // 完善指针域
	S->next = s;
	return OK;
}// Push()

Status Pop(linkStack S, AElem *x)
{// 弹栈并使用x接收弹出结点的数据域值
 /*
	基本思想：首先接收栈顶元素值并判断是否可弹栈，若可弹栈，删除栈顶结点。
 */
	SNode *s=S->next; // 工作指针
	if(!(GetTop(S, x))) // 无法获取栈顶元素说明栈为空，此时无法弹栈
		return ERROR;
	S->next = s->next; // 逻辑删除
	free(s); // 物理删除
	return OK;
}// Pop()

// -----辅助队列操作描述-----
Status InitQueue(linkQueue *Q)
{// 初始化链队列Q
 /*
	基本思想：建立表头结点，并使队首队尾指针均指向此结点
	*/
	LNode *s; // 工作指针
	s = (LNode*)malloc(sizeof(LNode)); // 新建表头结点
	s->data = NULL; // 初始化数据域
	s->next = NULL; // 初始化指针域
	Q->front = s; // 队首指针指向此新建结点
	Q->rear = s; // 队尾指针指向新建结点
	return OK;
}// InitQueue()

boolean QueueIsEmpty(linkQueue Q)
{// 

}

// 二叉树操作描述
Status visit(BiNode *s)
{// 访问二叉指针s指向的二叉结点
	printf("%d ", s->data); // 输出结点数据域
	return OK;
}// visit

Status Example(BiTree *T)
{// 将案例加载到二叉树T
	BiNode *s, *p, *q; // 工作指针

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 1; // 数据域赋值
	s->lchild = NULL; // 指针域赋初值
	s->rchild = NULL;
	*T = s; // 将此结点作为根结点

	p = s; // p指向数据元素为1结点

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 2; // 数据域赋值
	s->lchild = NULL; // 指针域赋初值
	s->rchild = NULL;
	p->lchild = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 3; // 数据域赋值
	s->lchild = NULL; // 指针域赋初值
	s->rchild = NULL;
	p->rchild = s;
	
	q = p->rchild; // q指向数据元素为3结点
	p = p->lchild; // p指向数据元素为2结点

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 4; // 数据域赋值
	s->lchild = NULL; // 指针域赋初值
	s->rchild = NULL;
	p->lchild = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 5; // 数据域赋值
	s->lchild = NULL; // 指针域赋初值
	s->rchild = NULL;
	p->rchild = s;

	q = p->rchild; // q指向数据元素为5结点

	s = (BiNode*)malloc(sizeof(BiNode)); // 新建结点
	s->data = 6; // 数据域赋值
	s->lchild = NULL; // 指针域赋初值
	s->rchild = NULL;
	q->lchild = s;

	return OK;
}// Example()

Status PreOrder_re(BiTree T)
{// 递归方式先序遍历二叉树T
	if(T!=NULL)
	{
		visit(T); // 访问根结点
		PreOrder_re(T->lchild); // 先序遍历左子树
		PreOrder_re(T->rchild); // 先序遍历右子树
	}// if
	return OK;
}// PreOrder_re

Status InOrder_nr(BiTree T)
{// 非递归中序遍历二叉树T
 /*
	基本思想：使用一辅助栈存储已由遍历指针指向但未输出的二叉结点。在遍历指针非空或
	辅助栈非空时进行如下循环：当遍历指针非空时，将其指向的二叉结点入栈，并继续向左
	下进发；当遍历指针为空，弹栈并输出，遍历指针向弹栈结点右下进发。
	*/
	linkStack S; // 辅助栈
	BiNode *p=T, *s; // 二叉树的遍历指针
	InitStack(&S); // 初始化辅助栈

	while(p!=NULL||(!StackIsEmpty(S))) // 遍历指针非空或栈非空时
	{
		if(p!=NULL) // 遍历指针非空
		{
			Push(S, p); // p结点入栈
			p = p->lchild; // 向左下进发
		}// if
		else // 遍历指针为空
		{
			Pop(S, &s); // 弹栈
			visit(s); // 访问
			p = s->rchild; // 向弹栈结点的右下进发
		}// else
	}// while
	printf("\n");

	return OK;
}// InOrder_nr

Status PreOrder_nr(BiTree T)
{// 先序非递归遍历二叉树T
 /*
	基本思想：使用辅助栈存储已输出但左右子树均为输出的二叉结点指针，使用一指针遍历二叉树的结点。
	在遍历指针非空或栈非空的情况下进行如下循环：若遍历指针非空，输出指针指向的二叉结点数据域，
	并使此结点指针入栈，接着遍历指针向左下进发；若遍历指针为空，弹栈并使遍历指针向弹栈结点右下进发。
	*/
	linkStack S; // 辅助栈
	BiNode *p=T; // 二叉树的遍历指针
	BiNode *s; // 工作指针

	InitStack(&S); // 初始化辅助栈
	while(p!=NULL||!(StackIsEmpty(S))) // p非空或栈非空时
	{
		if(p!=NULL) // 遍历指针非空
		{
			visit(p); // 访问结点
			Push(S, p); // p结点入栈
			p = p->lchild; // 向左下进发
		}// if
		else // 遍历指针空
		{
			Pop(S, &s);
			p = s->rchild;
		}// else
	}// while
	printf("\n");

	return OK;
}// PreOrder_nr()

Status PostOrder_nr(BiTree T)
{// 后序非递归遍历二叉树T
 /*
	基本思想：使用辅助栈存储左右子树均未输出的二叉结点指针，使用指针p遍历二叉树，使用指针pre指向上一次输出的结点，
	默认情况下，指针pre指向NULL。在指针p非空或栈非空情况下，进行如下循环：若指针p非空，说明遍历到了新的未输出结点，
	将此结点入栈，并继续向左下进发；若指针p为空，首先获取栈顶元素，并判断栈顶元素右孩子是否与pre指向的结点相同，若
	相同，弹栈并输出栈顶元素，重新设置pre；若不同，向栈顶元素右下进发。
	*/
	linkStack S; // 辅助栈
	BiNode *p=T; // 遍历指针
	BiNode *pre=NULL; // 指向上次输出的结点
	BiNode *s; // 工作指针

	InitStack(&S); // 初始化工作栈
	while(p!=NULL||(!StackIsEmpty(S))) // 当指针p非空或栈非空时
	{
		if(p!=NULL) // 指针p非空
		{
			Push(S, p); // 将此结点入栈
			p = p->lchild; // 向左下进发
		}// if
		else 
		{
			GetTop(S, &s); // 获取栈顶元素
			if(s->rchild==NULL||s->rchild==pre) // 栈顶元素的右孩子刚刚被访问过或无右孩子
			{
				Pop(S, &s); // 弹栈
				visit(s); // 访问结点
				pre = s;
			}// if
			else
			{
				p = s->rchild; // 向栈顶元素右下进发
			}// else
		}// else
	}// while
	printf("\n");
	return OK;
}// PostOrder_nr

// 主函数
void main()
{
	BiTree T;
	linkQueue Q;
	if(Example(&T))
		printf("二叉树案例已加载！\n");
	if(InitQueue(&Q))
		printf("队列已初始化！\n");
}