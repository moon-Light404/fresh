#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node_diary {
	int ts;
	int id;
	int flag = 0;//�����׷����ӻ���
	int sum = 1;
};

int main() {
	int n, d, k;
	int x[n];
	cin >> n >> d >> k;
	node_diary note[n];
	for (int i = 0; i < n; i++) {
		cin >> note[i].ts;
		cin >> note[i].id;
	}

	for (int i = 0; i < n; i++) {
		if (note[i].flag == 0) {
			for (int j = i + 1; j < n; j++) {
				if (note[i].id == note[j].id) { //���ڵ��޵��ۼ�
					note[j].flag = 1;
					if (note[i].ts + d > note[j].ts) { //��־��ʱ�������ж�
						note[i].sum++;

					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (note[i].sum >= k && note[i].flag == 0) {

			x[i] = note[i].id;

		}
	}
	sort(x, x + n);
	for (int i = 0; i < n; i++) {
		if (x[i]) {
			cout << x[i] << endl;
		}
	}


	return 0;





}
