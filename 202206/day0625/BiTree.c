#include<stdio.h>
#include<stdlib.h>

// ����״̬����
#define TRUE 1 // �߼�1
#define FALSE 0 // �߼�0
#define OK 1 // ������������
#define ERROR 0 // ������������
#define INFEASIBLE -1
#define OVERFLOW -2 // ������
typedef int Status; // ����״̬���ͣ�int
typedef int boolean; // �������ͣ�int

// ����������Ԫ������
typedef int TreeElem; // ����������Ԫ�����ͣ�int

// �������洢�ṹ
typedef struct BiNode
{
	TreeElem data; // ������
	struct BiNode *lchild, *rchild; // ���Һ���ָ����
}BiNode, *BiTree;

// �������ݽṹ�������Ԫ������
typedef BiNode* AElem; // �������ݽṹ����Ԫ�����ͣ�������ָ��

// ����ջ�洢�ṹ
typedef struct SNode
{
	AElem data; // ������
	struct SNode *next; // ָ����
}SNode, *linkStack;

// �������д洢�ṹ
typedef struct QNode 
{// ���н��
	AElem data; // ������
	struct QNode *next; // ָ����
}QNode;
typedef struct
{// ����
	QNode *front, *rear; // ���׶�βָ��
}linkQueue;

// -----����ջ��������-----
Status InitStack(linkStack *S)
{// ��ʼ��ջS
	SNode *s; // ����ָ��
	s = (SNode*)malloc(sizeof(SNode)); // �½���ͷ���
	s->data = NULL; // �����򸳳�ֵ
	s->next = NULL; // ָ���򸳳�ֵ
	*S = s; // ջָ��ָ����½����
	return OK;
}// InitStack()

boolean StackIsEmpty(linkStack S)
{// �ж�ջS�Ƿ�Ϊ��
	if(S->next==NULL)
		return TRUE;
	return FALSE;
}// StackIsEmpty()

Status DisplayStack(linkStack S)
{// ���ӻ������ջS
 /*
	ʹ�ñ���ָ��p���������ջ����ջ�׵�����Ԫ��	
 */
	SNode *p=S->next; // ����ָ��
	while(p!=NULL) // p�ǿ�ʱ
	{
		visit(p->data); // ����������
		printf("\n");
		p = p->next; // ��������
	}// while
	return OK;
}// DisplayStack()

Status GetTop(linkStack S, AElem *x)
{// ��ȡջ��Ԫ�ز�ʹ��x����
	if(S->next==NULL) // ջΪ��
		return ERROR;
	else
		*x = S->next->data;
	return OK;
}// GetTop()

Status Push(linkStack S, AElem x)
{// ������Ԫ��x��ջ
 /*
	����˼�룺�½���㰴ͷ�巨������ջ��
 */
	SNode *s; // ����ָ��
	s = (SNode*)malloc(sizeof(SNode)); // �½����
	s->data = x; // ������ֵ
	s->next = S->next; // ����ָ����
	S->next = s;
	return OK;
}// Push()

Status Pop(linkStack S, AElem *x)
{// ��ջ��ʹ��x���յ�������������ֵ
 /*
	����˼�룺���Ƚ���ջ��Ԫ��ֵ���ж��Ƿ�ɵ�ջ�����ɵ�ջ��ɾ��ջ����㡣
 */
	SNode *s=S->next; // ����ָ��
	if(!(GetTop(S, x))) // �޷���ȡջ��Ԫ��˵��ջΪ�գ���ʱ�޷���ջ
		return ERROR;
	S->next = s->next; // �߼�ɾ��
	free(s); // ����ɾ��
	return OK;
}// Pop()

// -----�������в�������-----
Status InitQueue(linkQueue *Q)
{// ��ʼ��������Q
 /*
	����˼�룺������ͷ��㣬��ʹ���׶�βָ���ָ��˽��
	*/
	QNode *s; // ����ָ��
	s = (QNode*)malloc(sizeof(QNode)); // �½���ͷ���
	s->data = NULL; // ��ʼ��������
	s->next = NULL; // ��ʼ��ָ����
	Q->front = s; // ����ָ��ָ����½����
	Q->rear = s; // ��βָ��ָ���½����
	return OK;
}// InitQueue()

boolean QueueIsEmpty(linkQueue Q)
{// �ж϶����Ƿ�Ϊ��
	if(Q.front==Q.rear)
		return TRUE;
	return FALSE;
}// QueueIsEmpty()

Status QueueDisplay(linkQueue Q)
{// ���ӻ��������Q
	QNode *p=Q.front->next; // ����ָ��
	while(p!=NULL)
	{
		visit(p->data);
		p = p->next;
	}// while
	printf("\n");
	return OK;
}// QueueDisplay()

Status GetHead(linkQueue Q, AElem *x)
{// ��ȡ����Q����Ԫ�ز�ʹ��x����
	if(QueueIsEmpty(Q)) // ����Ϊ��
		return ERROR;
	*x = Q.front->next->data;
	return OK;
}// GetHead()

Status EnQueue(linkQueue *Q, AElem x)
{// ������Ԫ��x���
 // ����˼�룺�����½���㣬Ȼ��β�巨�����½��
	QNode *s; // ����ָ��
	s = (QNode*)malloc(sizeof(QNode)); // �½����
	s->data = x; // ������ֵ
	s->next = Q->rear->next;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}// EnQueue()

Status DeQueue(linkQueue *Q, AElem *x)
{// ����Ԫ�س��Ӳ�ʹ��x����
	QNode *s=Q->front->next; // ����ָ��
	if(!(GetHead(*Q, x))) // ��ȡ����Ԫ��
		return ERROR;
	Q->front->next = s->next; // �߼�ɾ��
	if(s==Q->rear) // ������ֻ��һ��Ԫ��
		Q->rear = Q->front;
	free(s); // ����ɾ��
	return OK;
}// DeQueue()

// ��������������
Status visit(BiNode *s)
{// ���ʶ���ָ��sָ��Ķ�����
	printf("%d ", s->data); // ������������
	return OK;
}// visit

Status Example(BiTree *T)
{// ���������ص�������T
	BiNode *s, *p, *q; // ����ָ��

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 1; // ������ֵ
	s->lchild = NULL; // ָ���򸳳�ֵ
	s->rchild = NULL;
	*T = s; // ���˽����Ϊ�����

	p = s; // pָ������Ԫ��Ϊ1���

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 2; // ������ֵ
	s->lchild = NULL; // ָ���򸳳�ֵ
	s->rchild = NULL;
	p->lchild = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 3; // ������ֵ
	s->lchild = NULL; // ָ���򸳳�ֵ
	s->rchild = NULL;
	p->rchild = s;
	
	q = p->rchild; // qָ������Ԫ��Ϊ3���
	p = p->lchild; // pָ������Ԫ��Ϊ2���

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 4; // ������ֵ
	s->lchild = NULL; // ָ���򸳳�ֵ
	s->rchild = NULL;
	p->lchild = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 5; // ������ֵ
	s->lchild = NULL; // ָ���򸳳�ֵ
	s->rchild = NULL;
	p->rchild = s;

	q = p->rchild; // qָ������Ԫ��Ϊ5���

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 6; // ������ֵ
	s->lchild = NULL; // ָ���򸳳�ֵ
	s->rchild = NULL;
	q->lchild = s;

	return OK;
}// Example()

Status PreOrder_re(BiTree T)
{// �ݹ鷽ʽ�������������T
	if(T!=NULL)
	{
		visit(T); // ���ʸ����
		PreOrder_re(T->lchild); // �������������
		PreOrder_re(T->rchild); // �������������
	}// if
	return OK;
}// PreOrder_re

Status InOrder_nr(BiTree T)
{// �ǵݹ��������������T
 /*
	����˼�룺ʹ��һ����ջ�洢���ɱ���ָ��ָ��δ����Ķ����㡣�ڱ���ָ��ǿջ�
	����ջ�ǿ�ʱ��������ѭ����������ָ��ǿ�ʱ������ָ��Ķ�������ջ������������
	�½�����������ָ��Ϊ�գ���ջ�����������ָ����ջ������½�����
	*/
	linkStack S; // ����ջ
	BiNode *p=T, *s; // �������ı���ָ��
	InitStack(&S); // ��ʼ������ջ

	while(p!=NULL||(!StackIsEmpty(S))) // ����ָ��ǿջ�ջ�ǿ�ʱ
	{
		if(p!=NULL) // ����ָ��ǿ�
		{
			Push(S, p); // p�����ջ
			p = p->lchild; // �����½���
		}// if
		else // ����ָ��Ϊ��
		{
			Pop(S, &s); // ��ջ
			visit(s); // ����
			p = s->rchild; // ��ջ�������½���
		}// else
	}// while
	printf("\n");

	return OK;
}// InOrder_nr

Status PreOrder_nr(BiTree T)
{// ����ǵݹ����������T
 /*
	����˼�룺ʹ�ø���ջ�洢�����������������Ϊ����Ķ�����ָ�룬ʹ��һָ������������Ľ�㡣
	�ڱ���ָ��ǿջ�ջ�ǿյ�����½�������ѭ����������ָ��ǿգ����ָ��ָ��Ķ�����������
	��ʹ�˽��ָ����ջ�����ű���ָ�������½�����������ָ��Ϊ�գ���ջ��ʹ����ָ����ջ������½�����
	*/
	linkStack S; // ����ջ
	BiNode *p=T; // �������ı���ָ��
	BiNode *s; // ����ָ��

	InitStack(&S); // ��ʼ������ջ
	while(p!=NULL||!(StackIsEmpty(S))) // p�ǿջ�ջ�ǿ�ʱ
	{
		if(p!=NULL) // ����ָ��ǿ�
		{
			visit(p); // ���ʽ��
			Push(S, p); // p�����ջ
			p = p->lchild; // �����½���
		}// if
		else // ����ָ���
		{
			Pop(S, &s);
			p = s->rchild;
		}// else
	}// while
	printf("\n");

	return OK;
}// PreOrder_nr()

Status PostOrder_nr(BiTree T)
{// ����ǵݹ����������T
 /*
	����˼�룺ʹ�ø���ջ�洢����������δ����Ķ�����ָ�룬ʹ��ָ��p������������ʹ��ָ��preָ����һ������Ľ�㣬
	Ĭ������£�ָ��preָ��NULL����ָ��p�ǿջ�ջ�ǿ�����£���������ѭ������ָ��p�ǿգ�˵�����������µ�δ�����㣬
	���˽����ջ�������������½�������ָ��pΪ�գ����Ȼ�ȡջ��Ԫ�أ����ж�ջ��Ԫ���Һ����Ƿ���preָ��Ľ����ͬ����
	��ͬ����ջ�����ջ��Ԫ�أ���������pre������ͬ����ջ��Ԫ�����½�����
	*/
	linkStack S; // ����ջ
	BiNode *p=T; // ����ָ��
	BiNode *pre=NULL; // ָ���ϴ�����Ľ��
	BiNode *s; // ����ָ��

	InitStack(&S); // ��ʼ������ջ
	while(p!=NULL||(!StackIsEmpty(S))) // ��ָ��p�ǿջ�ջ�ǿ�ʱ
	{
		if(p!=NULL) // ָ��p�ǿ�
		{
			Push(S, p); // ���˽����ջ
			p = p->lchild; // �����½���
		}// if
		else 
		{
			GetTop(S, &s); // ��ȡջ��Ԫ��
			if(s->rchild==NULL||s->rchild==pre) // ջ��Ԫ�ص��Һ��Ӹոձ����ʹ������Һ���
			{
				Pop(S, &s); // ��ջ
				visit(s); // ���ʽ��
				pre = s;
			}// if
			else
			{
				p = s->rchild; // ��ջ��Ԫ�����½���
			}// else
		}// else
	}// while
	printf("\n");
	return OK;
}// PostOrder_nr

Status LevelOrder(BiTree T)
{// ��α���������T
 // ����˼�룺ʹ�ø������У����Ƚ��������ӣ����Ӳ��������Ԫ�أ���������Ԫ�ص����Һ���������ӣ�ֱ������Ϊ�ա�
	linkQueue Q; // ��������
	AElem x; // �洢����Ԫ��

	InitQueue(&Q); // ��ʼ������
	EnQueue(&Q, T); // ��������
	while(!(QueueIsEmpty(Q))) // �����зǿ�ʱ
	{
		DeQueue(&Q, &x); // ����
		visit(x); // ���ʳ���Ԫ��
		if(x->lchild!=NULL) // �������
			EnQueue(&Q, x->lchild);
		if(x->rchild!=NULL) // �Һ������
			EnQueue(&Q, x->rchild);
	}// while
	printf("\n");
	return OK;
}// LevelOrder()

Status LevelOrder_re(BiTree T)
{// ���¶��ϡ����ҵ����α���������T
 /*
	����˼�룺ʹ��һ������ջ��һ���������С����Ƚ��������ӣ����ӽ����ӽ��ѹջ��ͬʱ�����ӽ�����Һ�����ӡ�
	�����յõ���ջ���ε�ջ���ɡ�
	*/
	linkStack S; // ����ջ
	linkQueue Q; // ��������
	AElem x; // ����ָ��
	
	InitStack(&S); // ��ʼ������ջ
	InitQueue(&Q); // ��ʼ����������
	EnQueue(&Q, T); // ��������
	while(!(QueueIsEmpty(Q))) // ���зǿ�ʱ
	{
		DeQueue(&Q, &x); // ����
		Push(S, x); // ѹջ
		if(x->lchild!=NULL) // �������
		{
			EnQueue(&Q, x->lchild);
		}// if
		if(x->rchild!=NULL) // �Һ������
		{
			EnQueue(&Q, x->rchild);
		}// if
	}// while
	while(!(StackIsEmpty(S))) // ���ε�ջ���
	{
		Pop(S, &x); // ��ջ
		visit(x); // ����
	}// while
	printf("\n");
	return OK;
}// LevelOrder_re

int Height(BiTree T)
{// ���ض�����T�ĸ߶�
 /*
	����˼�룺ʹ���������������������T�ĸ߶ȼ�Ϊջ��Ԫ����������
	*/
	linkStack S; // ����ջ
	BiNode *p=T; // ����ָ��
	BiNode *pre=NULL; // ָ����һ������Ľ��
	int height=0; // ������ʵʱ�߶�
	int maxHeight=0; // ���������߶�
	AElem x; // ����ָ��

	InitStack(&S); // ��ʼ��ջ
	while(p!=NULL||(!(StackIsEmpty(S)))) // p�ǿջ�ջ�ǿ�ʱ
	{
		if(p!=NULL) // �����½��
		{
			Push(S, p); // ѹջ
			height++; // ������ʵʱ�߶ȼ�1
			if(height>maxHeight) // ��������ǰ�߶ȴ������߶�
				maxHeight = height; // �޸Ķ��������߶�
			p = p->lchild; // �����½���
		}// if
		else // pΪ��
		{
			GetTop(S, &x); // ��ȡջ��Ԫ��
			if(x->lchild==NULL||x->rchild==pre) // ջ������Һ���������������ѱ���
			{
				Pop(S, &x); // ��ջ
				height--; // ������ʵʱ�߶ȼ�1
				pre = x; // �޸�pre
			}// if
			else // ջ������Һ�����δ����
			{
				p = x->rchild; // �����½���
			}
		}// else
	}// while

	return maxHeight;
}// Height()

// ������
void main()
{
	BiTree T;
	if(Example(&T))
		printf("�����������Ѽ��أ�\n");
	printf("�������߶�Ϊ%d\n", Height(T));
}