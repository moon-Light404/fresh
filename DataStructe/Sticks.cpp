/**
 * ��ľ����ȡһЩ��ͬ��ľ�������и��������ľ���ĳ��ȣ���ԭ��ľ����С
 * ���ܵĳ���
 * */
#include<iostream>
#include<algorithm>
using namespace std;
int sticks[65];
int used[65];
int n, len;
bool dfs(int i,int l, int t) {
    if(l == 0) {
        t -= len;
        if(t == 0)  return true; // ����ľ�������г���
        for(i = 0;used[i];i++);// �ҵ���һ����û�е�ľ��
        used[i] = 1; // ����ľ��i
        if(dfs(i+1,len-sticks[i],t))    return true; // ƴ����һ��ľ��(�ֳ�����ľ��)
        used[i] = 0, t+=len; // �ָ��ݹ�֮ǰ�Ĳ���
    }
    else { // ��ʣ���len����(��һ��ľ�������г�һЩС��)
        for(int j = i;j < n;j++) { // ���ճ��ȵݼ���˳������--̰��
            if(j>0 && (sticks[j-1] == sticks[j] && !used[j-1])) continue; // ���j-1��j��ͬ���ȣ��Ҷ�û���гɹ�(�ʹղ���len)���ǾͿ���һ��ľ��

            if(!used[j] && l >= sticks[j]) { // ����ľ��j
                l -= sticks[j]; used[j] = 1;
                if(dfs(j,l,t)) return true; // ��������ʣ�µ�ľ��������true
                l += sticks[j]; used[j] = 0; // �ָ��ݹ�֮ǰ�Ĳ���
                // if(sticks[j] == l) break; 
            }
        }
    }
    return false;
} 

bool cmp(const int a,const int b) {
    return a > b;
}

int main() {
    while(cin >> n && n) {
        int sum = 0;
        for(int i=0;i < n;i++) {
            cin >> sticks[i];
            sum += sticks[i];
            used[i] = 0;
        }
        sort(sticks,sticks+n,cmp); // �ݼ�
        bool flag = false;

        for(len = sticks[0];len <= sum/2;++len) { // ����[stick[0],sim/2]����
            if(sum % len == 0) {
                if(dfs(0,len,sum)) { // ������Ϊlen��ľ���պ�������n��ľ��
                    flag = true;
                    cout << len  << endl;
                    break;
                }
            }
        }
        if(!flag)   cout << sum << endl; // �ܳ�����len�ı�������������sum/2��ʱ�򻹲��У���ľ���ĳ��Ⱦ�������ľ���ĺ�
    }

    return 0;
}
