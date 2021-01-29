#include<stdio.h>
#define N 10000000
int main()
{

    int k=1, n=0,max,a[N],b[N];
    scanf("%d", &n);

        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);

        for(int i=0; i<n; i++)                  
        
       {
            if(a[i]<a[i+1])
            {
                k++;
                b[i]=k; 
            }
            else
            {
                k=1;
                b[i]=k;
            }

        }

    max=b[1];       

    for(int i=0; i<n; i++)
        if(max<b[i])
          max=b[i];

        printf("%d\n",max); 
      
    return 0;
}
