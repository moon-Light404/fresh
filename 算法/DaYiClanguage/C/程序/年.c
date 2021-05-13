#include <stdio.h>

struct{
	int year;
	int month;
}Date;
 int main()
 {
   scanf("%d%d",&Date.year,&Date.month);
   int date;
   switch(Date.month)
   {
   	case 1:date=31;break;
   	case 2:date=28;break;
   	case 3:date=31;break;
   	case 4:date=30;break;
   	case 5:date=31;break;
   	case 6:date=30;break;
   	case 7:date=31;break;
   	case 8:date=31;break;
   		case 9:date=30;break;
   		case 10:date=31;break;
   			case 11:date=30;break;
   				case 12:date=31;break;
   				

					 
	   }	
	   	
   				if(Date.month==2)
   				{
   					if((Date.year%4==0&&Date.year%100!=0)||Date.year%400==0)
   					date+=1;
				   }
printf("%d\n",date);
return 0;
 }

