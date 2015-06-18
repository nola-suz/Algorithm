#include <stdio.h>
int main(){
    int a,b;
    char t;
    // a+=b は a=a+b と書くのと同じ(-, *, /, %についても同様)
    while(1){
        scanf("%d %c %d",&a,&t,&b);
        if(t=='?') break;
        if(t=='+') a+=b;
        if(t=='-') a-=b;
        if(t=='*') a*=b;
        if(t=='/') a/=b;
        printf("%d\n",a);
    }
    return 0;
}