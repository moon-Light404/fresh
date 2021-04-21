#include <iostream>
using namespace std;

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
	while (cin >> n) {
		if (!isValidDate(n))
			cout << "-1";
		else
			cout << "111";
	}


	return 0;
}