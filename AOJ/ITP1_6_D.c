#include <stdio.h>
int main(){
    int n,m;
    int a[110][110];
    int b[110];
    int i,j;
    int c;
    scanf("%d %d\n",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++){
        c=0;
        for(j=0;j<m;j++){
            c+=a[i][j]*b[j];
        }
        printf("%d\n",c);
    }
    return 0;
}