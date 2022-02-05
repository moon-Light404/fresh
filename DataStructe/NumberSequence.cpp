/**����һ��������i����дһ����������������S1S2...Sk���ҵ���i��λ�õ�����
 **/
#include<iostream>
#include<cmath>
using namespace std;
const int Maxn = 40000;
long long len[Maxn], sum[Maxn]; // ÿ�εĳ��Ⱥ�ǰi�εĳ��Ⱥ�
void init() {
    for(int i = 1;i < Maxn;i++) {
        len[i] = len[i-1] + (int)log10((double)i) + 1;
        sum[i] = sum[i-1] + len[i]; // ǰi�η���ĳ��Ⱥ�
    }
}

int solve(int N) { // ��N��λ��
    int i = 1;
    while(sum[i] < N)   i++;
    N = N - sum[i-1]; // �ڵ� i ���е�λ��

    int len_k = 0, t;
    for(t = 1;len_k < N;t++) {
        len_k += (int) log10((double)t) + 1; // ��1~t���ּ��㳤��
    }
    int pos = len_k - N;
    // �ҵ� t - 1 ����Ҫ�ҵ����֣��Ƚ�len_k�Ƿ񳬹��˷�Χ
    return (t - 1)/(int)(pow((double)10,pos)) % 10;
}
int main() {
    int T;
    cin >> T;
    init();
    while(T--) {
        int a;
        cin >> a;
        cout << solve(a) << endl;
    }
    return 0;
}