#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*对长度为n的整型数组作输入*/
void input( int a[],int n)
{   int i;
   printf("请输入 %d 个整数：\n",n);
   for (i=0;i<n;i++)
      scanf("%d",&a[i]);
}
/*输出长度为n的整型数组*/
void print(int a[ ],int n)
{  int i;
   printf("\n数组的内容是：\n");
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
