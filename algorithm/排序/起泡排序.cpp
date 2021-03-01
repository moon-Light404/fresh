#include<iostream>
using namespace std;
template<class T>
void swap(T &x,T &y)
{
	T temp=x;
	x=y;
	y=temp;
}
template <class T>
void bubble(T a[],int n)
{
	int i=n-1;
	while(i>0)
	{
		int lastchange=0;//这里必须赋值，如果不的话，假如已经排序完成，那么
		//a[j+1]>a[j]恒成立，lastchange就不会有值，这时i=lastchange的值就是未知的
		
		for(int j=0;j<i;j++)
		if(a[j+1]<a[j]){     //每次把最大的数下沉到末尾，然后只要对前面的数进行排序， 
		                      //记录lastchange=j--->i; 
			swap(a[j],a[j+1]);
			lastchange=j;
		}
			i=lastchange;
		
	}
}
int main(){

	return 0;
}