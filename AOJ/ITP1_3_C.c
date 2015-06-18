#include <stdio.h>
 
int main(){
    int a,b;
    for(;;){
        scanf("%d%d",&a,&b);
        //a=0 & b=0-> end
        if(a==0&&b==0) return 0;
        if(a<b) printf("%d %d\n",a,b);
        else printf("%d %d\n",b,a);
    }
    return 0;
}