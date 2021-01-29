#include<iostream>
#include<set>
using namespace std;
typdef long long LL;
const LL MAX=59084709587505;
int main()
{
	int a[3]={3,5,7};
	LL tou=1;
	set<LL> s;
	while(true){
		for(int i=0;i<3;i++)
		{
			LL tt=tou*a[i];
			if(tt<=MAX)
			s.insert(tt);
		}
		tou=*(s.upper_bound(t));
		if(tou>=MAX)  break;
	}
	cout<<s.size()<<endl;
	return 0;
}
