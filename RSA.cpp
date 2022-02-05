#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

// 8003119100����
ll n;
ll p, q, e;
ll d;
// �������
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}

// �ж��Ƿ�������
bool isPrime(ll n) {
	bool flag = false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			flag = true;
		if (flag)
			return false; // ��������
	}
	if (!flag)
		return true; // ������
}

// ��a^b mod n ��ֵ,���ÿ�����
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
			// �Ż�1
			ans = ksc(ans, base, n) % n;
		}
		base = ksc(base, base, n) % n;
		b >>= 1;
	}
	return ans;
}

//��˷���Ԫ
// ax+by=1 �� x ��amodb�ĳ˷���Ԫ
void extgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (b == 0) {
		d = a, x = 1, y = 0;
		return;
	}
	extgcd(b, a % b, d, y, x);
	y -= a / b * x;
	return;
}

// �˷���Ԫ�Ľ��
ll getMod(ll a, ll b) {
	ll d, x, y;
	extgcd(a, b, d, x, y);
	if (d == 1)
		return (x + b) % b;
	else
		return -1;
}

// ����
ll Encryption(ll value) {
	return Modular(value, e, n);
}

// ����
ll Decryption(ll value) {
	return Modular(value, d, n);
}

int main() {
	while (1) {
		cout << " �����������������(С��100000):" << endl;
		cin >> p >> q;
		if (isPrime(p) && isPrime(q))
			break;
	}
	while (1) {
		cout << "������e��ֵ" << endl;
		cin >> e;
		if (gcd(e, (p - 1) * (q - 1)) == 1 && e + 2 < (p - 1) * (q - 1))
			break;
	} // �����e��Ϊ��Կ����
	n = p * q;
	d = getMod(e, (p - 1) * (q - 1)); // ���eģ(p-1)(q-1)�ĳ˷���Ԫ

	cout << "d��ֵΪ" << d << endl;
	cout << "{" << e << "," << n << "}" << "Ϊ��Կ" << endl;
	cout << "{" << d << "," << n << " }" << "Ϊ˽Կ" << endl;
	// ���м��ܲ���
	while (1) {
		cout << "-----------��������Ҫ���ܵ�����-----------" << endl;
		ll k;
		cin >> k;
		ll m = Encryption(k);
		cout << "����Ϊ" << m << endl;
		cout << "����Ϊ" << Decryption(m) << endl;
		cout << "------------------" << endl;
	}
	cout << gcd(45, 15);
	return 0;
}
