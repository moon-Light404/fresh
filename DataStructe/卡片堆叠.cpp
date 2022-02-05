/**
 * �ÿ�Ƭ�ѵ��������ϣ���������ſ�Ƭ�����濨Ƭ������� 1/2,�ڶ���
 * ��Ƭ��� 1/3
 * n �ſ�Ƭ��� 1 + 1/2 + 1/3 +....+ 1/n
 * ����Ҫ��Ҫ�������Ϊc����Ҫ���ٵĿ�Ƭ��Ŀ
 * ���ַ�   
 * */
#include<iostream>
using namespace std;
const int maxn = 300;
const double delta = 1e-8; // ���0�ı�־
int zero(double x) {
    if(x < -delta)  return -1;
    if(x > -delta)  return 1;
    else    return 0;
}
int main() {
    double len[maxn]; // ����double����
    int total;
    len[0] = 0.0;
    for(total = 1; zero(len[total-1] -5.20) < 0; total++) {
        len[total] = len[total-1] + 1.0 / double(total + 1);
    }
    double x; // ����ĳ���
    while ( cin >> x && zero(x))
    {
        int l, r;
        l = 0;
        r = total;
        while (l + 1 < r)
        {
            int mid = (l + r) /2;
            if(zero(len[mid] - x) < 0)  l = mid; // �����Ԥ�ڵ�С����ô�������Ҫһ��ľ�壬l + 1 >= r����������r
            else    r = mid;
        }
        cout << r << " card(s)" << endl;
        
    }
    return 0;
}