#include<stdio.h>

int main()
{
	int n;
	int t[31][31];
	int i;
	int j;
	
	while((scanf("%d",&n))!=EOF){
		 for(i=0;i<31;i++)
		 for(j=0;j<31;j++)
		 t[i][j]=0;
		 
		 t[0][0]=1;
		 t[1][0]=1;
		 t[1][1]=1;
		 
		 
		 for(i=2;i<n;i++){
		 	t[i][0]=1;
		 	t[i][i]=1;
		 	for(j=1;j<=i;j++){
		 		t[i][j]=t[i-1][j]+t[i-1][j-1];
			 }
		 
		 }
		 
		 for(i=0;i<n;i++)
		 {
		 	for(j=0;j<n;j++){
		        if(t[i][j]!=0){
		        	if(j==0)
		        	printf("%d",t[i][j]);
		        	
		        	else printf(" %d",t[i][j]);
				}
			 }
			 printf("\n");
		 }
	}
	return 0;
}
