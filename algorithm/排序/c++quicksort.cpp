//c++快速排序
/*
#include <iostream>
#include <vector>
#define N 10
using namespace std;
void sawp(int &a,int &b)// 交换两个数
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
    base = a[left];// 基准元素
    while(i < j)
    {
        while(a[j]>=base && i < j) //i <j 基本条件
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
*/

// 单边循环


#include <iostream>
#include <vector>
#define N 10
using namespace std;
void sawp(int &a, int &b) { // 交换两个数
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void quickSort(vector<int> &a, int L, int R) {

    if(L>=R){
        return; // 递归结束条件
    }
	// L,R表示起始和终点下标
	int p = a[L];
	int mark = L;
    
	for (int i = L + 1; i <= R; i++) {
        
		if (a[i] < p) {
            cout<<p<<"  >  "<<a[i]<<endl;
            cout<<"mark值为"<<mark<<endl;
			mark++;
            cout<<"mark值为"<<mark<<endl;
			swap(a[mark], a[i]); //此时mark表示a[mark]>p,把小的
			// 提到前面来
          
   
		}
	}
    
	swap(a[mark], a[L]);
    
	quickSort(a, L, mark - 1);
	quickSort(a, mark + 1, R);
}

int main() {
	vector<int> a = {4,7,3,5,6,2,8,1};
	quickSort(a, 0, a.size() - 1);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	return 0;
}