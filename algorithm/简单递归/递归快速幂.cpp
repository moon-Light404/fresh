#include <iostream>
using namespace std;
int cnt = 0;


int qpow(int a, int n) {
	cnt++;
	cout << "times of cnt:" << cnt << endl;
	if (n == 0) {
		cout << "此时n等于0 " << endl;
		return 1;
	}

	else if (n % 2 == 1) {
		int k = qpow(a, n - 1);
		int l = k * a;
		cout << "k and l:" << k <<  " " << l << endl;
		cout << l << "=" << k << "* " << a << endl;
		return l;
	}

	else {
		int temp = qpow(a, n / 2);
		cout << "temp value:" << temp << endl;
		cout << temp << "* " << temp << "=" << temp *temp << endl;
		return temp * temp;
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	int res = qpow(m, n);
	cout << res << endl;
	return 0;
}