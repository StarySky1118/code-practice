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

//-----�������������Ԫ��-----
typedef int TreeElem; // int�� 

//-----�����������洢�ṹ-----
typedef struct ThreadNode
{
	TreeElem data; // ������
	struct ThreadNode *lchild, *rchild; // ��������ָ��
	boolean ltag, rtag; // ���ұ�־
}ThreadNode, *ThreadTree;

//-----�������ݽṹ����Ԫ������-----
typedef ThreadNode* AElem;

//-----����ջ�洢�ṹ-----
typedef struct SNode
{
	AElem data; // ������
	struct SNode *next; // ָ����
}SNode, *linkStack;

//-----����ջ��ز���-----
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

//-----������������ز���-----
Status visit(ThreadNode *s)
{// �����ָ��Ķ������������
	if(s==NULL)
		return ERROR;
	printf("%d ", s->data);
	return OK;
}// visit()

Status Example(ThreadTree *T)
{// ���������ص�����������T
	ThreadNode *s, *p, *q; // ����ָ��
	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // �½����
	s->data = 1;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	*T = s;
	p = s;

	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // �½����
	s->data = 2;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	p->lchild = s;

	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // �½����
	s->data = 3;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	p->rchild = s;

	q = p->rchild;
	p = p->lchild;

	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // �½����
	s->data = 4;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	p->lchild = s;
	
	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // �½����
	s->data = 5;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	p->rchild = s;

	q = p->rchild;

	s = (ThreadNode*)malloc(sizeof(ThreadNode)); // �½����
	s->data = 6;
	s->lchild = NULL;
	s->ltag = FALSE;
	s->rchild = NULL;
	s->rtag = FALSE;

	q->lchild = s;

	return OK;
}// Example()

Status CreateInThread(ThreadTree T)
{// ����������������T
 /* ����˼�룺ʹ��ָ��p�������������н�㡣ָ��preָʾ��һ������Ľ�㡣��ָ��p�ǿջ�ջ�ǿ�ʱ��������ѭ����
	��ָ��p�ǿգ����˽����ջ�������½�������ָ��pΪ�գ���ջ�����˽��ǰ��ΪNULL������ǰ���޸�Ϊpre��p������
	������ͬʱ����pre�ĺ��ΪNULL��������޸ĵ��˽�㡣
*/
	ThreadNode *p=T; // ���������ָ��
	AElem x;
	ThreadNode *pre=NULL; // ָʾ��һ������Ľ��
	linkStack S; // ����ջ

	InitStack(&S); // ��ʼ��ջ
	while(p!=NULL||(!(StackIsEmpty(S)))) // p�ǿջ�ջ�ǿ�
	{
		if(p!=NULL) // pָ���½��
		{
			Push(S, p); // �½����ջ
			p = p->lchild; // �����½���
		}// if
		else // pΪ��
		{
			Pop(S, &x); // ��ȡջ��Ԫ��
			if(x->lchild==NULL) // ��ջ�������Ϊ��
			{
				x->lchild = pre;
				x->ltag = TRUE;
			}// if
			if(pre!=NULL&&pre->rchild==NULL) // pre�Һ���Ϊ��
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

// ������
void main()
{
	ThreadTree T;
	if(Example(&T))
		printf("�����������ѳ�ʼ����\n");
	if(CreateInThread(T))
		printf("����������������\n");
}