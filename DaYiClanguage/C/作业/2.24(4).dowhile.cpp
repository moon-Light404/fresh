#include<iostream>
using namespace std;
int main()
{
	int i=2,k,m;
	do
	{m=1,k=2;
	do{
		if(i%k==0 &&i!=k){m=0; 
		 break;
		   }
		   k++;	
	}while(k<=i/2);
		if(m)  cout<<i<<" ";
		i++;
	}while(i<101);	

     return 0;
}
