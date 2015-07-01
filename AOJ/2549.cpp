#include <bits/stdc++.h>
using namespace std;
 
 
typedef long long ll,LL;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
 
// #define VV(T) vector<vector< T > >
 
template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}
 
template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}
 
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define F first
#define S second
#define mkp make_pair
#define RALL(v) (v).rbegin(),(v).rend()
#define DEBUG
#ifdef DEBUG
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#else
#define dump(x) 
#define debug(x) 
#endif
#define LDcout(x,n) fixed<<setprecision(n)<<x
 
#define MOD 1000000007LL
#define EPS 1e-8
static const int INF=1<<24;
int n,s;
int main(){
    cin>>n>>s;
    s--;
    vector<pair<pll,int> > v(n);
    rep(i,n){
        cin>>v[i].F.F>>v[i].F.S;
        v[i].S=i;
        swap(v[i].F.F,v[i].F.S);
    }
    sort(ALL(v));
    rep(i,n){
        swap(v[i].F.F,v[i].F.S);
    }
    vvll vv;
    initvv(vv,n,n);
    rep(i,n){
        rep(j,n){
            cin>>vv[i][j];
        }
    }
    rep(k,n){
        rep(i,n){
            rep(j,n){
                vv[i][j]=min(vv[i][j],vv[i][k]+vv[k][j]);
            }
        }
    }
    vll dp(n,LLONG_MIN/2);
    rep(i,n){
        if(vv[s][v[i].S]>v[i].F.S) continue;
        dp[v[i].S]=v[i].F.S-max(v[i].F.F,vv[s][v[i].S]);
    }
    rep(i,n){
        rep(j,n){
            if(v[i].F.S+vv[v[i].S][v[j].S]>v[j].F.S) continue;
            ll t=v[j].F.S-max(v[j].F.F,vv[v[i].S][v[j].S]+v[i].F.S);
            dp[v[j].S]=max(dp[v[j].S],dp[v[i].S]+t);
        }
    }
    ll ans=0;
    rep(i,n){
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
}