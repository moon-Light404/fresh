#include <iostream>
using namespace std;

int main() {
	int year = 2010;
	int d = year, d2 = 0;
	while (d) {
		d2 = d2 * 10 + d % 10;
		d /= 10;
	}
	int nowdate = year * 10000 + d2;
	cout << nowdate;
}