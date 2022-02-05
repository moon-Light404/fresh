/**
 * ʪ��ָ�� = �¶� + h
 *  h = (0.5555) x (e - 10.0)
 *  e = 6.11 x exp[5417.7530 x ((1/273.16)-(1/(¶��+273.16)))]
 * ��������������֣�Ҫ���������������
 * T ���� D ���� H ����   ---> �¶ȡ�¶�㡢ʪ��ָ��
 * */
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cassert>
using namespace std;
double A,B,temp,hum,dew; // �¶ȡ�ʪ��ָ����¶��

double dohum(double tt,double dd)  {    // �����¶�tt��¶��dd����ʪ��ָ��
    double e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(dd+273.16))));
    double h = (0.5555)*(e-10.0);
    return tt + h;
}

double dotemp() { // ����¶��dew��ʪ��ָ��hum�����¶�
    double e = 6.11 * exp(5417.7530 * ((1/273.16) - (1/(dew+273.16))));
    double h = (0.5555) *(e-10.0);
    return hum - h; 
}

double dodew() { // �����¶�temp��ʪ��ָ��hum����¶��
    double x = 0;
    double delta = 100;
    // ¶��delta��ʪ��ָ�������ȹ�ϵ
    // ����ֵ������������˾ͼ������˾���
    for(delta = 100;delta>.00001;delta /=2.0) {
        if(dohum(temp,x)>hum) x -= delta;
        else x += delta;
    }
    return x; // ����¶��x
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