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

int h, w;
vvll a;
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

bool inside(int y, int x) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

ll ijk(int y, int x) {
    vvll vv;
    initvv(vv, h, w, INFL);
    vv[y][x] = 0;
    priority_queue<pair<ll, pii>> pq;
    pq.push(mkp(0, pii(y, x)));

    while(pq.size()) {
        auto top = pq.top();
        pq.pop();

        int co = -top.fi;
        int yy = top.se.fi;
        int xx = top.se.se;

        if (vv[yy][xx] < co) continue;

        rep(i, 4) {
            int ny = yy + dy[i];
            int nx = xx + dx[i];

            if (!inside(ny, nx)) continue;
            int nco = co + a[ny][nx];
            if (vv[ny][nx] <= nco) continue;

            vv[ny][nx] = nco;
            pq.push(mkp(-nco, mkp(ny, nx)));
        }
    }

    return vv[h-1][0] + vv[h-1][w-1] + vv[0][w-1] + a[y][x];
}

void mainmain(){
    cin >> h >> w;
    initvv(a, h, w);
    rep(i, h) rep(j, w) cin >> a[i][j];

    ll ans = INFL;
    rep(i, h) rep(j, w) {
        mins(ans, ijk(i, j));
    }
    cout << ans << endl;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(20);
    mainmain();
}