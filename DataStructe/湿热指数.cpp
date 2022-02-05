/**
 * 湿热指数 = 温度 + h
 *  h = (0.5555) x (e - 10.0)
 *  e = 6.11 x exp[5417.7530 x ((1/273.16)-(1/(露点+273.16)))]
 * 该题给出两个数字，要求求出第三个数字
 * T 数字 D 数字 H 数字   ---> 温度、露点、湿热指数
 * */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>
using namespace std;
double A,B,temp,hum,dew; // 温度、湿热指数、露点

double dohum(double tt,double dd)  {    // 根据温度tt和露点dd计算湿热指数
    double e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(dd+273.16))));
    double h = (0.5555)*(e-10.0);
    return tt + h;
}

double dotemp() { // 根据露点dew和湿热指数hum计算温度
    double e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(dew+273.16))));
    double h = (0.5555) *(e-10.0);
    return hum - h; 
}

double dodew() { // 根据温度temp和湿热指数hum计算露点
    double x = 0;
    double delta = 100;
    // 露点delta和湿热指数成正比关系
    // 增量值减半递增，多了就减，少了就增
    for(delta = 100;delta>.00001;delta /=2.0) {
        if(dohum(temp,x)>hum) x -= delta;
        else x += delta;
    }
    return x; // 返回露点x
}
int main() {
    char a,b;
    while (4 == scanf(" %c %lf %c %lf", &a, &A, &b, &B) && a != 'E') {
        temp = hum = dew = -999;
        if (a == 'T') temp = A;
        if (a == 'H') hum = A;
        if (a == 'D') dew = A;
        if (b == 'T') temp = B;
        if (b == 'H') hum = B;
        if (b == 'D') dew = B;
        if (hum ==-999) hum = dohum(temp,dew);
        if (dew ==-999) dew = dodew();
        if (temp == -999) temp = dotemp();
        printf("T %0.1lf D %0.1f H %.1f\n", temp,dew,hum);
    }
    assert(a == 'E');
}