#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int n = 10;
	printf("%d\n", n);
	int a[12];
	for (int i = 1; i <= 10; i++)
		a[i] = i;
	random_shuffle(a + 1, a + n + 1 );
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}
