#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100010;
int a[N];
int ans;

void merge(int l1, int r1, int l2, int r2) {
	int tmp[r2 - l1 + 1];
	int index = 0;
	int j = l1;
	while (l1 <= r1 && l2 <= r2) {
		if (a[l1] <= a[l2])
			tmp[index++] = a[l1++];

		else {
			// 记录逆序对的数量,即前面的数大于后面的
			cout << "sucess";
			ans += r1 - l1 + 1;
			tmp[index++] = a[l2++];
		}
	}
	while (l1 <= r1)
		tmp[index++] = a[l1++];
	while (l2 <= r2)
		tmp[index++] = a[l2++];
	for (int i = 0; i < index; i++)
		a[j + i] = tmp[i]; // 修改l1
}

void mergeSort(int a[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		merge(left, mid, mid + 1, right);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mergeSort(a, 0, n - 1); // 0和n-1都是下标
	for (int i = 0; i < n; i++)
		cout << a[i];
	cout << ans;
	return 0;
}