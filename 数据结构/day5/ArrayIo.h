#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*�Գ���Ϊn����������������*/
void input( int a[],int n)
{   int i;
   printf("������ %d ��������\n",n);
   for (i=0;i<n;i++)
      scanf("%d",&a[i]);
}
/*�������Ϊn����������*/
void print(int a[ ],int n)
{  int i;
   printf("\n����������ǣ�\n");
   for (i=0;i<n;i++)
     { if (i%10==0) printf("\n");
	   printf("%6d",a[i]);
     }
  printf("\n");
}
void init(int a[],int n)
{	int i;
	srand(time(NULL));
	for (i=0;i<n;i++)
		a[i]=rand()%1000;
}
