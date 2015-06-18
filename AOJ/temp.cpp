#include <bits/stdc++.h>
using namespace std;
#define reep(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) reep((i),0,(n))
string ans="";
string tmp="";
vector<string> v;
vector<vector<int>> vv;
vector<vector<string>> dp;
int w,h;
bool check(int a,int b){
    if(0<=a&&a<h&&0<=b&&b<w) return true;
    return false;
}
string cmp(string a,string b){
    if(a.size()<b.size()) return b;
    if(a.size()>b.size()) return a;
    if(a>b) return a;
    return b;
}
string foo(int a,int b){
    // tmp+=v[a].substr(b,1);
    if(vv[a][b]) return dp[a][b];
    vv[a][b]=1;
    // if(ans.size()<tmp.size()) ans=tmp;
    // else if(ans.size()==tmp.size()&&ans<tmp) ans=tmp;
    string ret="";
    if(check(a+1,b)&&isdigit(v[a+1][b])) ret=cmp(ret,foo(a+1,b));
    if(check(a,b+1)&&isdigit(v[a][b+1])) ret=cmp(ret,foo(a,b+1));
    // tmp=tmp.substr(0,tmp.size()-1);
    return dp[a][b]=v[a].substr(b,1)+ret;
}
int main(){
    while(cin>>w>>h,h||w){
        v.clear();
        v=vector<string>(h);
        vv=vector<vector<int>>(h,vector<int>(w,0));
        dp=vector<vector<string>>(h,vector<string>(w,""));
        rep(i,h){
            cin>>v[i];
        }
        ans="";
        rep(i,h){
            rep(j,w){
                if(isdigit(v[i][j])&&v[i][j]!='0'){
                    if(vv[i][j]) continue;
                    ans=cmp(ans,foo(i,j));
                    // cout<<i<<" "<<j<<" "<<v[i][j]<<" "<<ans<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
}