#include <stdio.h>
#include <math.h>
int main(){
    double r;
    double PI=acos(-1);
    // #include <math.h>　と書くと、数学に関係する関数が使えるようになる。
    // acos関数はcosの逆関数であるarccosの値を計算する。
    // 値はラジアンなのに注意
    scanf("%lf",&r);
    printf("%lf %lf\n",PI*r*r,2.0*PI*r);
    return 0;
}