#include <stdio.h>
#include <string.h>
char t[100000];
int main(){
    int i;
    int n;
    // string.hをインクルードすることで文字列を扱う関数を使うことができる。
    
    // gets関数は文字列を１行読み込む関数
    // char t[100];
    // gets(t);
    // のようにして使用する。
    // scanf("%s",&t);
    // でも似たような処理は行えるが、
    // 入力が
    // This is a pen.
    // のように空白区切りで与えられると、
    // scanfではThisしかとれない。(getsならばThis is a pen.をとれる)

    // strlen関数は文字列の長さを調べる関数。
    // char t[10]="hello";
    // int n=strlen(t); (n=5)
    // のように使用する。

    // isupper関数は大文字かを判別する関数。
    // 大文字ならばtrue,それ以外ならばfalseとなる。
    // char t='B';
    // if(isupper(t)) t='a';
    // のようにして使用する。

    // toupper関数は小文字を大文字にする関数。
    // 小文字ならば大文字、それ以外ならばなにもしない。
    // char t='b';
    // t=toupper(t); (t='B')
    // のようにして使用する。

    // islower,tolower関数に関してはupperと同様なので省略。
    gets(t);
    n=strlen(t);
    for(i=0;i<n;i++){
        if(islower(t[i])) printf("%c",toupper(t[i]));
        else if(isupper(t[i])) printf("%c",tolower(t[i]));
        else printf("%c",t[i]);
    }
    puts("");
    return 0;
}