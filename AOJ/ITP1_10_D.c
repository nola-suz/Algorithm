#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    double a[1010];
    double b[1010];
    int n;
    double m=0;
    double ans=0;
    int i,j;
    // abs関数は数字の絶対値を返す関数。
    // abs(-1)だと1を返す。
    // abs( 1)でも1を返す。
    // 浮動小数点型の絶対値を求めたい場合は#include <math.h> ,
    // 整数型の絶対値を求めたい場合は     #include <stdlib.h> ,
    // と書く必要がある。（それぞれで別のヘッダが必要。詳しくはググってください）
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%lf",&b[i]);
    }
    for(i=1;i<4;i++){
        m=0;
        for(j=0;j<n;j++){
            m+=pow(abs(a[j]-b[j]),i);
        }
        printf("%lf\n",pow(m,1.0/(double)i));
    }
    m=0;
    for(i=0;i<n;i++){
        m=fmax(m,abs(a[i]-b[i]));
    }
    printf("%lf\n",m);
    return 0;
}