#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000;
int a[N], cnt;

//
//int main() {
//	int n;
//	while (cin >> n) {
//		cnt = 0;
//		do {
//			a[cnt++] = n % 2;
//			n /= 2;
//		} while (n != 0);
//		for (int i = cnt - 1; i >= 0; i--) {
//			cout << a[i];
//		}
//	}
//
//	return 0;
//}






char h[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'}; // 记录十六进制的各个数
int main() {
	int n;
	while (cin >> n) {
		cnt = 0;
		do {
			a[cnt++] = n % 16;
			n /= 16;
		} while (n != 0);
		for (int i = cnt - 1; i >= 0; i--) {
			int k = a[i];
			cout << h[k];
		}
	}
	return 0;
}