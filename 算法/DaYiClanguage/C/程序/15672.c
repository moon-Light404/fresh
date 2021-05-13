#include<stdio.h>
#define N 10000000
int main()
{

    int k=1, n=0,max,a[N],b[N];//k是计数器用来统计连续天数,将统                               计的数字保存在b[N]中  
    scanf("%d", &n);//n为可输入数字的个数 

        for(int i=0; i<n; i++)//向数组中输入数字 
            scanf("%d", &a[i]);

        for(int i=0; i<n; i++)//判断如果当前元素比后一个小,就                                 使k++,然后将k值保存在b[i]中,
                                //否则b[i]的元素为1 
       `{
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

    max=b[1];       //假设b[1]为最大的元素,也就是天数最多的元素 

    for(int i=0; i<n; i++)//求出天数最多的最大值 
        if(max<b[i])
          max=b[i];

        printf("%d\n",max); //输出天数最多的值 
       
    return 0;
}
