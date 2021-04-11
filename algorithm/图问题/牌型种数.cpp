
#include <iostream>
using namespace std;
int ans = 0;

void dfs(int type, int sum) { // type表示种数，sum表示数量
	if (sum > 13)
		return;

	if (type == 13) { // 对13种牌都进行了选择
		if (sum == 13) { // 选了13张牌
			ans++;
		}
		return;
	}

	for (int i = 0; i < 5; i++) {

		dfs(type + 1, sum + i);
		// 每一次循环对应一次选择
		// 也可理解为选了多少次
		// 有可能这种牌不选 为0,type每次都加1

	}
}

int main() {
	dfs(0, 0); // 当前选的次数，牌的数量
	cout << ans;
	return 0;
}

/// 一共有13种牌，每种4张，每种牌可以不选，选1、2、3、4张，只要最后的牌的数量为13即可



