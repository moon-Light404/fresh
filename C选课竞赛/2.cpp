#include <iostream>
using namespace std;

// ����� == 5n -1
int main() {
	bool flag = true;
	int n, x, i;
	for ( n = 1004; ; n += 5) {
//		cout << "����n��ֵΪ" << n << endl;
		x = n;
		for (i = 1; i <= 5 && flag; i++) { // ѭ��5��
			if ( ((x + 1) % 5 == 0) && (((x + 1) * 0.8 ) > 1000) ) {
				x = (x + 1) * 0.8;
//				cout << x << endl;
//				cout << "i��ֵΪ" << i << endl;
				if (i == 5)
					flag = false;
			} else
				break;
		}
		if (!flag)
			break;
	}

	cout << n;
	return 0;
}