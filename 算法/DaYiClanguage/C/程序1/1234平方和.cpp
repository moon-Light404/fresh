#include<iostream>
using namespace std;
int sum(long a)
{
	int b;
	int s=0;
	for(int i=1;i<=9;i++)
	{
		b=a%10;
		a=a/10;
		s=s+b*b;
	}
	return s;
}
int main()
{
	cout<<"����С�������Ȧ����"<<endl<<endl<<endl<<"������һ����������"<<endl;
	int s=1;
	int b[100]={0};
	int m,a;
	cin>>a;
	b[0]=a;
	bool p=true;
	for(int i=1;i<=100;i++)
	{
		if(p==true)
		{
			m=sum(a);
			b[i]=m;
			a=m;
			s=s+1;
			for(int j=0;j<s-1;j++)
			{
				if(m==b[j])
				p=false;
			}
		}
		else 
		break;
	}
		cout<<"������:";
		for(int k=0;k<s;k++)
		{
			cout<<b[k]<<" ";
		
		}
		return 0;
	}
	
	

