
#include <iostream>
using namespace std;
int ans = 0;

void dfs(int type, int sum) { // type��ʾ������sum��ʾ����
	if (sum > 13)
		return;

	if (type == 13) { // ��13���ƶ�������ѡ��
		if (sum == 13) { // ѡ��13����
			ans++;
		}
		return;
	}

	for (int i = 0; i < 5; i++) {

		dfs(type + 1, sum + i);
		// ÿһ��ѭ����Ӧһ��ѡ��
		// Ҳ�����Ϊѡ�˶��ٴ�
		// �п��������Ʋ�ѡ Ϊ0,typeÿ�ζ���1

	}
}

int main() {
	dfs(0, 0); // ��ǰѡ�Ĵ������Ƶ�����
	cout << ans;
	return 0;
}

/// һ����13���ƣ�ÿ��4�ţ�ÿ���ƿ��Բ�ѡ��ѡ1��2��3��4�ţ�ֻҪ�����Ƶ�����Ϊ13����



