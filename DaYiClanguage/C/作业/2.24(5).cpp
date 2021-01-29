#include<iostream>
using namespace std;
int main()
{   
    enum color {red,yellow,blue,white,black};
    enum color p;
    int n,l,i,j,k;
    n=0;
    for(i=red;i<=black;i++)
      for(j=red;j<=black;j++)
      if(i!=j)
      {
      for(k=red;k<=black;k++)
      if((k!=i)&&(k!=j))
      {
      	n++;
      	cout.width(4);cout<<n;
      	for(l=1;l<=3;++l)
      	{
      		switch(l)
      		{
      			case 1:p=(enum color)i;break;
      			case 2:p=(enum color)j;break;
      			case 3:p=(enum color)k;break;
      			default:break;
			  }
			  switch(p)
			  {
			  	case red:cout<<"red  ";break;
			  	case yellow:cout<<"yellow ";break;
			  	case blue:cout<<"blue  ";break;
				case white: cout<<"white ";break;
				case black:cout<<"black "; break;
				default:break;
			  }
		  }
		 cout<<endl;
	  }
}
cout<<"total:"<<n<<endl;
return 0;
}
