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

//-----二叉树结点数据元素-----
typedef int TreeElem; // int型 

//-----线索二叉树存储结构-----
typedef struct ThreadNode
{
	TreeElem data; // 数据域
	struct ThreadNode *lchild, *rchild; // 左右线索指针
	boolean ltag, rtag; // 左右标志
}ThreadNode, *ThreadTree;

//-----辅助数据结构数据元素类型-----
typedef ThreadNode* AElem;

//-----辅助栈存储结构-----
typedef struct SNode
{
	AElem data; // 数据域
	struct SNode *next; // 指针域
}SNode, *linkStack;

//-----辅助栈相关操作-----
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

//-----线索二叉树相关操作-----
Status visit(ThreadNode *s)
{// 输出所指向的二叉结点的数据域
	if(s==NULL)
		return ERROR;
	printf("%d ", s->data);
	return OK;
}// visit()

Status Example(ThreadTree *T)
{// 将案例加载到线索二叉树T
	ThreadNode *s, *p, *q; // 工作指针
	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // 新建结点
	s->data = 1;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	*T = s;
	p = s;

	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // 新建结点
	s->data = 2;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	p->lchild = s;

	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // 新建结点
	s->data = 3;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	p->rchild = s;

	q = p->rchild;
	p = p->lchild;

	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // 新建结点
	s->data = 4;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	p->lchild = s;
	
	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // 新建结点
	s->data = 5;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	p->rchild = s;

	q = p->rchild;

	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // 新建结点
	s->data = 6;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	q->lchild = s;

	return OK;
}// Example()

Status CreateInThread(ThreadTree T)
{// 中序线索化二叉树T
 /* 基本思想：使用指针p遍历二叉树所有结点。指针pre指示上一个输出的结点。在指针p非空或栈非空时进行如下循环：
	若指针p非空，将此结点入栈并向左下进发；若指针p为空，弹栈，若此结点前驱为NULL，将其前驱修改为pre，p向右下
	进发，同时，若pre的后继为NULL，将后继修改到此结点。
*/
	ThreadNode *p=T; // 二叉结点遍历指针
	AElem x;
	ThreadNode *pre=NULL; // 指示上一个输出的结点
	linkStack S; // 辅助栈

	InitStack(&S); // 初始化栈
	while(p!=NULL||(!(StackIsEmpty(S)))) // p非空或栈非空
	{
		if(p!=NULL) // p指向新结点
		{
			Push(S, p); // 新结点入栈
			p = p->lchild; // 向左下进发
		}// if
		else // p为空
		{
			Pop(S, &x); // 获取栈顶元素
			if(x->lchild==NULL) // 弹栈结点左孩子为空
			{
				x->lchild = pre;
				x->ltag = TRUE;
			}// if
			if(pre!=NULL&&pre->rchild==NULL) // pre右孩子为空
			{
				pre->rchild = x;
				pre->rtag = TRUE;
			}// if
			pre = x;
			p = x->rchild;
		}// else
	}// while

	return OK;
}// CreateInThread()

// 主函数
void main()
{
	ThreadTree T;
	if(Example(&T))
		printf("线索二叉树已初始化！\n");
	if(CreateInThread(T))
		printf("二叉树已线索化！\n");
}