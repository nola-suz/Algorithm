#include <stdio.h>
#include <string.h>
char t[1510];
int main(){
    int i;
    int n;
    int ans;
    int al[26]={0};
    while(gets(t)){
        n=strlen(t);
        for(i=0;i<n;i++){
            if(!isalpha(t[i])) continue;
            al[tolower(t[i])-'a']++;
        }
    }
    for(i=0;i<26;i++){
        printf("%c : %d\n",'a'+i,al[i]);
    }
    return 0;
}