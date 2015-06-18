#include <stdio.h>
int main(){
    int n;
    int card[110];
    char t;
    int i;
    int x;
    //配列cardでは、
    // card[0]-card[12]がスペードの1-13
    // card[13]-card[25]がハートの1-13
    // card[26]-card[38]がクラブの1-13
    // card[39]-card[51]がダイヤの1-13
    // に対応している。
    scanf("%d\n",&n);
    for(i=0;i<110;i++){
        card[i]=0;
    }
    for(i=0;i<n;i++){
        scanf("%c %d\n",&t,&x);
        x-=1;
        if(t=='H') x+=13;
        else if(t=='C') x+=26;
        else if(t=='D') x+=39;
        card[x]=1;
    }
    for(i=0;i<52;i++){
        if(card[i]==0){
            if(i<13) printf("S ");
            else if(i<26) printf("H ");
            else if(i<39) printf("C ");
            else  printf("D ");
            printf("%d\n",(i%13)+1);
        }
    }
    return 0;
}