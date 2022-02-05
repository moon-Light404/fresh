// #include<iostream>
// using namespace std;
// const int N = 10000;
// int A[1000]; // 加入要输入1000个数最多
// bool exist[N]; // 出现的数true 没有出现false
// int main() {
//     int n = 0;
//     // scanf("%d",&n);
//     int a;
//     while(cin >> a) {
//         if(a == 0) break;
//         A[n++] = a;
//         exist[A[n]] = true;
//     }

//     for(int i = 0;i < n ;i++) {
//         scanf("%d",&A[i]);
//         exist[A[i]] = true;
//     }
//     int cnt = 0;
//     for(int i = 0;i < n;i++) {
//         if(exist[A[i]] && exist[A[i] * 2]) {
//             cnt++;
//         }
//     }
//     printf("%d",cnt);

//     return 0;
// }


#include<iostream>
using namespace std;
int main() {
    int i, j, n, count, a[20];
    cin >> a[0];
    while(a[0] != -1) {
        n = 1;
        for(; ; n++) {
            cin >> a[n];
            if(a[n] == 0) break;
        }
        count = 0;
        for(i = 0; i< n-1;i++) {
            for(j = i + 1; j < n;j++) {
                if(a[i] * 2 == a[j] || a[j] * 2 == a[i]) {
                    count++;
                }
            }
        }
        cout << "输入的数据用例中成倍数关系的对数:" << count << endl;
        cin >> a[0]; // 输入下一个测试用例的首例数据
    }

    return 0;
}