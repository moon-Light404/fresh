#include<iostream>
using namespace std;
int main()
{
	int i=2,k,m;
	while(i<101)
	{  m=1,k=2;
		while(k<=i/2)
		{
			if(i%k==0)
			{
				m=0; break;
			}
			k++;
		}
		if(m)  cout<<i<<" " ;
		i++;
	}
	return 0;
}
