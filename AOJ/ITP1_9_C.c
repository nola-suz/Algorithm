#include <stdio.h>
#include <string.h>
char t1[1510];
char t2[1510];
int main(){
    int n;
    int a=0,b=0;
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s %s",&t1,&t2);
        if(strcmp(t1,t2)==0) a++,b++;
        if(strcmp(t1,t2)>0) a+=3;
        if(strcmp(t1,t2)<0) b+=3;
    }
    printf("%d %d\n",a,b);
    return 0;
}