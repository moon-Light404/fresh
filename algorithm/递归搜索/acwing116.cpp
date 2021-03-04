#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

// acwing116: 第一种————遍历操作法,备份数组
//
//“飞行员兄弟”这个游戏，需要玩家顺利的打开一个拥有16个把手的冰箱。
//
//已知每个把手可以处于以下两种状态之一：打开或关闭。
//
//只有当所有把手都打开时，冰箱才会打开。
//
//把手可以表示为一个4х4的矩阵，您可以改变任何一个位置[i,j]上把手的状态。
//
//但是，这也会使得第i行和第j列上的所有把手的状态也随着改变。
//
//请你求出打开冰箱所需的切换把手的次数最小值是多少。
//
//输入格式
//输入一共包含四行，每行包含四个把手的初始状态。
//
//符号“+”表示把手处于闭合状态，而符号“-”表示把手处于打开状态。
//
//至少一个手柄的初始状态是关闭的。
//
//输出格式
//第一行输出一个整数N，表示所需的最小切换把手次数。
//
//接下来N行描述切换顺序，每行输入两个整数，代表被切换状态的把手的行号和列号，数字之间用空格隔开。
//
//注意：如果存在多种打开冰箱的方式，则按照优先级整体从上到下，同行从左到右打开。
//
//数据范围



using namespace std;

/*
typedef pair<int, int> p; // 临时存储坐标
const int N = 5;
char map[N][N], backup[N][N]; // 冰箱状态和备份数组

int get_potition(int x, int y) {
	return 4 * x + y;
}

bool success() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (map[i][j] == '+')
				return false;

	return true;
}

void turn_one(int i, int j) {
	if (map[i][j] == '+')
		map[i][j] = '-';
	else
		map [i][j] = '+';
}

void turn_all(int x, int y) {
	for (int i = 0; i < 4; i++) {
		turn_one(x, i);
		turn_one(i, y);
	} // 改变所有同行同列的状态
	turn_one(x, y); // 上面改变了两次等于没变，需要再变一次
}

int main() {
	for (int i = 0; i < 4; i++)
		cin >> map[i];
	vector<p> res; // 表示最终最小步数的结果,因为有多种操作，所以
	// 我们必须再来个同类型的临时动态数组
	// 循环2^16种操作
	for (int op = 0; op < 1 << 16; op++) {
		// op代表16个二进制数字，1表示改变状态，0表示不变
		memcpy(backup, map, sizeof map); // 把原始状态备份到backup中去
		vector<p> temp; // 临时存储操作坐标
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (op >> get_potition(i, j) & 1) {
					// 存储坐标
					temp.push_back({i, j}); // {i,j}表示 pair类型
					turn_all(i, j);
				}
			}
		if (success()) { // 如果全部'-' 即成功的操作
			if (res.empty() || res.size() > temp.size())

			res = temp;
			break; // 每种状态只有唯一的方案(操作方式)
		}

		memcpy(map, backup, sizeof map); // 恢复原始状态
	}
	cout << res.size() << endl;
	for (auto k : res)
		cout << k.first + 1 << ' ' << k.second + 1 << endl;

	return 0;

}

*/


// 第二种写法: dfs递归，不需要备份数组，每个格子有两种状态:改变与不改变
const int N = 5;
typedef pair<int, int> p;
char g[N][N]; // 不需要拷贝数组
int i = 1;

vector<p> res, temp;


void turn_one(int i, int j) {
	if (g[i][j] == '+')
		g[i][j] = '-';
	else
		g [i][j] = '+';
}

void turn_all(int x, int y) {
	for (int i = 0; i < 4; i++) {
		turn_one(x, i);
		turn_one(i, y);
	} // 改变所有同行同列的状态
	turn_one(x, y); // 上面改变了两次等于没变，需要再变一次
}

bool success() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (g[i][j] == '+')
				return false;

	return true;
}


void dfs(int x, int y) {
	if (x == 3 && y == 4) { // 递归到边界了
//		cout << "第" << i << "次" << endl;
		i++;
		if (success()) {

			if (res.empty() || res.size() > temp.size())
				res = temp;

		}
		return;
	}

	if (y == 4) { // 每行的边界操作
		x++, y = 0;
	}

	// 下面是递归操作:最主要的部分---

	// 改变这个开关,记录坐标
	turn_all(x, y);
	temp.push_back({x, y});
	dfs(x, y + 1); // 从左到右

	// 恢复现场
	temp.pop_back();
	turn_all(x, y); // 两次抵消变回原样

	// 对该坐标不做处理
	dfs(x, y + 1);



}


int main() {
	for (int i = 0; i < 4; i++)
		cin >> g[i];

	dfs(0, 0); // 从坐标00开始(以数组下标为标准)

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first + 1 << ' ' << res[i].second + 1 << endl;
	}
	return 0;
}
