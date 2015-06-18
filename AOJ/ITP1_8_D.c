#include <stdio.h>
#include <string.h>
char t1[1510];
char t2[1510];
int main(){
    int i,j;
    int n1,n2;
    int ok=0;
    gets(t1);
    gets(t2);
    n1=strlen(t1);
    n2=strlen(t2);
    for(i=0;i<n1;i++){
        t1[i+n1]=t1[i];
    }
    n1*=2;
    for(i=0;i<n1-n2+1;i++){
        for(j=0;j<n2;j++){
            if(t1[i+j]!=t2[j]) break;
            if(j==n2-1) ok=1;
        }
    }
    if(ok) puts("Yes");
    else puts("No");
    return 0;
}