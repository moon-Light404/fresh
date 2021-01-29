#include<stdio.h>
void insertion(int arr[],int len)
{
	int i,j,temp;
	for(i=1;i<len;i++)
	{
		temp=arr[i];
		for(j=i;j>0&& arr[j-1]>temp;j--)
		{
		arr[j]=arr[j-1];
	}
	arr[j]=temp;
	}
}
int main()
{
	int arr[]={1,3,2,5,4,8,6};
	int len=(int) sizeof(arr)/sizeof(*arr);
	insertion(arr,len);
	int i=0;
	for(i=0;i<len;i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}
