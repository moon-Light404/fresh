#include <iostream>
using namespace std;
const int N = 10; // 存储8个数字
int a[N];

int monday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isValidDate(int d) {
	int year = d / 10000;
	int month = d % 10000 / 100;
	int day = d % 100;
	if (month > 12 || !month)
		return false;
	bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	if (month == 2) {
		if (day > 28 + leap)
			return false;
	}
	if (monday[month] < day)
		return false;
	return true;
}

int main() {
	int n;
	int ans1 = 0, ans2 = 0;
	cin >> n;
	int k = n / 10000;
	for (int i = k + 1;; i++) {
//		cout << i << endl;
		int d = i;
		int date = i;
		while (d) {
			date = date * 10 + d % 10;
			d /= 10;
		}
		// date是回文数字串,d改变了
		int cnt = 1;
		int temp = date;
		while (cnt <= 8) {
			a[cnt++] = temp % 10; // 存储每个数字
			temp /= 10;
		}


		if (!isValidDate(date))
			continue;


		if (a[1] == a[3] && a[1] == a[6] && a[1] == a[8] && a[2] == a[4] && a[2] == a[5] && a[2] == a[7])
			for (int j = 8; j; j--) {
				ans2 *= 10;
				ans2 += a[j];
			}
		if (a[1] == a[8] && a[2] == a[7] && a[3] == a[6] && a[4] == a[5] && !ans1)
			for (int j = 8; j; j--) {
				ans1 *= 10;
				ans1 += a[j];
			}
		if (ans1 && ans2) {

			break;
		}
	}
	cout << ans1 << endl << ans2 ;
	return 0;
}