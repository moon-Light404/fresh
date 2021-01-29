#include<bits/stdc++.h>  //万能头文件
using namespace std;
int cmp(string a,string b)
{
return a.compare(b)<0;  //字符串比较函数 a<b 
    //字符串比较规则： 从字符串开头开始，直到出现不一样的字符，比较其大小，返回
}
int main()
{
  int n;
  cin>>n;
  char str[n];
  for(int i=0;i<n;i++)
  cin>>str[i];
  sort(str,str+n,cmp);
  cout<<str[0]<<endl;
  return 0;
}
