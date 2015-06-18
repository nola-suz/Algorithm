#include <stdio.h>
int main(){
    int a,b;
    int i,j,k;
    int ans;
    while(1){
        scanf("%d %d",&a,&b);
        if(a==0&&b==0){
            break;
        }
        ans=0;
        for(i=1;i<a-1;i++){
            for(j=i+1;j<a;j++){
                for(k=j+1;k<a+1;k++){
                    if(i+j+k==b) ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}