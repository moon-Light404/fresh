#include<stdio.h>
void bubble_sort(int arr[],int len)
{
	int i,j,temp;
	for(i=0;i<len-1;i++)
	 for(j=0;j<len-1-i;j++)
	 {
	 	if(arr[j]>arr[j+1]){
	 		temp=arr[j];
	 		arr[j]=arr[j+1];
	 		arr[j+1]=temp;
		 }
	 }
}
int main()
{
	int arr[]={22,34,5,55,34,12,35,2,43,23};
	int len=(int) sizeof(arr)/sizeof(*arr);
	bubble_sort(arr,len);
	int i;
	for(i=0;i<len;i++)
	printf("%d ",arr[i]);
	
	return 0; 
}
