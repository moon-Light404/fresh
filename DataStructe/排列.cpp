/**
 * ����һ�����У�������е���k������
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
 * �㷨˼��
 * 1�������е��ұ�����Ѱ�������������У�����1,3,5,4,2,���� 2-4-5�ǵ�������
 * 2���ӵ����������ҵ�����ǰ�����(3)�����С��(4),������������-->1,4,5,3,2---->1,4, 2,5,3(��������������)
 **/
#include <iostream>
#include<algorithm>
using namespace std;
int a[1024];

//������һ��������
//�����򷵻�1
//�����ڷ���0
int next(int a[], int n)
{
    int i,j,k;
    // ��������Ѱ�ҷǵݼ�����,�����������1,3,5,4,2,�����ҵ�����5��λ��
    for(k = n - 1; k > 0 && a[k - 1] >= a[k]; k--);
    if(k == 0) return 0; //��:����5,4,3,2,1�����Σ�������һ�������ڣ�����0
    //�ӷǵݼ�������Ѱ�ұ���ǰ���һ����(3)�����С��,������4
    for(i = n - 1; a[i] <= a[k - 1]; i--);
    //����3��4
    int t = a[k-1];
    a[k-1] = a[i];
    a[i] = t;
    //���µķǵݼ���������
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
        cin >> n >> cnt; // 1-n �� ��cnt������
        for(int i = 0;i < n;i++)    cin >> a[i];
        while(cnt--) {
            int re = next(a,n);
            if(re == 0) sort(a,a+n);
        }
        pnt(a,n);
    }
}