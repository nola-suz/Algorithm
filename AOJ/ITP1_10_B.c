#include <stdio.h>
#include <math.h>
int main(){
    double a,b,c;
    double PI=acos(-1);
    scanf("%lf %lf %lf",&a,&b,&c);
    c/=180.0;
    c*=PI;
    printf("%lf\n%lf\n%lf\n",a*b*0.5*sin(c),a+b+sqrt(a*a+b*b-2.0*a*b*cos(c)),a*b*sin(c)/a);
    return 0;
}