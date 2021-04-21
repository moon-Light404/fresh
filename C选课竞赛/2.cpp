#include <iostream>
using namespace std;

// 金币数 == 5n -1
int main() {
	bool flag = true;
	int n, x, i;
	for ( n = 1004; ; n += 5) {
//		cout << "现在n的值为" << n << endl;
		x = n;
		for (i = 1; i <= 5 && flag; i++) { // 循环5次
			if ( ((x + 1) % 5 == 0) && (((x + 1) * 0.8 ) > 1000) ) {
				x = (x + 1) * 0.8;
//				cout << x << endl;
//				cout << "i的值为" << i << endl;
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