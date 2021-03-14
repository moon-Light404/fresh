#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[8] = {1, 3, 4, 6, 8, 9, 10, 11};
	int low = *lower_bound(a, a + 8, 2);
	int high = *upper_bound(a, a + 8, 4);
	cout << low << high << endl;
	return 0;
}