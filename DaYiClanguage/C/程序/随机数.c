#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 void main()
 {
 	int i,j;
 	srand(time(0));
 		for(j=0;j<9;j++)
 		{
 			printf("%d\n",rand());
		 }
 		
 		srand(time(0));
 		for(j=0;j<9;j++)
 		{
 			printf("%d\n",rand());
		 }
	}
 
