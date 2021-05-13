#include<stdio.h>

int main()
{
	int arry[3][4]={{0,1,2,3},
	             {4,5,6,7},
				 {8,9,10,11}};
				 
	
	int *p= arry;
	int i;
  printf("p:%p,arry:%p\n",p,arry);
  printf("p+1£º%p,arry+1:%p\n",p+1,arry+1);
   
	return 0;
 } 
