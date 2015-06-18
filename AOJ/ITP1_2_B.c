#include <stdio.h>
 
int main(void) {
    int a;
    int b;
    int c;
    scanf("%d%d%d",&a,&b,&c);
    if(a<b&&b<c) puts("Yes");
    else puts("No");
    return 0;
}