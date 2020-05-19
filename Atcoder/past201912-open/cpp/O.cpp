#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll;
typedef vector<vector<long long> > vvll;

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

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i,n) _rep2((i),0,(n))
#define _rep2(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define fi first
#define se second
#define mkp make_pair
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
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)

void mainmain(){
    int n;
    cin >> n;
    vvll a;
    initvv(a, n, 6);
    rep(i, n) rep(j, 6) cin >> a[i][j];
    map<ll, vint> ma;
    rep(i, n) {
        rep(j, 6) {
            if (ma.count(-a[i][j]) == 0) {
                ma[-a[i][j]] = vint(0);
            }
            ma[-a[i][j]].emplace_back(i);
        }
    }
    vector<double> now(n);
    double now_max = 0;
    double p = 1;
    p /= 6;
    for(auto x: ma) {
        ll key = x.fi;
        vint val = x.se;
        auto tmp = now_max;
        for(auto y: val) {
            now[y] += tmp / 6. + p;
            maxs(now_max, now[y]);
        }
    }

    cout << now_max + 1 << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}