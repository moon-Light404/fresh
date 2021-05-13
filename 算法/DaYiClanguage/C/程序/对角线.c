#include<iostream>
using namespace std;
int main()
{
	int Arr[]={11,22,33,44,55,66,77};
	int insertnum=34;
	int insertIndex=0;
	for(int i=0;i<Arr.length;i++){
		if(insertnum<Arr[i]){
			insertIndex=i;
			break;
		}
	}

int *A=new[Arr.length+1];
for(int i=0;i<A.length;i++)
{
	if(i>=isertIndex){
		if(i==insertIndex) A[i]=insertnum;
		
		if(i+1<A.length)
		A[i+1]=Arr[i];
	}
	else {
		A[i]=Arr[i];
	}
}
for(int i=0;i<A.length;i++)
cout<<A[i]<<" ";
return 0;
}
