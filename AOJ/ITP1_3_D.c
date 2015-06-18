#include <stdio.h>
 
int main(){
    int a,b;
    int c;
    int i;
    int cnt=0;
    scanf("%d%d%d",&a,&b,&c);
	// 演算子%は余りを計算する。
	// 例
	// 5%2  -> 1
	// 6%2  -> 0
	// 2%10 -> 2
	// 5%3  -> 2
    for(i=a;i<=b;i++){
        if(c%i==0){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}