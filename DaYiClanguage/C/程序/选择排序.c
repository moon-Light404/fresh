#include<stdio.h>
void swap(int* a, int* b);
void selection(int arr[],int len);
int main()
{   int i;
	int arr[] = {2,3,4,1,5,7,6};
	int len = (int) sizeof(arr) / sizeof(*arr);
    selection(arr,len);
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
void selection(int arr[],int len)
{
	int i,j;
	for(i=0;i<len-1;i++)
	{
		int min=i;
		for(j=i+1;j<len;j++)
		
			{
				if(arr[j]<arr[min])
				
				min=j;
			}
			
			swap(&arr[min],&arr[i]);
		
	}
}
void swap(int* a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

