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
typedef struct LNode 
{// ���н��
	AElem data; // ������
	struct LNode *next; // ָ����
}LNode;
typedef struct
{// ����
	LNode *front, *rear; // ���׶�βָ��
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
	LNode *s; // ����ָ��
	s = (LNode*)malloc(sizeof(LNode)); // �½���ͷ���
	s->data = NULL; // ��ʼ��������
	s->next = NULL; // ��ʼ��ָ����
	Q->front = s; // ����ָ��ָ����½����
	Q->rear = s; // ��βָ��ָ���½����
	return OK;
}// InitQueue()

boolean QueueIsEmpty(linkQueue Q)
{// 

}

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

// ������
void main()
{
	BiTree T;
	linkQueue Q;
	if(Example(&T))
		printf("�����������Ѽ��أ�\n");
	if(InitQueue(&Q))
		printf("�����ѳ�ʼ����\n");
}