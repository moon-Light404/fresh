#include <iostream>
using namespace std;
const int N = 110;

int a[N], d[N]; // d[i]��ʾ��a[i]��β���Ӷ��е����������
// ��Ϊ��û�����Ƴ���(���ⳤ�ȶ���)���޷Ǿ����жϻ᲻���и���
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (d[i - 1] > 0)
			d[i] = d[i - 1] + a[i];
		else
			d[i] = a[i]; // ǰ��Ķ��Ǹ�����ֱ�Ӷ���
	}
	cout << d[n];
	return 0;
}