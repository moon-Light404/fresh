#include <stdio.h>
#include <stdlib.h>
#define N 100
extern char *a;     /*��������������ǰ������*/
typedef struct node /*�������ṹ����*/
{
    char data;
    struct node *lchild,*rchild;
}binnode;
typedef binnode *bintree;

/*����creatbintree (���������������ǰ������(�ַ���a)����������t�Ĵ洢�ṹ*/
bintree  creatbintree()
{
    char ch=*a++;
    bintree t;
    if  (ch=='#')  t=NULL; // #��ʾNULL��ֵ
    else
    { t=(bintree)malloc(sizeof(binnode));
      t->data=ch;
      t->lchild=creatbintree();
      t->rchild=creatbintree();
    }
    return t;
}

void preorder(bintree t)  /*ǰ��ݹ����������*/
{
    if (t)
    {
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void postorder(bintree t)  /*����ݹ����������*/
{
    if (t)
    {

        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}

/*˳��ջ����*/
typedef struct
{
    bintree data[N];
    int top;
    int tag[N];
}seqstack;

void init(seqstack *s)   /*��ʼ����ջ*/
{
    s->top=-1;
}
int empty(seqstack *s)   /*�ж�ջ�Ƿ�Ϊ��*/
{
    if (s->top>-1) return 0;
    else return 1;
}
int full(seqstack *s)   /*�ж�ջ�Ƿ�Ϊ��*/
{
    if (s->top==N-1) return 1;
    else return 0;
}
void push(seqstack *s ,bintree x)   /*��ջ*/
{
    if (!full(s))
        s->data[++s->top]=x;
}
bintree pop(seqstack *s)			/*��ջ*/
{
    if (!empty(s))
        return s->data[s->top--];
}
