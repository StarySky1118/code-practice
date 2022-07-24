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
	struct BiNode* lchild, * rchild; // ���Һ���ָ����
}BiNode, * BiTree;

// �������ݽṹ�������Ԫ������
typedef BiNode* AElem; // �������ݽṹ����Ԫ�����ͣ�������ָ��

// ����ջ�洢�ṹ
typedef struct SNode
{
	AElem data; // ������
	struct SNode* next; // ָ����
}SNode, * linkStack;

// �������д洢�ṹ
typedef struct QNode
{// ���н��
	AElem data; // ������
	struct QNode* next; // ָ����
}QNode;
typedef struct
{// ����
	QNode* front, * rear; // ���׶�βָ��
}linkQueue;

Status visit(BiNode*); // ����visit()����

// -----����ջ��������-----
Status InitStack(linkStack* S)
{// ��ʼ��ջS
	SNode* s=NULL; // ����ָ��
	s = (SNode*)malloc(sizeof(SNode)); // �½���ͷ���
	s->data = NULL; // �����򸳳�ֵ
	s->next = NULL; // ָ���򸳳�ֵ
	*S = s; // ջָ��ָ����½����
	return OK;
}// InitStack()

boolean StackIsEmpty(linkStack S)
{// �ж�ջS�Ƿ�Ϊ��
	if (S->next == NULL)
		return TRUE;
	return FALSE;
}// StackIsEmpty()

Status DisplayStack(linkStack S)
{// ���ӻ������ջS
 /*
	ʹ�ñ���ָ��p���������ջ����ջ�׵�����Ԫ��
 */
	SNode* p = S->next; // ����ָ��
	while (p != NULL) // p�ǿ�ʱ
	{
		visit(p->data); // ����������
		printf("\n");
		p = p->next; // ��������
	}// while
	return OK;
}// DisplayStack()

Status GetTop(linkStack S, AElem* x)
{// ��ȡջ��Ԫ�ز�ʹ��x����
	if (S->next == NULL) // ջΪ��
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
	SNode* s; // ����ָ��
	s = (SNode*)malloc(sizeof(SNode)); // �½����
	s->data = x; // ������ֵ
	s->next = S->next; // ����ָ����
	S->next = s;
	return OK;
}// Push()

Status Pop(linkStack S, AElem* x)
{// ��ջ��ʹ��x���յ�������������ֵ
 /*
	����˼�룺���Ƚ���ջ��Ԫ��ֵ���ж��Ƿ�ɵ�ջ�����ɵ�ջ��ɾ��ջ����㡣
 */
	SNode* s = S->next; // ����ָ��
	if (!(GetTop(S, x))) // �޷���ȡջ��Ԫ��˵��ջΪ�գ���ʱ�޷���ջ
		return ERROR;
	S->next = s->next; // �߼�ɾ��
	free(s); // ����ɾ��
	return OK;
}// Pop()

// -----�������в�������-----
Status InitQueue(linkQueue* Q)
{// ��ʼ��������Q
 /*
	����˼�룺������ͷ��㣬��ʹ���׶�βָ���ָ��˽��
	*/
	QNode* s; // ����ָ��
	s = (QNode*)malloc(sizeof(QNode)); // �½���ͷ���
	s->data = NULL; // ��ʼ��������
	s->next = NULL; // ��ʼ��ָ����
	Q->front = s; // ����ָ��ָ����½����
	Q->rear = s; // ��βָ��ָ���½����
	return OK;
}// InitQueue()

boolean QueueIsEmpty(linkQueue Q)
{// �ж϶����Ƿ�Ϊ��
	if (Q.front == Q.rear)
		return TRUE;
	return FALSE;
}// QueueIsEmpty()

Status QueueDisplay(linkQueue Q)
{// ���ӻ��������Q
	QNode* p = Q.front->next; // ����ָ��
	while (p != NULL)
	{
		visit(p->data);
		p = p->next;
	}// while
	printf("\n");
	return OK;
}// QueueDisplay()

Status GetHead(linkQueue Q, AElem* x)
{// ��ȡ����Q����Ԫ�ز�ʹ��x����
	if (QueueIsEmpty(Q)) // ����Ϊ��
		return ERROR;
	*x = Q.front->next->data;
	return OK;
}// GetHead()

Status EnQueue(linkQueue* Q, AElem x)
{// ������Ԫ��x���
 // ����˼�룺�����½���㣬Ȼ��β�巨�����½��
	QNode* s; // ����ָ��
	s = (QNode*)malloc(sizeof(QNode)); // �½����
	s->data = x; // ������ֵ
	s->next = Q->rear->next;
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}// EnQueue()

Status DeQueue(linkQueue* Q, AElem* x)
{// ����Ԫ�س��Ӳ�ʹ��x����
	QNode* s = Q->front->next; // ����ָ��
	if (!(GetHead(*Q, x))) // ��ȡ����Ԫ��
		return ERROR;
	Q->front->next = s->next; // �߼�ɾ��
	if (s == Q->rear) // ������ֻ��һ��Ԫ��
		Q->rear = Q->front;
	free(s); // ����ɾ��
	return OK;
}// DeQueue()

// ��������������
Status visit(BiNode* s)
{// ���ʶ���ָ��sָ��Ķ�����
	printf("%d ", s->data); // ������������
	return OK;
}// visit

Status Example(BiTree* T)
{// ���������ص�������T
	BiNode* s=NULL, * p=NULL, * q=NULL; // ����ָ��

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
	if (T != NULL)
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
	BiNode* p = T, * s; // �������ı���ָ��
	InitStack(&S); // ��ʼ������ջ

	while (p != NULL || (!StackIsEmpty(S))) // ����ָ��ǿջ�ջ�ǿ�ʱ
	{
		if (p != NULL) // ����ָ��ǿ�
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
	BiNode* p = T; // �������ı���ָ��
	BiNode* s; // ����ָ��

	InitStack(&S); // ��ʼ������ջ
	while (p != NULL || !(StackIsEmpty(S))) // p�ǿջ�ջ�ǿ�ʱ
	{
		if (p != NULL) // ����ָ��ǿ�
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
	BiNode* p = T; // ����ָ��
	BiNode* pre = NULL; // ָ���ϴ�����Ľ��
	BiNode* s; // ����ָ��

	InitStack(&S); // ��ʼ������ջ
	while (p != NULL || (!StackIsEmpty(S))) // ��ָ��p�ǿջ�ջ�ǿ�ʱ
	{
		if (p != NULL) // ָ��p�ǿ�
		{
			Push(S, p); // ���˽����ջ
			p = p->lchild; // �����½���
		}// if
		else
		{
			GetTop(S, &s); // ��ȡջ��Ԫ��
			if (s->rchild == NULL || s->rchild == pre) // ջ��Ԫ�ص��Һ��Ӹոձ����ʹ������Һ���
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
	while (!(QueueIsEmpty(Q))) // �����зǿ�ʱ
	{
		DeQueue(&Q, &x); // ����
		visit(x); // ���ʳ���Ԫ��
		if (x->lchild != NULL) // �������
			EnQueue(&Q, x->lchild);
		if (x->rchild != NULL) // �Һ������
			EnQueue(&Q, x->rchild);
	}// while
	printf("\n");
	return OK;
}// LevelOrder()

boolean IsComplete(BiTree T)
{// �ж϶�����T�Ƿ�Ϊ��ȫ������
 /*
	����˼�룺ʹ�ø������С����Ƚ��������ӣ��ڶ��зǿ�ʱ��������ѭ�������ӣ�������Ԫ�ط�NULL��
	�����Һ��ӣ����޽�NULL����ӣ�������Ԫ��ΪNULL�����ν�����Ԫ�س����ж��Ƿ��зǿ�Ԫ�ء�
 */
	linkQueue Q; // ��������
	AElem x=NULL; // ����ָ��
	boolean flag = TRUE; // ��־������Ĭ��ΪTRUE

	InitQueue(&Q); // ��ʼ������
	EnQueue(&Q, T); // ��������
	while (!QueueIsEmpty(Q)) // �����зǿ�ʱ
	{
		DeQueue(&Q, &x); // ����
		if (x != NULL) // ����Ԫ�ط�NULL
		{
			EnQueue(&Q, x->lchild); // ����Ԫ���������
			EnQueue(&Q, x->rchild); // ����Ԫ���Һ������
		}// if
		else // ����Ԫ��ΪNULL
		{
			while (!QueueIsEmpty(Q)) // ���зǿ�ʱ
			{
				DeQueue(&Q, &x); // ����
				if (x != NULL) // ����Ԫ�ط�NULL
				{
					flag = FALSE; // �ñ�־����Ϊ��
					break;
				}// if
			}// while
		}// else
	}// while

	return flag;
}// IsComplete()

Status Exchange(BiTree T)
{// ��������T���н��������������н���
 /*
	ʹ�õݹ鷽ʽ�����ȶ��������ݹ���ã�Ȼ�����Һ���ָ�뻥���������������ݹ���á�	
 */
	BiNode* s=NULL; // ����ָ��
	if (T != NULL)
	{
		Exchange(T->lchild); // ����������
		Exchange(T->rchild); // ����������
		s = T->lchild;
		T->lchild = T->rchild;
		T->rchild = s;
	}// if

	return TRUE;
}// Exchange()

int PreOrder_k(BiTree T, int k)
{// ���ض�����������������е�k������ֵ
 /*
	����˼�룺ʹ�ø���ջ�ṹ����ʼ������ʹ��ָ��p������������㣬ʹ��num��¼����Ľ�������
	ʹ��return_val����ֵ��pĬ��ָ�����㣬��p�ǿջ�ջ�ǿ�ʱ����������ѭ������p�ǿգ�����
	���ѹջ��num++�������½�������num=k���޸�reutrn_valֵ����pΪ�գ���ջ����ջԪ�����½�����
	��󷵻�return_valֵ��
 */
	linkStack S; // ����ջ
	BiNode* p=T; // ����ָ��
	AElem x = NULL; // ����ָ��
	int num=0; // ����Ľ����
	int return_val = 999; // ����ֵ

	InitStack(&S); // ��ʼ��ջ
	while (p != NULL || !(StackIsEmpty(S))) // p�ǿջ�ջ�ǿ�ʱ
	{
		if (p != NULL) // p�ǿ�
		{
			Push(S, p); // ���ý��ѹջ
			num++; // ������+1
			if (num == k)
			{
				return_val = p->data;
				break;
			}// if
			p = p->lchild; // �����½���
		}// if
		else // pΪ��
		{
			Pop(S, &x); // ��ջ
			p = x->rchild; // ��ջԪ�����½���
		}// else
	}// while

	return return_val;
}// PreOrder_k()

// ������
int main()
{
	BiTree T;
	if (Example(&T))
		printf("�����������Ѽ��أ�\n");
	PreOrder_nr(T);
	return 0;
}