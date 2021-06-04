#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 20;
int a[N];
//��������֪�� ��� k == n ,��ô��֤�����е�������ȫ����ѡ,
//             ��� k < n , ��ô��Ҫ˼������ȥѡ����:
//1.k �����ż���Ļ�,ѡ�����Ľ��һ���ǷǸ��� , ԭ������:
//             (1) # �����ĸ�����ż�����Ļ�,��������,��ôһ���ǷǸ���
//             (2) # �����ĸ���������������Ļ�,��ô���Ǿ�ֻѡż��������ֵ���ĸ���
//2.k ������������Ļ�,
//             (1)# ���е�����������Ǹ���,��ôѡ�����Ľ��Ҳһ�����Ǹ���
//             (2)# ����Ļ�,��һ�������� 1���Ǹ���, ��ô���ǽ�������ȡ����, ��ʱҪѡ�ĸ������� k--,
//                # k-- ��ż��,��ô����ת��Ϊ k-- ��ż�������˼��

int main() {
	int time;
	cin >> time;
	while (time--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		ll res = 1;
		int l = 0, r = n - 1;
		int sign = 1;
		if (k % 2) {
			res = a[r];
			r--;
			k--;
			if (res < 0 )
				sign = -1;
		}
		while (k) {
			ll x = (ll)a[l] * a[l + 1], y = (ll)a[r] * a[r - 1];
			if (x * sign > y * sign) {
				res = x * res;
				l += 2;
			} else {
				res = y * res;
				r -= 2;
			}
			k -= 2;
		}
		printf("%lld", res);
	}

	return 0;
}




#include<iostream>
#include<cstring>
using namespace std;
const int N = 20;
char g[N][N];
bool col[N]; // �����Ƿ����
bool u1[N], u2[N]; // ��¼�Խ��ߺͷ��Խ���
int k; // k x K�ķ���
void dfs(int n)
{
    if(n == k) // ����k��
    {
        for(int i = 0; i < k;i++)   cout << g[i]  << endl;
        puts("");
        return;
    }
    
    for(int u = 0;u < k;u++) // ����������ĳһ�е��ϵĸ���
    {
        if(!col[u] && !u1[u+n] && !u2[u-n+k-1]) // �Խ����ϵĵ��x��y���������
        {
           col[u] = true; // ��Ǹ���
           g[n][u] = 'Q';
           u1[u+n] = true;
           u2[u-n+k-1] = true;
           dfs(n+1);
           // �ָ��ֳ�
           col[u] = false;
           u1[u+n]  =false;
           u2[u-n+k-1]=false;
           g[n][u]='.';
        }
    }
}
int main()
{
    cin >> k;
    for(int i = 0;i < k;i++)
        for(int j = 0; j < k;j++)
            g[i][j] = '.';
    dfs(0); // ��һ�п�ʼ
    return 0;
}