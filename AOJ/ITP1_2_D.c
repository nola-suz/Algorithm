#include <stdio.h>
 
int main(){
    int W,H;
    int x,y,r;
    scanf("%d %d %d %d %d",&W,&H,&x,&y,&r);
    if(H<y+r) puts("No");
    else if(0>y-r) puts("No");
    else if(W<x+r) puts("No");
    else if(0>x-r) puts("No");
    else puts("Yes");
    return 0;
}