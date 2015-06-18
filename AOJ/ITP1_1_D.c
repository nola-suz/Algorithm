#include <stdio.h>
 
int main(void) {
    int a;
    int h=0,m=0,s=0;
    scanf("%d",&a);
    while(a>=3600) a-=3600,h++;
    while(a>=60) a-=60,m++;
    s=a;
    printf("%d:%d:%d\n",h,m,s);
    return 0;
}