#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 8003119100明文
ll n;
ll p, q, e;
ll d;
// 最大公因数
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

// 判断是否是素数
bool isPrime(ll n) {
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

// 求a^b mod n 的值,利用快速幂
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

//求乘法逆元
// ax+by=1 中 x 是amodb的乘法逆元
void extgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (b == 0) {
		d = a, x = 1, y = 0;
		return;
	}
	extgcd(b, a % b, d, y, x);
	y -= a / b * x;
	return;
}

// 乘法逆元的结果
ll getMod(ll a, ll b) {
	ll d, x, y;
	extgcd(a, b, d, x, y);
	if (d == 1)
		return (x + b) % b;
	else
		return -1;
}

// 加密
ll Encryption(ll value) {
	return Modular(value, e, n);
}

// 解密
ll Decryption(ll value) {
	return Modular(value, d, n);
}

int main() {
	while (1) {
		cout << " 请输入两个大的素数(小于100000):" << endl;
		cin >> p >> q;
		if (isPrime(p) && isPrime(q))
			break;
	}
	while (1) {
		cout << "请输入e的值" << endl;
		cin >> e;
		if (gcd(e, (p - 1) * (q - 1)) == 1 && e + 2 < (p - 1) * (q - 1))
			break;
	} // 输入的e作为公钥密码
	n = p * q;
	d = getMod(e, (p - 1) * (q - 1)); // 获得e模(p-1)(q-1)的乘法逆元

	cout << "d的值为" << d << endl;
	cout << "{" << e << "," << n << "}" << "为公钥" << endl;
	cout << "{" << d << "," << n << " }" << "为私钥" << endl;
	// 进行加密操作
	while (1) {
		cout << "-----------请输入你要加密的数据-----------" << endl;
		ll k;
		cin >> k;
		ll m = Encryption(k);
		cout << "密文为" << m << endl;
		cout << "明文为" << Decryption(m) << endl;
		cout << "------------------" << endl;
	}
	cout << gcd(45, 15);
	return 0;
}
