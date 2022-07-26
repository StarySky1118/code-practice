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
	struct BiNode* lchild, * rchild; // 左右孩子指针域
}BiNode, * BiTree;

// 辅助数据结构结点数据元素类型
typedef BiNode* AElem; // 辅助数据结构数据元素类型：二叉结点指针

// 辅助栈存储结构
typedef struct SNode
{
	AElem data; // 数据域
	struct SNode* next; // 指针域
}SNode, * linkStack;

// 辅助队列存储结构
typedef struct QNode
{// 队列结点
	AElem data; // 数据域
	struct QNode* next; // 指针域
}QNode;
typedef struct
{// 队列
	QNode* front, * rear; // 队首队尾指针
}linkQueue;

Status visit(BiNode* s)
{// 访问二叉指针s指向的二叉结点
	printf("%d ", s->data); // 输出结点数据域
	return OK;
}// visit

// -----辅助栈操作描述-----
Status InitStack(linkStack* S)
{// 初始化栈S
	SNode* s; // 工作指针
	s = (SNode*)malloc(sizeof(SNode)); // 新建表头结点
	s->data = NULL; // 数据域赋初值
	s->next = NULL; // 指针域赋初值
	*S = s; // 栈指针指向此新建结点
	return OK;
}// InitStack()

boolean StackIsEmpty(linkStack S)
{// 判断栈S是否为空
	if (S->next == NULL)
		return TRUE;
	return FALSE;
}// StackIsEmpty()

Status DisplayStack(linkStack S)
{// 可视化输出链栈S
 /*
	使用遍历指针p依次输出从栈顶到栈底的所有元素
 */
	SNode* p = S->next; // 遍历指针
	while (p != NULL) // p非空时
	{
		visit(p->data); // 访问数据域
		printf("\n");
		p = p->next; // 继续遍历
	}// while
	return OK;
}// DisplayStack()

Status GetTop(linkStack S, AElem* x)
{// 获取栈顶元素并使用x返回
	if (S->next == NULL) // 栈为空
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
	SNode* s; // 工作指针
	s = (SNode*)malloc(sizeof(SNode)); // 新建结点
	s->data = x; // 数据域赋值
	s->next = S->next; // 完善指针域
	S->next = s;
	return OK;
}// Push()

Status Pop(linkStack S, AElem* x)
{// 弹栈并使用x接收弹出结点的数据域值
 /*
	基本思想：首先接收栈顶元素值并判断是否可弹栈，若可弹栈，删除栈顶结点。
 */
	SNode* s = S->next; // 工作指针
	if (!(GetTop(S, x))) // 无法获取栈顶元素说明栈为空，此时无法弹栈
		return ERROR;
	S->next = s->next; // 逻辑删除
	free(s); // 物理删除
	return OK;
}// Pop()

// -----辅助队列操作描述-----
Status InitQueue(linkQueue* Q)
{// 初始化链队列Q
 /*
	基本思想：建立表头结点，并使队首队尾指针均指向此结点
	*/
	QNode* s; // 工作指针
	s = (QNode*)malloc(sizeof(QNode)); // 新建表头结点
	s->data = NULL; // 初始化数据域
	s->next = NULL; // 初始化指针域
	Q->front = s; // 队首指针指向此新建结点
	Q->rear = s; // 队尾指针指向新建结点
	return OK;
}// InitQueue()

boolean QueueIsEmpty(linkQueue Q)
{// 判断队列是否为空
	if (Q.front == Q.rear)
		return TRUE;
	return FALSE;
}// QueueIsEmpty()

Status QueueDisplay(linkQueue Q)
{// 可视化输出队列Q
	QNode* p = Q.front->next; // 遍历指针
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}// while
	printf("\n");
	return OK;
}// QueueDisplay()

Status GetHead(linkQueue Q, AElem* x)
{// 获取队列Q队首元素并使用x返回
	if (QueueIsEmpty(Q)) // 队列为空
		return ERROR;
	*x = Q.front->next->data;
	return OK;
}// GetHead()

Status EnQueue(linkQueue* Q, AElem x)
{// 将数据元素x入队
 // 基本思想：首先新建结点，然后按尾插法插入新结点
	QNode* s; // 工作指针
	s = (QNode*)malloc(sizeof(QNode)); // 新建结点
	s->data = x; // 数据域赋值
	s->next = Q->rear->next;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}// EnQueue()

Status DeQueue(linkQueue* Q, AElem* x)
{// 队首元素出队并使用x返回
	QNode* s = Q->front->next; // 工作指针
	if (!(GetHead(*Q, x))) // 获取队首元素
		return ERROR;
	Q->front->next = s->next; // 逻辑删除
	if (s == Q->rear) // 若队列只含一个元素
		Q->rear = Q->front;
	free(s); // 物理删除
	return OK;
}// DeQueue()

// 二叉树操作描述

Status Example(BiTree* T)
{// 将案例加载到二叉树T
	BiNode* s, * p, * q; // 工作指针

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
	if (T != NULL)
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
	BiNode* p = T, * s; // 二叉树的遍历指针
	InitStack(&S); // 初始化辅助栈

	while (p != NULL || (!StackIsEmpty(S))) // 遍历指针非空或栈非空时
	{
		if (p != NULL) // 遍历指针非空
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
	BiNode* p = T; // 二叉树的遍历指针
	BiNode* s; // 工作指针

	InitStack(&S); // 初始化辅助栈
	while (p != NULL || !(StackIsEmpty(S))) // p非空或栈非空时
	{
		if (p != NULL) // 遍历指针非空
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
	BiNode* p = T; // 遍历指针
	BiNode* pre = NULL; // 指向上次输出的结点
	BiNode* s; // 工作指针

	InitStack(&S); // 初始化工作栈
	while (p != NULL || (!StackIsEmpty(S))) // 当指针p非空或栈非空时
	{
		if (p != NULL) // 指针p非空
		{
			Push(S, p); // 将此结点入栈
			p = p->lchild; // 向左下进发
		}// if
		else
		{
			GetTop(S, &s); // 获取栈顶元素
			if (s->rchild == NULL || s->rchild == pre) // 栈顶元素的右孩子刚刚被访问过或无右孩子
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

Status LevelOrder(BiTree T)
{// 层次遍历二叉树T
 // 基本思想：使用辅助队列，首先将根结点入队，出队并输出队首元素，并将出队元素的左右孩子依次入队，直到队列为空。
	linkQueue Q; // 辅助队列
	AElem x; // 存储出队元素

	InitQueue(&Q); // 初始化队列
	EnQueue(&Q, T); // 根结点入队
	while (!(QueueIsEmpty(Q))) // 当队列非空时
	{
		DeQueue(&Q, &x); // 出队
		visit(x); // 访问出队元素
		if (x->lchild != NULL) // 左孩子入队
			EnQueue(&Q, x->lchild);
		if (x->rchild != NULL) // 右孩子入队
			EnQueue(&Q, x->rchild);
	}// while
	printf("\n");
	return OK;
}// LevelOrder()

Status LevelOrder_re(BiTree T)
{// 自下而上、从右到左遍历二叉树T
 /*
	基本思想：使用辅助队列与辅助栈。首先将根结点入队，在队列非空的情况下，出队，将出队元素压栈，同时将出队元素的
	左右孩子入队。将最终所得栈依次弹栈输出即可得到所需遍历序列。
	*/
	linkStack S; // 辅助栈
	linkQueue Q; // 辅助队列
	AElem x; // 工作指针

	InitStack(&S); // 初始化栈
	InitQueue(&Q); // 初始化队列
	EnQueue(&Q, T); // 根结点入队
	while (!QueueIsEmpty(Q)) // 队列非空时
	{
		DeQueue(&Q, &x); // 出队
		Push(S, x); // 出队元素压栈
		if (x->lchild != NULL) // 左孩子入队
			EnQueue(&Q, x->lchild);
		if (x->rchild != NULL) // 右孩子入队
			EnQueue(&Q, x->rchild);
	}// while
	while (!StackIsEmpty(S)) // 栈非空时
	{
		Pop(S, &x); // 弹栈
		visit(x); // 访问
	}// while
	printf("\n");

	return OK;
}// LevelOrder_re

int Height_Stack(BiTree T)
{// 返回二叉树T的高度
 /*
	基本思想：使用辅助栈结构，后序遍历二叉树T，并记录整个过程中栈的最大高度。	
 */
	linkStack S; // 辅助栈
	BiNode* p=T; // 遍历指针
	BiNode* pre = NULL; // 指向上一个输出的结点
	int height=0; // 记录栈实时高度
	int max_height=0; // 记录栈最大高度
	AElem x=NULL; // 工作指针 

	InitStack(&S); // 初始化栈
	while (p != NULL || !StackIsEmpty(S)) // p非空或栈非空时
	{
		if (p != NULL) // p非空
		{
			Push(S, p); // p指针压栈
			height++; // 栈实时高度加1
			if (height > max_height) // 若实时高度大于最大高度
				max_height = height;
			p = p->lchild; // p继续向左下进发
		}// if
		else // 栈非空
		{
			GetTop(S, &x); // 获取栈顶元素
			if (x->rchild == NULL || x->rchild == pre) // 栈顶元素无右孩子或右孩子刚刚被访问过
			{
				Pop(S, &x); // 弹栈
				height--; // 栈实时高度减1
				pre = x; // 更新pre 
			}// if
			else // 栈顶元素右孩子未被访问
			{
				p = x->rchild; // p向栈顶元素右孩子进发
			}// else
		}// eles
	}// while
	return max_height;
}// Height_Stack()

int Height_Queue(BiTree T)
{// 返回二叉树T的高度
 /*
	基本思想：使用辅助队列对二叉树进行层次遍历，使用指针last记录每层最右侧结点，last默认为T。
	将根结点入队，在队列非空时进行如下循环：出队并将出队元素左右孩子入队，若出队元素为last，设
	置last指向出队元素右孩子，层数加1。
 */	
	linkQueue Q; // 辅助队列
	BiNode* last=T; // 记录二叉树每层最右侧结点
	AElem x=NULL; // 工作指针
	int height=0; // 二叉树高度

	InitQueue(&Q); // 初始化辅助队列
	EnQueue(&Q, T); // 根结点入队
	while (!QueueIsEmpty(Q)) // 队列非空时
	{
		DeQueue(&Q, &x); // 出队
		if (x->lchild != NULL) // 左孩子入队
		{
			EnQueue(&Q, x->lchild); // 入队
		}// if
		if (x->rchild != NULL) // 右孩子入队
		{
			EnQueue(&Q, x->rchild); // 入队
		}// if
		if (x == last) // 出队元素为该层最右侧元素
		{
			last = Q.rear->data; // 修改last指针
			height++;
		}// if
	}// while

	return height;
}

boolean IsComplete(BiTree T)
{// 判断二叉树T是否为完全二叉树
 /*
 *	基本思想：借助层次遍历方法。首先将根结点入队，在队列非空时进行如下循环：出队，判断出队元素
 * 是否为空，若出队元素非空，将左右子树入队(无论是否为空)；若出队元素为空，将队列剩余元素全部出队
 * 进行判断。
 */
	linkQueue Q; // 辅助队列
	AElem x=NULL; // 工作指针
	boolean flag = TRUE; // 标志变量

	InitQueue(&Q); // 初始化辅助队列
	EnQueue(&Q, T); // 根结点入队
	while (!QueueIsEmpty(Q)) // 当队列非空时
	{
		DeQueue(&Q, &x); // 出队
		if (x != NULL) // 出队元素非空
		{
			EnQueue(&Q, x->lchild); // 左孩子入队
			EnQueue(&Q, x->rchild); // 右孩子入队
		}// if
		else // 出队元素为空
		{
			while (!QueueIsEmpty(Q)) // 队列非空时
			{
				DeQueue(&Q, &x); // 出队
				if (x != NULL) // 出现非空结点
				{
					flag = FALSE; // 置标志变量为假
					break;
				}// if
			}// while
		}// else
		if (flag == FALSE) // 若flag被修改过，退出循环
		{
			break;
		}// if
	}// while

	return flag;
}// IsComplete()

// 主函数
void main()
{
	BiTree T;
	if (Example(&T))
		printf("二叉树案例已加载！\n");
	if (IsComplete(T))
		printf("二叉树为完全二叉树！\n");
	else
		printf("二叉树非完全二叉树！\n");
}