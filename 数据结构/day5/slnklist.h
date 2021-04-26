#include <stdio.h>
#include <stdlib.h>
/**************************************/
/* 链表实现的头文件，文件名slnklist.h */
/**************************************/
 typedef int datatype;
 typedef struct link_node{
   datatype info;
   struct link_node *next;
 }node;
typedef node *linklist;
/******************************************/
/*函数名称：creatbystack() 		       	  */
/*函数功能：头插法建立带头结点的单链表    */
/******************************************/
linklist creatbystack()
{

    linklist  head,s;
    datatype x;
    head=(linklist)malloc(sizeof(node));
    head->next=NULL;

    printf("请输入整数序列（空格分开，以0结束）:\n");
    scanf("%d",&x);
    while (x!=0)
    {
        s=(linklist)malloc(sizeof(node));
        s->info=x;

        s->next=head->next;
        head->next=s;

        scanf("%d",&x);
    }
    return head;
}
/***************************************/
/*函数名称：creatbyqueue() 			   */
/*函数功能：尾插法建立带头结点的单链表 */
/***************************************/
linklist creatbyqueue()
{
    linklist head,r,s;
    datatype x;
    head=r=(linklist)malloc(sizeof(node));
    head->next=NULL;
    printf("请输入整数序列（空格分开，以0结束）:\n");
    scanf("%d",&x);
    while (x!=0)
    {
         s=(linklist)malloc(sizeof(node));
         s->info=x;
         r->next=s;
         r=s;
         scanf("%d",&x);
   }
    r->next=NULL;
    return head;
}
/**********************************/
/*函数名称：print()		 			 */
/*函数功能：输出带头结点的单链表      */
/**********************************/
void print(linklist head)
{
    linklist p;
    int i=0;
    p=head->next;
    printf("List is:\n");
    while(p)
    {
        printf("%7d",p->info);
        i++;
        if (i%10==0)    printf("\n");
        p=p->next;
    }
    printf("\n");

}

/******************************************/
/*函数名称：creatLink() 			      */
/*函数功能：从文件中读入n个数据构成单链表 */
/******************************************/
linklist creatLink(char *f, int n)
{
    FILE *fp;
    int i;
    linklist s,head,r;
    head=r=(linklist)malloc(sizeof(node));
    head->next=NULL;
    fp=fopen(f,"r");
    if (fp==NULL)
        return head;
    else
    {
         for (i=0;i<n;i++)
            {
                s=(linklist)malloc(sizeof(node));
                fscanf(fp,"%d",&(s->info));
                r->next=s;
                r=s;
            }
        r->next=NULL;
        fclose(fp);
        return head;
    }
}


/**********************************/
/*函数名称：delList()		 		 */
/*函数功能：释放带头结点的单链表      */
/**********************************/
void delList(linklist head)
{ linklist p=head;
  while (p)
  { head=p->next;
    free(p);
    p=head;
  }
}
