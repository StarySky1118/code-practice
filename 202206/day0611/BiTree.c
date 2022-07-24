#include<stdio.h>
#include<stdlib.h>

// ����״̬����
#define TRUE 1 // �߼�1
#define FALSE 0 // �߼�0
#define OK 1 // ������������
#define ERROR 0 // ������������
#define INFEASIBLE -1 
#define OVERFLOW -2 // ������
typedef int Status; // ����״̬����
typedef int Boolean; // ��������

// ����������Ԫ������
typedef int BiElem; // int��

// ��������洢�ṹ
typedef struct BiNode
{
	BiElem data; // ������
	struct BiNode *lchild, *rchild; // ���Һ���
}BiNode, *BiTree;

// �������ݽṹ����Ԫ������
typedef BiNode* AElem; // ������ָ��

// ����ջ�洢�ṹ
typedef struct SNode
{
	AElem data; // ������
	struct SNode *next; // ָ����
}SNode, *Stack;

// ����ջ����
Status InitStack(Stack *S)
{// ��ʼ������ջS
	SNode *s; // ����ָ��
	s = (SNode*)malloc(sizeof(SNode)); // �½���ͷ���
	s->data = NULL; // ��ʼ��������
	s->next = NULL; // ��ʼ��ָ����
	*S = s;
	return OK;
}// InitStack()

Boolean StackIsEmpty(Stack S)
{// �ж�ջS�Ƿ�Ϊ��
	if(S->next==NULL)
		return TRUE;
	return FALSE;
}// StackIsEmpty()

// ����������
Status Example(BiTree *T)
{// ���ذ���
	BiNode *s, *p, *q; // ����ָ��

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 1; // ������ֵ
	s->lchild = NULL; // ָ�����ʼ��
	s->rchild = NULL;

	*T = s; // �����ָ��ָ��
	p = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 2; // ������ֵ
	s->lchild = NULL; // ָ�����ʼ��
	s->rchild = NULL;

	p->lchild = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 3; // ������ֵ
	s->lchild = NULL; // ָ�����ʼ��
	s->rchild = NULL;

	p->rchild = s;

	q = p->rchild;
	p = p->lchild;

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 4; // ������ֵ
	s->lchild = NULL; // ָ�����ʼ��
	s->rchild = NULL;
	
	p->lchild = s;

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 5; // ������ֵ
	s->lchild = NULL; // ָ�����ʼ��
	s->rchild = NULL;

	p->rchild = s;
	
	q = p->rchild;

	s = (BiNode*)malloc(sizeof(BiNode)); // �½����
	s->data = 6; // ������ֵ
	s->lchild = NULL; // ָ�����ʼ��
	s->rchild = NULL;

	q->lchild = s;

	return OK;

}// Example()

Status visit(BiNode *p)
{// ����ָ��pָ�����������
	if(p==NULL)
		return ERROR;
	else
		printf("%d ", p->data);
	return OK;
}// visit()

Status PreOrder_r(BiTree T)
{// �ݹ鷽ʽ�������������T
	if(T==NULL) // ������Ϊ��
		return ERROR;
	else
	{
		visit(T); // ���ʸ����
		PreOrder_r(T->lchild); // ����������
		PreOrder_r(T->rchild); // ����������
	}// else
	return OK;
}// PreOrder_r()

// ������
void main()
{
	BiTree T;
	Example(&T);
	
}
