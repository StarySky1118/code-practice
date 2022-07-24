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
{// �ǵݹ鷽ʽ����������������T
 /*
	����˼�룺ʹ�ø���ջ�洢�ѱ�������δ����Ľ�㡣ʹ��ָ��p������������㣬��p�ǿջ�ջ�ǿ�ʱ����������ѭ����
	��p�ǿգ���p��ָ���ѹջ�����������½�������pΪ�գ���ջ������ջ�������Ϊ�գ�����������pre����pre�Һ���
	Ϊ�գ�������������ջ��㡣
	*/
	ThreadNode *p=T; // ����ָ��
	ThreadNode *pre=NULL; // ָ����һ������Ľ��
	AElem x; // ����ָ��
	linkStack S; // ����ջ

	InitStack(&S); // ��ʼ������ջ
	while(p!=NULL||!StackIsEmpty(S)) // p�ǿջ�ջ�ǿ�ʱ
	{	
		if(p!=NULL)
		{
			Push(S, p); // p��ָ���ѹջ
			p = p->lchild; // p�����½���
		}// if
		else
		{
			Pop(S, &x); // ��ջ
			if(x->lchild==NULL) // ��ջ�������Ϊ��
			{
				x->lchild = pre;
				x->ltag = TRUE;
			}// if
			if(pre!=NULL&&pre->rchild==NULL) // ��һ����������Һ���Ϊ��
			{
				pre->rchild = x;
				pre->rtag = TRUE;
			}// if
			pre = x; // �޸���һ��������
			p = x->rchild; // ��������
		}// else
	}// while

	return OK;
}// CreateInThread()

ThreadNode* FirstNode(ThreadTree T)
{// ������TΪ��������������������������е��׸����ָ��
 /*
	����˼�룺�����־ΪFALSE������£�һֱ�����½�����ֱ��������־ΪTRUE��
	*/
	ThreadNode *p=T; // ����ָ��
	if(p==NULL) // ������Ϊ��
		return NULL;
	while(p->ltag==FALSE) // ����ָ��ָ������
	{
		p = p->lchild; // �����½���
	}// while
	return p;
}// FirstNode()

ThreadNode* NextNode(ThreadNode *p)
{// ������������������p��ָ�����������������е���һ�����
 /*
	����˼�룺��p��ָ����ұ�־ΪTRUE������p������������p��ָ����ұ�־ΪFALSE��������p���Һ���Ϊ���Ķ����������������
	���׸���㡣
	*/
	if(p==NULL)
		return NULL;
	if(p->rtag==TRUE) // p��������
		return p->rchild;
	else
		return FirstNode(p->rchild);
}// NextNode()

Status InOrder(ThreadTree T)
{// ��������������������T
 // ʹ��һ����ָ��p��������������е��׸���㿪ʼ��������
	ThreadNode *p=FirstNode(T); // ����ָ��
	while(p!=NULL)
	{
		visit(p); // ���ʽ��
		p = NextNode(p); // ��������
	}// while
	printf("\n");
	return OK;
}// InOrder()

// ������
void main()
{
	ThreadTree T;
	ThreadNode *s;
	if(Example(&T))
		printf("�����������ѳ�ʼ����\n");
	if(CreateInThread(T))
		printf("����������������\n");
	InOrder(T);
}