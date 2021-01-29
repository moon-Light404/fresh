//c++閫掑綊蹇�熸帓搴?
#include <iostream>
#include <vector>
#define N 10
using namespace std;
void sawp(int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void quickSort(int left,int right,vector<int> & a)
{
    if(left >= right)
    return;

    int i,j,base;
    i = left, j =right;
    base = a[left];
    while(i < j)
    {
        while(a[j]>=base && i < j)
        j--;

        while(a[i]<=base && i < j)
        i++;

        if(i < j)
        swap(a[i],a[j]); //交换左边和右边的值，一个大于基准值，一个小于基准值

    }
    a[left] = a[i];
    a[i] = base;
    quickSort(left,i-1,a);//对剩余的部分进行快速排序
    quickSort(i+1,right,a);//
}
//4 7 6 5 3 2 8 1
int main()
{
    vector<int> a(N);
    cout<<"请输入你的数组:"<<endl;
    for (int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    quickSort(0,N-1,a);
    for(int i=0;i<N;i++)
    {
        cout<< a[i]<<" ";
    }
    return 0;
}