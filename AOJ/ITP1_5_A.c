#include <stdio.h>
int main(){
    int a,b;
    int i,j;
    for(;;){
        scanf("%d %d",&a,&b);
        if(a==0&&b==0) break;
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
                printf("#");
            }
            puts("");
        }
        puts("");
    }
    return 0;
}