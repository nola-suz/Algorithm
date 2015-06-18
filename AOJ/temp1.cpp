#include <bits/stdc++.h>
using namespace std;
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))

int main(){
    int n;
    while(cin>>n,n){
        vector<string> v(n);
        rep(i,n) cin>>v[i];
        int ans=1e9;
        rep(i,51){
            vector<string> tmp=v;
            rep(j,n){
                tmp[j]=v[j].substr(0,1);
                rep(k,v[j].size()){
                    if(k+1!=v[j].size()&&v[j][k]=='a'||v[j][k]=='i'||v[j][k]=='u'||v[j][k]=='e'||v[j][k]=='o'){
                        tmp[j]+=v[j].substr(k+1,1);
                    }
                }
                if(tmp[j].size()>=i){
                    tmp[j]=tmp[j].substr(0,i);
                }
            }
            sort(tmp.begin(),tmp.end());
            tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            if(n==tmp.size()){
                ans=min(ans,i);
            }
        }
        if(ans==1e9) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}