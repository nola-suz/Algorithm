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

int n;
vvint a;
ll ans = -INFL;
vint group;

void calc() {
    ll tmp = 0;
    rep(i, n) rep(j, i+1, n) {
        if (group[i] == group[j]) {
            tmp += a[i][j];
        }
    }
    // cout << "ans " << endl;

    // rep(i, n) {
    //     cout << group[i] << " ";
    // }
    // cout << endl;
    // cout << tmp << endl << endl;
    maxs(ans, tmp);
}

void rec(int idx=0) {
    if (idx == n) {
        return calc();
    }

    rep(i, 3) {
        group[idx] = i;
        rec(idx+1);
    }
}

void mainmain(){
    cin >> n;
    initvv(a, n, n);
    rep(i, n) rep(j, i+1, n) {
        cin >> a[i][j];
        a[j][i] = a[i][j];
    }

    // rep(i, n) {
    //     rep(j, n) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    group = vint(n);
    rec();
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}