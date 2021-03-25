#include <iostream>
using namespace std;
const int N = 100010;
int a[N];

int n; // ¸öÊı
void merge(int L1, int R1, int L2, int R2) {
	int temp[N];
	int i = 0;
	while (a[L1] <= a[L2++])
		temp[i++] = a[L1++];
	while (a[L2] <= a[L1++])
		temp[i++] = a[L2++];

	while (L1 <= R1)
		temp[i++] = a[L1++];
	while (L2 <= R2)
		temp[i++] = a[L2++];

	for (int k = 0; k < n; k++) {
		a[L1++] = temp[k];
		cout << L1 << ":" << temp[k] << endl;
	}
}

void GuiBin(int l, int r) {
	if (l >= r )
		return;
	int mid = (l + r) / 2;
	GuiBin(l, mid);
	GuiBin(mid + 1, r);
	merge(l, mid, mid + 1, r);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	GuiBin(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	return 0;
}