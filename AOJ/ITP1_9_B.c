#include <stdio.h>
#include <string.h>
char t[1510];
int main(){
    int i,j;
    int n,m;
    int cnt=0;
    int h;
    while(scanf("%s",&t)){
        if(strcmp(t,"-")==0) break;
        n=strlen(t);
        for(i=0;i<n;i++){
            t[n+i]=t[i];
        }
        scanf("%d",&m);
        cnt=0;
        for(i=0;i<m;i++){
            scanf("%d",&h);
            cnt+=h;     
        }
        cnt%=n;
        for(i=0;i<n;i++){
            printf("%c",t[i+cnt]);
        }
        puts("");
    }
    return 0;
}