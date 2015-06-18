#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
//#include <utility>
//#include <memory>
//#include <functional>
//#include <deque>
//#include <cctype>
//#include <ctime>
//#include <numeric>
//#include <list>
//#include <iomanip>

//#if __cplusplus >= 201103L
//#include <array>
//#include <tuple>
//#include <initializer_list>
//#include <forward_list>
//
//#define cauto const auto&
//#else

//#endif

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

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

#define MOD 1000000007LL
#define EPS 1e-8
static const int INF=1<<24;
int a[]={2,3,5,7,11,13};
int b[]={4,6,8,9,10,12};

const int MX=150;
const int MN=12;

struct mint{
  ll x;
  mint():x(0){}
  mint(ll x):x((x%MOD+MOD)%MOD){}
  mint operator+=(const mint& a){ if((x+=a.x)>=MOD) x-=MOD; return *this;}
  mint operator-=(const mint& a){ if((x+=MOD-a.x)>=MOD) x-=MOD; return *this;}
  mint operator*=(const mint& a){ (x*=a.x)%=MOD; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
//
// Matrix
struct mat{
  typedef mint TT;
  int h, w;
  vector<vector<TT> > d;
  mat(){}
  mat(int h, int w, TT v=0):h(h),w(w),d(h,vector<TT>(w,v)){}
  void fil(TT v=0){ rep(i,h)rep(j,w) d[i][j] = v;}
  void uni(){ rep(i,h)rep(j,w) d[i][j] = (i==j);}
  mat operator*(const mat& a)const{ // w = a.h
    mat res(h,a.w);
    rep(i,h)rep(k,w)rep(j,a.w) res.d[i][j] += d[i][k]*a.d[k][j];
    return res;
  }
  mat power(ll a){ // h = w
    if(a == 0){
      mat res(h,w); res.uni();
      return res;
    }
    mat res = power(a/2);
    res = res*res;
    if(a&1) res = res*(*this);
    return res;
  }
};
vint cc;
vvint aaa;
vvint bbb;
void fa(int x){
    if(x==0){
        aaa.PB(cc);
        return;
    }
    rep(i,6){
        cc.PB(a[i]);
        fa(x-1);
        cc.pop_back();
    }
}
void fb(int x){
    if(x==0){
        bbb.PB(cc);
        return;
    }
    rep(i,6){
        cc.PB(b[i]);
        fb(x-1);
        cc.pop_back();
    }
}
void mainmain(){
    ll n;
    cin>>n;
    ll aa,bb;
    cin>>aa>>bb;
    // vvll vv;
    vll v=vll(150,0);
    // v[0]=1;
    // ll ans=0;
    if(aa) fa(aa);
    if(bb) fb(bb);
    rep(i,aaa.size()){
        sort(ALL(aaa[i]));
    }
    rep(i,bbb.size()){
        sort(ALL(bbb[i]));
    }
    sort(ALL(aaa));
    sort(ALL(bbb));
    aaa.erase(unique(ALL(aaa)),aaa.end());
    bbb.erase(unique(ALL(bbb)),bbb.end());
    // dump(aaa.size());
    vll ta(150,0LL);
    vll tb(150,0LL);
    rep(i,aaa.size()){
        ll t=0LL;
        rep(j,aaa[i].size()){
            t+=aaa[i][j];
            t%=MOD;
        }
        ta[t]++;
    }
    rep(i,bbb.size()){
        ll t=0LL;
        rep(j,bbb[i].size()){
            t+=bbb[i][j];
            t%=MOD;
        }
        tb[t]++;
    }
    // cout<<v[0]<<endl;
    if(aa==0||bb==0){
        rep(i,150) v[i]=ta[i]+tb[i];
    }
    else{
        rep(i,150){
            rep(j,150){
                if(i+j>=150) break;
                if(ta[i]==0||tb[j]==0) continue;
                v[i+j]+=ta[i]*tb[j];
                v[i+j]%=MOD;
                // if(i+j==6) cout<<ta[i]<<" "<<tb[j]<<endl;
            }
        }
        // rep(i,150) v[i]/=2;
    }
    mint ans=0,sum=0;
    mat vv(MX,MX),x(MX,1);
    reep(i,1,MX){
        vv.d[i][i-1]=1;
    }
    rep(i,MX) vv.d[0][i]=v[i+1];
    x.d[0][0]=1;
    vv=vv.power(n-1);
    x=vv*x;
    reep(i,1,150){
        sum+=v[150-i];
        ans+=x.d[150-i-1][0]*sum;
    }
    cout<<ans.x<<endl;
    // printf("%.13lf\n",ans);
}


signed main() {
    mainmain();
}