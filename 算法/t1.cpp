#include <cstring>
#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000
#define ll long long
using namespace std;

bool isPrime(long long n) {
	bool flag = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			flag = true;
		if (flag)
			return false; // 不是素数
	}
	if (!flag)
		return true; // 是素数
}

ll ksc(ll a, ll b, ll n) {
	ll ans = 0;

	while (b) {
		if (b & 1)
			ans = (ans + a) % n;
		a = (a + a) % n;
		b = b >> 1;
	}
	return ans;
}

ll Modular(ll a, ll b, ll n) {
	ll ans = 1, base = a;
	while (b) {
		if (b & 1) {
			// 优化1
			ans = ksc(ans, base, n) % n;
		}
		base = ksc(base, base, n) % n;
		b >>= 1;
	}
	return ans;
}

int main() {
	int j = 0;
	for (ll i = 78000;; i++) {
		if (isPrime(i)) {
			j++;
			cout << i << " ";
		}
		if (j > 1000)
			break;
	}
}
