#include <stdio.h>
int main(){
    int n;
    int room[10][3][4]={};
    int i,j,k;
    int a,b,c,d;
    // 配列の宣言時にint a[10]={}という風に書くと、配列の中身を0で初期化できる。
    // ただし、このように書いて初期化する場合は０以外では不可能
    // また、{}を書かない場合は配列の中身は何が入っているか分からない(未定義)
    // 例
    // int a[3]={};    -> a[0]=0, a[1]=0,a[2]=0
    // int a[3]={-1};  -> a[0]=-1,a[1]=0,a[2]=0
    // int a[3];       -> a[0]=?, a[1]=?,a[2]=?
    // int a[2][2]={};    -> a[0][0]=0,a[0][1]=0,a[1][0]=0,a[1][1]=0
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        room[c-1][b-1][a-1]+=d;
    }
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            for(k=0;k<10;k++){
                printf(" ");
                printf("%d",room[k][j][i]);
            }
            puts("");
        }
        if(i==3) break;
        for(j=0;j<20;j++) printf("#");
        puts("");
    }
    return 0;
}