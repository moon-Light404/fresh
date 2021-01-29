#include<iostream>
using namespace std;
int main()
{   
   int a;
	cin>>a;
	if(90<=a && a<=100)
	cout<<"ÓÅ";
	else if(80<=a && a<90)
	cout<<"Á¼";
	else if(60<=a && a<80)
	cout<<"ÖÐ";
	else cout<<"²î";
	return 0; 
}
