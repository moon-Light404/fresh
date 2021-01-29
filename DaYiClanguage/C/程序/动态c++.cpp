#include<iostream>
#include<string>
#define N 10
using namespace std;
int main()
{
	int Arr[N];
	for(int i=0;i<10;i++)
	cin>>Arr[i];
	int len=sizeof(Arr)/sizeof(*Arr);
	int insertnum;
	cin>>insertnum;
	int insertIndex=0;
	for(int i=0;i<len;i++){
		if(insertnum<Arr[i]){
			insertIndex=i;
			break;
		}
	}

int *A=new int [len+1];
for(int i=0;i<len+1;i++)
{
	if(i>=insertIndex){
		if(i==insertIndex) A[i]=insertnum;
		
		if(i+1<len+1)
		A[i+1]=Arr[i];
	}
	else {
		A[i]=Arr[i];
	}
}
for(int i=0;i<len+1;i++)
cout<<A[i]<<" ";
return 0;
}
