/**
 * 对称字符串
 * */
#include<iostream>
using namespace std;

void print(int n) {
    string s;
    cin >> s;
    cout << s <<endl; // 输出第1、3、5个字符串...
    if(--n) {
        cin >> s; // 输入2、4、6个字符串
        if (--n) print(n);
        cout << s << endl; // 回溯从后向前输出字符串
    }
}
int main() {
    int n, loop = 0;
    cin >> n; // 字符串个数
    while (n)
    {
        cout << "SET " <<++loop<<endl;
        print(n); 
        cin >> n; // 下一个案例
    }
    return 0;
}
/**
 *  Bo Pat Jean Kevin Claude William Martbeth
Bo
Jean
Claude
Martbeth
William
Kevin
Pat
**/