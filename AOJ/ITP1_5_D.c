#include <stdio.h>

// 問題文で与えられたc++のコードをC言語に書き換えたコード
// void call(int n){
//     int i=1;
//     int x;
//     CHECK_NUM:
//         x=i;
//         if(x%3==0){
//             printf(" %d",i);
//             goto END_CHECK_NUM;
//         }
//     INCLUDE3:
//         if(x%10==3){
//             printf(" %d",i);
//             goto END_CHECK_NUM;
//         }
//         x/=10;
//         if(x!=0) goto INCLUDE3;
//     END_CHECK_NUM:
//         if(++i<=n) goto CHECK_NUM;
//     printf("\n");
// }

int main(){
    int n;
    int i;
    int x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        x=i;
        if(x%3==0){
            printf(" %d",i);
        }
        else{
            while(x!=0){
                if(x%10==3){
                    printf(" %d",i);
                    x=0;
                }
                x/=10;
            }
        }
    }
    printf("\n");
    return 0;
}