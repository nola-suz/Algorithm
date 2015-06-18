#include <stdio.h>
int main(){
    int a,b;
    int i,j;
    for(;;){
        scanf("%d %d",&a,&b);
        if(a==0&&b==0) break;
        for(i=0;i<a;i++){
            for(j=0;j<b;j++){
				// i行j列のマスが#か.かはi+jが偶数か奇数かで判別が可能である。(ただし、0<=i<=a-1,0<=j<=b-1)
				// 左上のマスは0行0列目とする。
                if((i+j)%2==0) printf("#");
                else printf(".");
            }
            puts("");
        }
        puts("");
    }
    return 0;
}