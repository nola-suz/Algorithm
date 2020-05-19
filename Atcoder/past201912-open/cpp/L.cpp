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

struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

long double dist(int a, int b, int c, int d) {
    long double di = (a-c)*(a-c) + (b-d)*(b-d);
    return sqrt(di);
}

long double solve(vint x, vint y, vint c) {
    int n = x.size();
    UnionFind uf(n);

    priority_queue<pair<long double, pair<int, int>>> pq;

    rep(i, n) {
        rep(j, i) {
            long double cost = dist(x[i], y[i], x[j], y[j]);
            if (c[i] != c[j]) cost *= 10;
            pq.push(mkp(-cost, mkp(i, j)));
        }
    }

    long double ret = 0;
    while(pq.size()) {
        auto top = pq.top();
        pq.pop();

        int a = top.se.fi;
        int b = top.se.se;
        long double cost = -top.fi;
        if (uf.find(a) != uf.find(b)) {
            uf.unite(a, b);
            ret += cost;
        }
    }

    return ret;
}

void mainmain(){
    int n, m;
    cin >> n >> m;
    vint x(n), y(n), c(n);
    vint X(m), Y(m), C(m);
    rep(i, n) cin >> x[i] >> y[i] >> c[i];
    rep(i, m) cin >> X[i] >> Y[i] >> C[i];


    long double ans = INF;
    rep(i, 1<<m) {
        vint xx = x, yy = y, cc = c;
        rep(j, m) {
            if ((1<<j)&i) {
                xx.emplace_back(X[j]);
                yy.emplace_back(Y[j]);
                cc.emplace_back(C[j]);
            }
        }
        mins(ans, solve(xx, yy, cc));
    }

    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}