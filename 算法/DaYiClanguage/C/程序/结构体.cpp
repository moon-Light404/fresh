#include<stdio.h>
#include<stdbool.h>



struct date{
	int month;
	int day;
	int year;
	
};
bool isleap(struct date d);
int numberofDAYs(struct date d);

int main()
{
	struct date today ,tommorrow;
	printf("Enter today's date (mm dd yyyy):");
	scanf("%i %i %i",&today.month, &today.day, &today.year);
	
	if(today.day!=numberofDAYs(today)){
		tommorrow.day=today.day+1;
		tommorrow.month=today.month;
		tommorrow.year=today.year;
	}
	else if (today.month==12)
	{
		tommorrow.day=1;
		tommorrow.month=1;
		tommorrow.year=today.year+1;
	}
	else{
		tommorrow.day=1;
		tommorrow.month=today.month+1;
		tommorrow.year=today.year;
	}
	printf("Tommorow's date is %i %i %i\n",tommorrow.year,tommorrow.month,tommorrow.day);
	return 0;
}
int numberofDAYs(struct date d)
{
	int days;
	const int dayspermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(d.month ==2 && isleap(d))
	days =29;
	else 
	days =dayspermonth[d.month-1];
	return days;
}
bool isleap(struct date d)
{
	int flase =0; int true =1;
 bool leap = flase;
if( d.year %4 ==0 && d.year %100!=0 || d.year %400==0)
leap =true ;
return leap ;
}
