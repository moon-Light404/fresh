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