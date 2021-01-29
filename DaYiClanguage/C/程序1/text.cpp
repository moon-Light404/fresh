#include <iostream>
using namespace std;
int main()
{
	int r=0;
	cin>>r;
	int *p=new int(r*r);

	
	
	for (int i = 0; i < r; i++)
	{
			for (int j = 0; j < r; j++)
			cin >> p[i*r+j];
		}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
			cout << p[i * r + j];
	}
	return 0;
}

