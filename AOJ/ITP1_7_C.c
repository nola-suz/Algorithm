#include <stdio.h>
int main(){
    int r,c;
    int i,j;
    int rc[110][110];
    int SUM;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
        SUM=0;
        for(j=0;j<c;j++){
            scanf("%d",&rc[i][j]);
            SUM+=rc[i][j];
        }
        rc[i][c]=SUM;
    }
    for(i=0;i<c+1;i++){
        SUM=0;
        for(j=0;j<r;j++){
            SUM+=rc[j][i];
        }
        rc[r][i]=SUM;
    }
    for(i=0;i<r+1;i++){
        for(j=0;j<c+1;j++){
            if(j!=0) printf(" ");
            printf("%d",rc[i][j]);
        }
        puts("");
    }
    return 0;
}