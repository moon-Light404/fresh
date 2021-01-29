指针：
int a[10];
int* p=a;
*(p+1)->a[1];

 *p++ 
 取出p所指的数据，然后顺便把p指向下一个位置；
 
 (*p)++
 取出p所指向的数据，并且加1；指向没有改变！！！
 
 无论指向什么类型，所有的指针大小都是一样的，都是地址；；
 
 void* 是不知道指向什么东西的指针
 指针转换类型 、
 int *p=&i;
 void*q=(void*)p; 这并没有改变P所指数据的类型，只是不一样的看待。。
 
 
 #include<stdio.h 
 void* malloc(size_t size)
 (int*)malloc(n*sizeof(int))
 
 
  
  
  
  
  
 
  
