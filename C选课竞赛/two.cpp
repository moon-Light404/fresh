#include <iostream>

#include <algorithm>

#include <cmath>

#include <string.h>

using namespace std;

typedef long long ll;

int n;

int length[100];

int mark[100];

int stick_num;

int len;

int cmp(int a, int b) {

	return a > b;

}



int dfs(int nowLen, int nowGet, int cnt)

{

	if (cnt >= n)
		return 0;

	if (nowGet == stick_num)
		return 1;

	for (int i = cnt; i < n; i++)

	{

		if (mark[i] == 0)

		{

			if (nowLen + length[i] == len)

			{

				mark[i] = 1;

				if ( dfs(0, nowGet + 1, nowGet) == 1)
					return 1;

				mark[i] = 0;

				return 0;

			}

			else if (nowLen + length[i] < len)

			{

				mark[i] = 1;

				if (dfs(nowLen + length[i], nowGet, i + 1) == 1)
					return 1;

				mark[i] = 0;

				if (nowLen == 0)
					return 0;

				for (; length[i] == length[i + 1] && i + 1 < n; i++);

			}

		}

	}

	return 0;

}

int main()

{

	int i;

	int sum = 0;

	cin >> n;

	sum = 0;

	for (int i = 0; i < n; i++)

	{

		cin >> length[i];

		sum += length[i];

	}

	sort(length, length + n, cmp);

	for (len = length[0]; len <= sum; len++)

	{

		if (sum % len != 0)
			continue;

		stick_num = sum / len;

		if (dfs(0, 0, 0) == 1)
			break;

	}

	std::cout << len << endl;

}

return 0;

}