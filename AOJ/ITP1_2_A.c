#include <stdio.h>
 
int main(void) {
    int a;
    int b;
    scanf("%d%d",&a,&b);
    // putsは文字列を出力する関数で、最後に改行を出力する。
    if(a<b) puts("a < b");
    else if(a>b) puts("a > b");
    else puts("a == b");
    return 0;
}