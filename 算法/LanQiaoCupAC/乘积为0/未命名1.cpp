#include<stdio.h>

int main()
{
    const int MAX_VALUE = 100;
    int arr[MAX_VALUE];
    int i;
    //����Ŀ��100������ֱ�Ӹ���ճ�� 
    for(i=0;i<MAX_VALUE;i++){    //���� 
        scanf("%d",&arr[i]);
        if(arr[i] == 0){    //��չ 
            printf("1");
            return 0;
        }
    }    
        
    int num2=0,num5=0;
    for(i=0;i<MAX_VALUE;i++)
    {
        while(1)
        { 
            if( arr[i]%2==0 )    //���Էֽ��2 
            { 
                num2++;    
                arr[i]/=2;
            }     
                else if( arr[i]%5==0 )    //���Էֽ��5 
                {
                    num5++;
                    arr[i]/=5;
                }
                    else
                        break;
        } 
    }
    
    printf("%d",num2<num5?num2:num5);
    return 0;
}
