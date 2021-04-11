#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int a[N];

int get_unique_count(int a[], int n) {
	int sum = 1;
	int j = 0;
//	sort(a, a + n);
	for (int i = 0; i < n && j < n; ) {
		j = i;
		while (a[j] == a[i] && j < n) {
			j++;
		}
		cout << "现在的值为:" << a[j] << endl;
		i = j;
		if (j <= n - 1)
			sum++;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	cout << get_unique_count(a, n);
	return 0;
}