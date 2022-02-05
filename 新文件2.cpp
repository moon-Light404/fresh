#include <iostream>
using namespace std;

int main() {
	char A[8];
	scanf("%s", A);
	for (int i = 0; i < 8; i++) {
		for (int j = 7; j >= 0; j--)
			cout << ((A[i] >> j) & 1);

		cout << endl;
	}

	return 0;
}