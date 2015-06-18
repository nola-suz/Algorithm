#include <stdio.h>
#include <string.h>
char t1[1510];
char t2[1510];
int main(){
    int i,j;
    int n1,n2;
    int cnt=0;
    // strcmp関数は文字列の比較を行うことができる関数。
    // ２つの文字列を辞書式順序で比較し、
    // １つ目の文字列の方が小さい(辞書だと早く出る)ときは負の値、
    // ２つ目の文字列の方が小さい(辞書だと早く出る)ときは正の値、
    // ２つの文字列が等しい場合は０、
    // を返す。
    scanf("%s",t1);
    for(i=0;i<strlen(t1);i++){
        t1[i]=tolower(t1[i]);
    }
    while(scanf("%s",t2)){
        if(strcmp(t2,"END_OF_TEXT")==0) break;
        for(i=0;i<strlen(t2);i++){
            t2[i]=tolower(t2[i]);
        }
        if(strcmp(t1,t2)==0) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}