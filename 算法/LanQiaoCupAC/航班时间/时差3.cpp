#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int getTime(){
	char line[100] = {};
	cin.getline(line,100);
	int h1,m1,s1,h2,m2,s2,d=0;
	if(strlen(line) == 17){
		sscanf(line,"%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
		} 
		else{
		sscanf(line,"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
		}
		int time = (d*24*3600+h2*3600+m2*60+s2)-(h1*3600+m1*60+s1);
		return time;
	
}
int main(){
	int T;
	(cin >> T).get();	//读取整数后把换行符吃掉
	for(int i = 0;i < T;i++){
		int time1 = getTime();
		int time2 = getTime();
		int t = (time1+time2)/2;	//得到总的秒数
		//输出时间 
		printf("%02d:%02d:%02d\n",t/3600,t/60%60,t%60);	//转换为hh:mm:ss 
	} 
	
	return 0;
}
