#include <stdio.h>
#include <string.h>
char t[1010];
int main(){
    int i;
    int n;
    int ans;
    // すべての文字は内部的にはasciiコードに対応した数字で表現されている。
    // 例えば
    // char t='a';
    // t+=1;
    // printf("%c\n",t);
    // のようなコードを書くと
    // b
    // と出力される。
    // 'a'-'z'の数字は連続している。
    // 例
    // chat t1='A',t2='3';
    // t1=t+3; (t1='D')
    // t2=t2+3; (t2='6')
    while(scanf("%s",&t)){
        n=strlen(t);
        ans=0;
        if(n==1&&t[0]=='0') break;
        for(i=0;i<n;i++){
            ans+=t[i]-'0';
        }
        printf("%d\n",ans);
    }
    return 0;
}