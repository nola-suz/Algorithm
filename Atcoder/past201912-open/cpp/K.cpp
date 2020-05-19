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

template<typename G>
struct DoublingLowestCommonAncestor {
    const int LOG;
    const int ROOT;
    vector<int> dep;
    const G &g;
    vector<vector<int>> table;

    DoublingLowestCommonAncestor(const G &g, int root = 0) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())), ROOT(root) {
        table.assign(LOG, vector<int>(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for(auto &to: g[idx]) {
            if (to != par) dfs(to, idx, d + 1);
        }
    }

    void build() {
        dfs(ROOT, -1, 0);
        for (int k=0; k+1 < LOG; k++) {
            for(int i=0; i < table[k].size(); i++) {
                if (table[k][i] == -1) table[k+1][i] = -1;
                else table[k+1][i] = table[k][table[k][i]];
            }
        }
    }

    int query(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i=LOG-1; i>=0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if (u == v) return u;
        for (int i=LOG-1; i >= 0; i--) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }
};


void mainmain() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    int root = -1;
    rep(i, n) {
        int p;
        cin >> p;
        if (p == -1){
            root = i;
            continue;
        }
        p--;
        graph[p].push_back(i);
    }

    DoublingLowestCommonAncestor<vector<vector<int>>> lca(graph, root);

    lca.build();
    int q;
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (lca.query(a, b) == b) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}