/**
 * ��һ��ʮ������ת��Ϊʮ������
 * */
#include<iostream>
using namespace std;
// int main() { // ����ת��Ϊʮ������
//     int num;
//     int temp[10];
//     int pos = 0;
//     int T;
//     cin >> T;
//     while(T--) {
//          cin >> num;
//         while(num) {
//         temp[pos++] = num % 12;
//         num /= 12;
//         }
//         for(int i = pos - 1;i >= 0;i--) {
//             // cout << temp[i] << " ";
//             if(temp[i] == 10) cout <<"A";
//             else if(temp[i] == 11) cout <<"B";
//             else cout << temp[i]; 
//         }
//         pos = 0;
//     }
    
//     return 0;
// }

int calc(int num,int base) { // ��numת��Ϊbase���ƺ������֮��
    int temp[20];
    int pos = 0;
    while(num) {
        temp[pos++] = num % base;
        num /= base;
    }
    int sum = 0; // ��λ֮��
    for(int i = pos - 1;i >= 0;i--) {
        // cout << temp[i] << " ";
        sum += temp[i];
    }
    return sum;
}
int main() {
    for(int i = 2992; i <= 9999;i ++) {
        if(calc(i,10) == calc(i,12) && calc(i,12) == calc(i,16)) {
            cout << i << endl;
        }
    }
    return 0;
}