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
    vint c(n);
    rep(i, n) cin >> c[i];
    vint st = c;

    int q;
    cin >> q;
    int emin = INF;
    int omin = INF;
    int sall = 0;
    int soall = 0;
    rep(i, n) {
        if (i&1) {
            mins(emin, c[i]);
        }
        else {
            mins(omin, c[i]);
        }
    }

    // dump(emin);
    // dump(omin);

    rep(i, q) {
        int ope;
        cin >> ope;
        if (ope == 1) {
            int x, a;
            cin >> x >> a;
            x--;
            // even
            if (x&1) {
                if (c[x] - sall >= a) {
                    c[x] -= a;
                    mins(emin, c[x]);
                }
            }
            // odd
            else {
                if (c[x] - sall - soall >= a) {
                    c[x] -= a;
                    mins(omin, c[x]);
                }
            }
        }
        else if (ope == 2) {
            int a;
            cin >> a;
            if (omin - sall - soall >= a) {
                soall += a;
            }
        }
        else if (ope == 3) {
            int a;
            cin >> a;
            if (omin - sall - soall >= a && emin - sall >= a) {
                sall += a;
            }
        }

        // dump(sall);
        // dump(soall);
        // dump(emin);
        // dump(omin);
        // rep(i, n) cout << c[i] << " ";
        // cout << endl << endl;
    }

    ll ans = 0;
    rep(i, n) {
        ans += st[i] - c[i];
    }
    ans += 1LL* sall * n;
    ans += 1LL * soall * ((n+1)/2);

    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}