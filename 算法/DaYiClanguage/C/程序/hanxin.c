#include<stdio.h>
int main()
{
 FILE *fin,*fout;
 fin=fopen("hanxinin.txt","r");
 fout=fopen("hanxinout.txt","w");
 //fin=stdim;
 //fout=stdout;
 int a,b,c,x,temp=0;
 fscanf(fin,"%d %d %d",&a,&b,&c);
 for(x=10;x<=100;x++)
 {
 	if(x%3==a&&x%5==b&&x%7==c)
 	{
 		fprintf(fout,"%d\n",x);
 		temp=1;
 		break;
	 }
 }
 if(!temp) fprintf(fout,"No answer!\n");
 fclose(fin);
 fclose(fout);
 return 0;
}
