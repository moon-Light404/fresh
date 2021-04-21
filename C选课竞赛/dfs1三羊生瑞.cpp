#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int aa[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sum = 0;
	int sum1 = 0;
	int sum2 = 0;
	int ans = 0;
	while (next_permutation(aa, aa + 10)) {
		if (aa[0] != 0 && aa[4] != 0) {
			sum1 = aa[4] * 1000 + aa[3] * 100 + aa[5] * 10 + aa[6];
			sum2 = aa[0] * 1000 + aa[1] * 100 + aa[2] * 10 + aa[3];
			sum = aa[0] * 10000 + aa[1] * 1000 + aa[5] * 100 + aa[3] * 10 + aa[7];
			if (sum == (sum1 + sum2)) {
				break;
			}
		}


	}
//	cout << "ÏéÈðÉú»Ô:" << endl;
//	cout << " " << sum1 << endl;

//	cout << "ÈýÑòÏ×Èð:" << endl;
	cout << " " << sum2 ;

//	cout << "ÈýÑòÉúÈðÆø:" << endl;
//	cout << sum << endl;
	return 0;
}