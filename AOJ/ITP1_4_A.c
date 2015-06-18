#include <stdio.h>
 
int main(){
    int a,b;
    double _a,_b;
    // 整数型(int, long, unsigend intなど)で/演算子を使うと余りは切り捨てとなる。
    // 例
    // 4/2 -> 2
    // 5/2 -> 2
    // 6/2 -> 2
    // 1/2 -> 0
    // 7/3 -> 2
    scanf("%d%d",&a,&b);
    printf("%d ",a/b);
    printf("%d ",a%b);
    _a=a;
    _b=b;
    //浮動小数点型では/演算子を使っても余りは切り捨てにならない。
    printf("%lf\n",_a/_b);
    return 0;
}