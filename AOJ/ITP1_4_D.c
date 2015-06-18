#include <stdio.h>
int main(){
    int n;
    int MIN=100000000;
    int MAX=-100000000;
    long long SUM=0;
    int i;
    // この問題では入力された数字の合計を求める必要があるが、
    // 数字の合計は最大で10000000000(100億)になる。
    // int型で表現できる最大値は2147483647(20億程度)なので、オーバーフロー(詳しくはググってください)を起こしてしまう。
    // そこで、数字の合計を求めるための変数をlong long型にすることで対処する必要がある。
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        if(t<MIN) MIN=t;
        if(t>MAX) MAX=t;
        SUM+=t;
    }
    printf("%d %d %ld\n",MIN,MAX,SUM);
    return 0;
}