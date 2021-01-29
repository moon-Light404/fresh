#include "usr.h"
int main()
{
	int i,j;
	cin >> i >> j;
    Matrix m1(i,j),m2(i,j),m3(j,i);
    m1.Fill(1);
    m2.Fill(2);
	m3.Fill(0);
    for(int s = 0 ; s < i ; s++){
		for(int c = 0 ; c < j ; c++){
			if(s==c)
				m3.Set(s,c,s+1);
		}
    }
    
	cout << "m1 + m2 :" << endl ;
    (m1 + m2).Print();
	cout << "m1 - m2 :" << endl ;
    (m1 - m2).Print();
	cout << "m1 * m3 :" << endl ;
    (m1 * m3).Print();
    
}

