#include <stdio.h>
#include <stdlib.h>
#define N 100
extern char *a;     /*存放扩充二叉树的前序序列*/
typedef struct node /*二叉树结构定义*/
{
    char data;
    struct node *lchild,*rchild;
}binnode;
typedef binnode *bintree;

/*函数creatbintree (根据扩充二叉树的前序序列(字符串a)建立二叉树t的存储结构*/
bintree  creatbintree()
{
    char ch=*a++;
    bintree t;
    if  (ch=='#')  t=NULL; // #表示NULL空值
    else
    { t=(bintree)malloc(sizeof(binnode));
      t->data=ch;
      t->lchild=creatbintree();
      t->rchild=creatbintree();
    }
    return t;
}

void preorder(bintree t)  /*前序递归遍历二叉树*/
{
    if (t)
    {
        printf("%c",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
void postorder(bintree t)  /*后序递归遍历二叉树*/
{
    if (t)
    {

        postorder(t->lchild);
        postorder(t->rchild);
        printf("%c",t->data);
    }
}

/*顺序栈定义*/
typedef struct
{
    bintree data[N];
    int top;
    int tag[N];
}seqstack;

void init(seqstack *s)   /*初始化空栈*/
{
    s->top=-1;
}
int empty(seqstack *s)   /*判断栈是否为空*/
{
    if (s->top>-1) return 0;
    else return 1;
}
int full(seqstack *s)   /*判断栈是否为满*/
{
    if (s->top==N-1) return 1;
    else return 0;
}
void push(seqstack *s ,bintree x)   /*进栈*/
{
    if (!full(s))
        s->data[++s->top]=x;
}
bintree pop(seqstack *s)			/*出栈*/
{
    if (!empty(s))
        return s->data[s->top--];
}
