#include<iostream>
using namespace std;
int main()
{    
int i,k,m;
	for( i=2;i<=1000000;i++)
	{
		m=1;
		
		for(k=2;k<=i/2;k++)
		{
			if(i%k==0) {
				m=0; break;
			}
		}
		if(m)
	cout<<i<<" ";
	}
	
    return 0;
}
