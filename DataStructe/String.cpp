/**
 * �Գ��ַ���
 * */
#include<iostream>
using namespace std;

void print(int n) {
    string s;
    cin >> s;
    cout << s <<endl; // �����1��3��5���ַ���...
    if(--n) {
        cin >> s; // ����2��4��6���ַ���
        if (--n) print(n);
        cout << s << endl; // ���ݴӺ���ǰ����ַ���
    }
}
int main() {
    int n, loop = 0;
    cin >> n; // �ַ�������
    while (n)
    {
        cout << "SET " <<++loop<<endl;
        print(n); 
        cin >> n; // ��һ������
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