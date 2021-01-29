#include<iostream>
using namespace std;

int midsort(int a[],int target,int n)
{
	int low = 0,high = n-1,mid;
    while(low <= high)
    {
         mid = low + (high - low)/2; 
         if(a[mid]>target)
            {
                high = mid - 1;
            }
        else if (a[mid]<target)
            {
                low = mid + 1;
            }
              
        else 
           {
            return mid;
           }
    }
    return -1;
}
int main()
{
    int a[6]={1,3,4,5,6,9};
    int c = midsort(a,5,6);
     cout<<c<<endl;
     return 0;
 }
