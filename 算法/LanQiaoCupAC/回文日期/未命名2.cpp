#include <iostream>
#include <iomanip>
using namespace std;
int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isok(int x)//�ж�����
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
	int year=x/10000;//������� 
	int month=x%10000/100;//������� 
	int day=x%100;//������� 
	int flag=0;
	//1321  1231 
	int m=year%10*10+year%100/10;//��ݶ�Ӧ�Ļ����� 
	int n=year/100%10*10+year/1000;//��ݶ�Ӧ�Ļ����� ��ʼ�����ȼ�¼����-----������������������ 
	
	if(isok(year)) a[1]=29;
	else a[1]=28;
	
	if((m>month&&m<13&&n<=a[m-1])||(m==month&&n>day&&n<=a[m-1])){//�����Ӧ�Ļ������������������֮��
		cout<<setw(4)<<setfill('0')<<year<<setw(2)<<setfill('0')<<m<<setw(2)<<setfill('0')<<n<<endl;//��������Ӧ�Ļ�������
		flag=1;
		if((year/1000!=year%10)&&(year%100==m%10*10+m/10)&&(m==n)){ //�жϵ����Ӧ�Ļ��������Ƿ���ABAB BABA������ 
			cout<<setw(4)<<setfill('0')<<year<<setw(2)<<setfill('0')<<m<<setw(2)<<setfill('0')<<n<<endl;
			return 0;//��������� 
		}
	}
		
	while(year<=8999){
		year++;	//ֻҪ����ݾͿ���,�·ݿ��Ը������������ã������� 
		month=year%10*10+year%100/10;//��ݻ����� 
		day=year/100%10*10+year/1000;//��ݻ�����
		if(month>12||day>31) continue;//�����ϳ���ֱ�Ӽ���ѭ�� 
		
		if(isok(year)) a[1]=29;
		else a[1]=28;//�ж����� 
		
		if((flag!=1)&&month>0&&month<13&&day>0&&day<=a[month-1]){//�һ����� 
			cout<<setw(4)<<setfill('0')<<year<<setw(2)<<setfill('0')<<month<<setw(2)<<setfill('0')<<day<<endl;
			flag=1;
		}
	
		if((year/1000!=year%10)&&(year%100==month%10*10+month/10)&&(month==day)){//��ABABBABA�� 
			cout<<setw(4)<<setfill('0')<<year<<setw(2)<<setfill('0')<<month<<setw(2)<<setfill('0')<<day<<endl;
			break;
		}
	}
	
	return 0;
}
