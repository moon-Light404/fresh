/**
 * ����һ������������ʾһ���������������ĺͣ�д���ж����������ı�ʾ
 *
 */
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
 
const ll N = 100000; // 100000���ڵ�����
int prime[N]; // �����ж�
int table[10000];// ������
void findPrime() { // ɸѡ������
    prime[1] = 1; // 1��������
    for(ll i = 2; i <= N;i++)
        if(prime[i] == 0) { // i������
            for(ll j = i * i; j <= N; j += i)
                prime[j] = 1;
        }
}
int main() {
    findPrime();
    int c = 0;
    for(int i = 1; i <= N;i++) {
       if(!prime[i]) {
           table[c++] = i;
       }
    }
    // for(int i = 0;i < c;i++)    cout << table[i] << " ";
    int t; // Ҫ�������
    while (cin >> t && (t != 0)) {
        int cnt = 0; // ������ʼ��Ϊ0
        for(int i = 0; t >= table[i];i++) {
            int sum = 0; // ���������ĺ�
            vector<int> a;
            a.clear(); // �������
            for(int j = i; j < c && sum < t; j++) {
                sum += table[j];
                a.push_back(table[j]);
            }
                
            if(sum == t) {
                ++cnt; // ���� +1  
                for(vector<int> :: iterator iter = a.begin();iter!=a.end();iter++) {
                    cout << *iter;
                    if((iter + 1) != a.end())   cout << "+";
                }
                cout << endl;
            }     
        }
        cout <<"����Ϊ��" << cnt << endl;
    }
    
    return 0;
}

