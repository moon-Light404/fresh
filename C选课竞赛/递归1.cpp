#include <iostream>
using namespace std;
int n, m;

int f(int m, int n) {
	if (m == 0 || n == 0) {
		cout << "mµÄÖµ:" << m << endl;
		cout << "value of n:" << n << endl;
		return 1;
	}
	return f(m - 1, n) + f(m, n - 1);
}

int main() {
	cin >> m >> n;
	f(m, n);
	return 0;
}