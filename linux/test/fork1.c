#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<errno.h>

// 使用fork函数查看子进程和父进程的关系
int main()
{
    pid_t pid = fork(); // pid_t用于定义进程id
    if(pid == 0)
    {
        int j;
        for(j=0;j<10;j++)
        {
            printf("child:%d\n",j);
            sleep(1);
        }
    }
    else if(pid > 0)
    {
        int i;
        for(i = 0;i < 10;i++)
        {
            printf("parent: %d\n",i);
            sleep(1);
        }
    }
    else{
        fprintf(stderr,"cant't fork,error %d\n",errno);
        exit(1);
    }
    printf("This is the end !");
}