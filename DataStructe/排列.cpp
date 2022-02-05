/**
 * 给出一个排列，求该排列的下k个排列
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1 
 * 
 * 1 2 3 4
 * 1 2 4 3
 * 1 3 2 4
 * 1 3 4 2
 * 1 4 2 3 
 * 1 4 3 2
 * 2 1 3 4
 * 算法思想
 * 1、从数列的右边向左寻找连续递增序列，例如1,3,5,4,2,其中 2-4-5是递增序列
 * 2、从递增序列中找到比它前面的数(3)大的最小数(4),交换这两个数-->1,4,5,3,2---->1,4, 2,5,3(递增排序后面的数)
 **/
#include <iostream>
#include<algorithm>
using namespace std;
int a[1024];

//产生下一个排列数
//存在则返回1
//不存在返回0
int next(int a[], int n)
{
    int i,j,k;
    // 从右向左寻找非递减序列,例如对于序列1,3,5,4,2,将会找到数字5的位置
    for(k = n - 1; k > 0 && a[k - 1] >= a[k]; k--);
    if(k == 0) return 0; //例:对于5,4,3,2,1的情形，他的下一个不存在，返回0
    //从非递减序列李寻找比它前面的一个数(3)大的最小数,即数字4
    for(i = n - 1; a[i] <= a[k - 1]; i--);
    //交换3和4
    int t = a[k-1];
    a[k-1] = a[i];
    a[i] = t;
    //将新的非递减序列逆序
    // i = k;
    // j = n - 1;
    // while(i < j) swap(&a[i++], &a[j--]);
    sort(a+k,a+n);
    return 1;
}

void pnt(int a[], int n)
{
    int i;
    for(i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    // int a[] = {1,2,3,4};
    // int size = sizeof(a) / sizeof(a[0]);
    // pnt(a, size);
    // while(next(a, size))
    //     pnt(a, size);
    // return 0;
    int T;
    cin >> T;
    int n,cnt;
    while(T--) {
        cin >> n >> cnt; // 1-n 和 下cnt个排列
        for(int i = 0;i < n;i++)    cin >> a[i];
        while(cnt--) {
            int re = next(a,n);
            if(re == 0) sort(a,a+n);
        }
        pnt(a,n);
    }
}