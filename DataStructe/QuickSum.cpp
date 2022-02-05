/**
 * QucikSum计算每个字符的位置 与 字符的对应值的乘积的总和
 * */
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int value_c(char c) { // 返回字符对应的值
    if(c == ' ')    return 0;
    return c - 'A' + 1;
}

int QuickSum() {
    char c;
    int i = 2; // 字母的位置从1开始
    int sum = 0;
    while((c = getchar()) != '\n') {
        sum += value_c(c) * (i++);
    }
    return sum;
}
int main() {
    char s;
    cin >> s;
    while(s != '#') {
        cout << QuickSum() + value_c(s);
        cin >> s;
    }
    
    return 0;
}