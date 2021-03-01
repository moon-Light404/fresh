#include<iostream>
using namespace std;

void swap(int& a,int& b){
    int t = a;
    a = b;
    b = t;
}

void Select_sort(int a[],int n){
    int minindex;
    for(int i=0;i<n-1;i++){
        minindex = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minindex]){
                minindex = j;
            }
        }
          swap(a[i],a[minindex]);
    }
  
}

int main(){
    int arr[6] = {2,4,15,26,36,19};
    Select_sort(arr,6);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";

    }
    return 0;
}