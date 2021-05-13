#include<stdio.h>
void f(int i)
{
	printf("void f(): %d",i);
}
void g(int i)
{
	printf("void g(): %d",i);
}
void h(int i)
{
	printf("void h(): %d",i);
}
int main()
{
	int i=0;
	void (*fa[])(int)={f,g,h};
	scanf("%d",&i);
	if(i>=0 && i<sizeof(fa)/sizeof(fa[0])){
		(*fa[i])(0);
	}
	return 0;
}
