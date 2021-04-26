#include <stdio.h>
#include <stdlib.h>
/**************************************/
/* ����ʵ�ֵ�ͷ�ļ����ļ���slnklist.h */
/**************************************/
 typedef int datatype;
 typedef struct link_node{
   datatype info;
   struct link_node *next;
 }node;
typedef node *linklist;
/******************************************/
/*�������ƣ�creatbystack() 		       	  */
/*�������ܣ�ͷ�巨������ͷ���ĵ�����    */
/******************************************/
linklist creatbystack()
{

    linklist  head,s;
    datatype x;
    head=(linklist)malloc(sizeof(node));
    head->next=NULL;

    printf("�������������У��ո�ֿ�����0������:\n");
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
/*�������ƣ�creatbyqueue() 			   */
/*�������ܣ�β�巨������ͷ���ĵ����� */
/***************************************/
linklist creatbyqueue()
{
    linklist head,r,s;
    datatype x;
    head=r=(linklist)malloc(sizeof(node));
    head->next=NULL;
    printf("�������������У��ո�ֿ�����0������:\n");
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
/*�������ƣ�print()		 			 */
/*�������ܣ������ͷ���ĵ�����      */
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
/*�������ƣ�creatLink() 			      */
/*�������ܣ����ļ��ж���n�����ݹ��ɵ����� */
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
/*�������ƣ�delList()		 		 */
/*�������ܣ��ͷŴ�ͷ���ĵ�����      */
/**********************************/
void delList(linklist head)
{ linklist p=head;
  while (p)
  { head=p->next;
    free(p);
    p=head;
  }
}
