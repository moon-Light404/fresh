// #include<iostream>
// using namespace std;
// template<class T>
// void insertion(T a[],int n){
// 	int i,j;
// 	T temp;
	
// 	for(int i=1;i<n;i++)
// 	{
// 		int j=i;
// 		T temp=a[i];
// 		while(j>0 && temp<a[j-1])
// 		{
// 			a[j]=a[j-1];
// 			j--;    /*从第二个数开始看看是不是比前面的数小，有则前面的数后移
// 			       一位，j-- 继续比较前一个数再移动，若是较大的数，则不移动
// 				    ，插入到a[j]位置上，依次往下进行*/ 
// 		}
// 		a[j]=temp;
// 	}
// }
// int main()
// {
// 	int a[]={5,4,10,20,12,3};
// 	insertion(a,6);
// 	int n=sizeof(a)/sizeof(int ); // 获取数组元素个数 
// 	for(int i=0;i<n;i++)
// 	{
// 		cout<<a[i]<<" ";
// 	}
// 	cout<<"我是";
// 	return 0;
// }

//  复习--2021/2/26   big To small

#include<iostream>
using namespace std;

void insertSort(int a[],int len){// 数组+长度
	int pre,cur;
	for(int i=1;i<len;i++){
		pre = i - 1; 
		cur = a[i];
		while(pre>=0 && a[pre] < cur){
			a[pre + 1] = a[pre];// 往后挪位置
			pre--;
		}
		a[pre+1] = cur;
	}
}
int main()
{
	int a[]={5,4,10,20,12,3};
	insertSort(a,6);
	int n=sizeof(a)/sizeof(int ); // 获取数组元素个数 
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<"我是";
	return 0;
}