/**
 * QucikSum����ÿ���ַ���λ�� �� �ַ��Ķ�Ӧֵ�ĳ˻����ܺ�
 * */
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int value_c(char c) { // �����ַ���Ӧ��ֵ
    if(c == ' ')    return 0;
    return c - 'A' + 1;
}

int QuickSum() {
    char c;
    int i = 2; // ��ĸ��λ�ô�1��ʼ
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