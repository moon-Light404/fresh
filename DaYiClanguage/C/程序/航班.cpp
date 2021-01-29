#include<iostream>
#include<cstring>

using namespace std;

int getTime()
{
	char line[100]={};
		cin.getline(line,100); //ge
		int h1,m1,s1,h2,m2,s2,d=0;
		if(strlen(line)==17){
			sscanf(line ,"%d:%d:%d %d:%d:%d",&h1,&m1,&s1,&h2,&m2,&s2);
		}
		else {
			sscanf(line,"%d:%d:%d %d:%d:%d (+%d)",&h1,&m1,&s1,&h2,&m2,&s2,&d);
		}
		int time=d*24*3600+h2*3600+m2*60+s2-(h1*3600+m1*60+s1);
}
int main()
{
	int T;
	(cin>>T).get();
	for(int i=0;i<T;i++)
	{
		int time1=getTime();
		int time2=getTime();
	    int t=(time2+time1)/2;
	    printf("%02d:%02d:%02d\n",t/3600,t/60%60,t%60);
	}
//	cin.get();
	return 0;
}
