#include <stdio.h>
#include <math.h>
int main(){
    double a[1010];
    int n;
    double m=0;
    double ans=0;
    int i;
    // pow関数はべき乗を計算する関数。
    // pow(3,2)のように書くと3^2(3の2乗)を返す。
    // pow(4,0.5)のように書くと4^(0.5) (4の平方根)を返す。
    while(scanf("%d",&n),n!=0){
        m=0;
        ans=0;
        for(i=0;i<n;i++){
            scanf("%lf",&a[i]);
            m+=a[i];
        }
        m/=(double)n;
        for(i=0;i<n;i++){
            ans+=pow(a[i]-m,2.0);
        }
        ans/=(double)n;
        printf("%lf\n",sqrt(ans));
    }
    return 0;
}