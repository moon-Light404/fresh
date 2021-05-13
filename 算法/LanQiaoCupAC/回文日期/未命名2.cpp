#include <iostream>
#include <iomanip>
using namespace std;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isok(int x)//判断闰年
{
	if( x%400==0 )	return true;
	if( x%100==0 )	return false;
	if( x%4==0 )	return true;
	return false;
}
int main()
{
	int x; 
	cin >> x;
	int year=x/10000;//输入的年 
	int month=x%10000/100;//输入的月 
	int day=x%100;//输入的日 
	int flag=0;
	//1321  1231 
	int m=year%10*10+year%100/10;//年份对应的回文月 
	int n=year/100%10*10+year/1000;//年份对应的回文日 起始数据先记录下来-----》》》》》》》》》 
	
	if(isok(year)) a[1]=29;
	else a[1]=28;
	
	if((m>month&&m<13&&n<=a[m-1])||(m==month&&n>day&&n<=a[m-1])){//当年对应的回文日期在输入的日期之后
		cout<<setw(4)<<setfill('0')<<year<<setw(2)<<setfill('0')<<m<<setw(2)<<setfill('0')<<n<<endl;//输出当年对应的回文日期
		flag=1;
		if((year/1000!=year%10)&&(year%100==m%10*10+m/10)&&(m==n)){ //判断当年对应的回文日期是否是ABAB BABA型日期 
			cout<<setw(4)<<setfill('0')<<year<<setw(2)<<setfill('0')<<m<<setw(2)<<setfill('0')<<n<<endl;
			return 0;//计算完成了 
		}
	}
		
	while(year<=8999){
		year++;	//只要加年份就可以,月份可以根据性质来设置！！！！ 
		month=year%10*10+year%100/10;//年份回文月 
		day=year/100%10*10+year/1000;//年份回文日
		if(month>12||day>31) continue;//不符合常理直接继续循环 
		
		if(isok(year)) a[1]=29;
		else a[1]=28;//判断闰年 
		
		if((flag!=1)&&month>0&&month<13&&day>0&&day<=a[month-1]){//找回文型 
			cout<<setw(4)<<setfill('0')<<year<<setw(2)<<setfill('0')<<month<<setw(2)<<setfill('0')<<day<<endl;
			flag=1;
		}
	
		if((year/1000!=year%10)&&(year%100==month%10*10+month/10)&&(month==day)){//找ABABBABA型 
			cout<<setw(4)<<setfill('0')<<year<<setw(2)<<setfill('0')<<month<<setw(2)<<setfill('0')<<day<<endl;
			break;
		}
	}
	
	return 0;
}
