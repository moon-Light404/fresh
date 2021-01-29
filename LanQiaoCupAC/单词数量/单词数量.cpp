#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main(){
	char str[88];
	int count = 0;
	gets(str);
	for(int i=0;i<strlen(str);i++){
		if(str[i]==' ')
		count++;
	}
	cout<<count+1<<endl;
	return 0;
} 
