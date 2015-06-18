#include <stdio.h>
 
int main(){
    int x;
    int i;
    for(i=1;;i++){
        scanf("%d",&x);
        //x=0 -> end
        if(x==0) break;
        printf("Case %d: %d\n",i,x);
    }
    return 0;
}