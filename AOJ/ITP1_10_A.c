#include <stdio.h>
#include <math.h>
int main(){
    double x1,x2;
    double y1,y2;
    // sqrt関数は平方根を計算する関数。(#include <math.h> が必要)
    scanf("%lf %lf",&x1,&y1);
    scanf("%lf %lf",&x2,&y2);
    x1-=x2;
    y1-=y2;
    printf("%lf\n",sqrt(x1*x1+y1*y1));
    return 0;
}