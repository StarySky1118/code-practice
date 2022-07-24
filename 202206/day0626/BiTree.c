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
typedef struct QNode 
{// 队列结点
	AElem data; // 数据域
	struct QNode *next; // 指针域
}QNode;
typedef struct
{// 队列
	QNode *front, *rear; // 队首队尾指针
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
	QNode *s; // 工作指针
	s = (QNode*)malloc(sizeof(QNode)); // 新建表头结点
	s->data = NULL; // 初始化数据域
	s->next = NULL; // 初始化指针域
	Q->front = s; // 队首指针指向此新建结点
	Q->rear = s; // 队尾指针指向新建结点
	return OK;
}// InitQueue()

boolean QueueIsEmpty(linkQueue Q)
{// 判断队列是否为空
	if(Q.front==Q.rear)
		return TRUE;
	return FALSE;
}// QueueIsEmpty()

Status QueueDisplay(linkQueue Q)
{// 可视化输出队列Q
	QNode *p=Q.front->next; // 遍历指针
	while(p!=NULL)
	{
		visit(p->data);
		p = p->next;
	}// while
	printf("\n");
	return OK;
}// QueueDisplay()

Status GetHead(linkQueue Q, AElem *x)
{// 获取队列Q队首元素并使用x返回
	if(QueueIsEmpty(Q)) // 队列为空
		return ERROR;
	*x = Q.front->next->data;
	return OK;
}// GetHead()

Status EnQueue(linkQueue *Q, AElem x)
{// 将数据元素x入队
 // 基本思想：首先新建结点，然后按尾插法插入新结点
	QNode *s; // 工作指针
	s = (QNode*)malloc(sizeof(QNode)); // 新建结点
	s->data = x; // 数据域赋值
	s->next = Q->rear->next;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}// EnQueue()

Status DeQueue(linkQueue *Q, AElem *x)
{// 队首元素出队并使用x返回
	QNode *s=Q->front->next; // 工作指针
	if(!(GetHead(*Q, x))) // 获取队首元素
		return ERROR;
	Q->front->next = s->next; // 逻辑删除
	if(s==Q->rear) // 若队列只含一个元素
		Q->rear = Q->front;
	free(s); // 物理删除
	return OK;
}// DeQueue()

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

Status LevelOrder(BiTree T)
{// 层次遍历二叉树T
 // 基本思想：使用辅助队列，首先将根结点入队，出队并输出队首元素，并将出队元素的左右孩子依次入队，直到队列为空。
	linkQueue Q; // 辅助队列
	AElem x; // 存储出队元素

	InitQueue(&Q); // 初始化队列
	EnQueue(&Q, T); // 根结点入队
	while(!(QueueIsEmpty(Q))) // 当队列非空时
	{
		DeQueue(&Q, &x); // 出队
		visit(x); // 访问出队元素
		if(x->lchild!=NULL) // 左孩子入队
			EnQueue(&Q, x->lchild);
		if(x->rchild!=NULL) // 右孩子入队
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
	while(!QueueIsEmpty(Q)) // 队列非空时
	{
		DeQueue(&Q, &x); // 出队
		Push(S, x); // 出队元素压栈
		if(x->lchild!=NULL) // 左孩子入队
			EnQueue(&Q, x->lchild);
		if(x->rchild!=NULL) // 右孩子入队
			EnQueue(&Q, x->rchild);
	}// while
	while(!StackIsEmpty(S)) // 栈非空时
	{
		Pop(S, &x); // 弹栈
		visit(x); // 访问
	}// while
	printf("\n");
	
	return OK;
}// LevelOrder_re

int Height(BiTree T)
{// 返回二叉树T的高度
 /*
	基本思想：使用辅助栈，借助后序遍历二叉树方法，在遍历过程中，栈中元素最大个数即为二叉树T的高度。
	*/
	linkStack S; // 辅助栈
	int height=0; // 记录栈的实时高度
	int maxHeight=0; // 记录栈的最大高度
	BiNode *p=T; // 遍历指针
	BiNode *pre=NULL; // 指向上一个输出的结点
	BiNode *s; // 工作指针

	InitStack(&S); // 初始化栈
	while(p!=NULL||!StackIsEmpty(S)) // p非空或栈非空时
	{
		if(p!=NULL)
		{
			Push(S, p); // 压栈
			height++;
			if(height>maxHeight)
				maxHeight = height;
			p = p->lchild; // 向左下进发
		}// if
		else
		{
			GetTop(S, &s); // 获取栈顶元素
			if(s->rchild==NULL||s->rchild==pre) // 栈顶元素无右孩子或右孩子刚刚被输出
			{
				Pop(S, &s); // 弹栈
				height--;
				pre = s; // 记录刚输出的结点
			}// if
			else
			{
				p = s->rchild; // 前往弹栈结点的右孩子
			} // else
		}// else
	}// while

	return maxHeight;
}// Height()

int Height_02(BiTree T)
{// 返回二叉树的高度
 /*
	基本思想：使用辅助队列结构。根结点入队并将其记为该层最后结点，在队列非空时循环：出队，若出队元素与LAST相同，层数加1，
	将出队元素的左右孩子入队，并记右孩子为LAST。
	*/
	linkQueue Q; // 辅助队列
	int level=0; // 层数
	BiNode *last; // 指向该层最后一个结点
	BiNode *s; // 工作指针

	InitQueue(&Q); // 初始化队列
	EnQueue(&Q, T); // 根结点入队 
	last = T;
	while(!QueueIsEmpty(Q)) // 队列非空时
	{
		DeQueue(&Q, &s); // 出队
		if(s->lchild!=NULL) // 出队元素左孩子入队
		{
			EnQueue(&Q, s->lchild); 
		}// if
		if(s->rchild!=NULL) // 出队元素右孩子入队
		{
			EnQueue(&Q, s->rchild);
		}// if
		if(s==last) // 出队元素即为本层最右侧结点
		{
			level++; // 层数加1
			last = Q.rear->data; // 将出队元素右孩子记为LAST
		}// if
	}// while

	return level;
}// Height_02()

// 主函数
int main()
{
	BiTree T;
	if(Example(&T))
		printf("二叉树案例已加载！\n");
	printf("二叉树的高度为%d\n", Height_02(T));

	return 0;
}