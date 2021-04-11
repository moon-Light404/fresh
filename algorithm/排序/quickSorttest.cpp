#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100010;
int a[N];


int Pos(int a[], int left, int right) {
	int l = left, r = right;
	int t = a[left];
	while (left < right) {
		while (left < right && a[right] >= t)
			right--;
		a[left] = a[right];
		while (left < right && a[left] <= t)
			left++;
		a[right] = a[left];
	}
	a[left] = t;
	for (int i = l; i <= r; i++ )
		cout << a[i] << " " ;
	cout << endl;
	return left;
}

void quicksort(int a[], int left, int right) {
	if (left < right) {
		int p = Pos(a, left, right);
		quicksort(a, left, p - 1);
		quicksort(a, p + 1, right);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	quicksort(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}