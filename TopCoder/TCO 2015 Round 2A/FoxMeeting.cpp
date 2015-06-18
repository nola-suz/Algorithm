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
#include <fstream>
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

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
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
//max flow (dinic)
template<class V> class MaxFlow_dinic{
public:
    struct edge{int to,reve;V cap;};
    static const int MV = 1100;
    vector<edge> E[MV];
    int itr[MV],lev[MV];

    void add_edge(int x,int y,V cap,bool undir=false){
        E[x].push_back((edge){y,(int)E[y].size(),cap});
        E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
    }

    void bfs(int cur){
        memset(lev,0xff,sizeof(lev));
        queue<int> q;
        lev[cur]=0;
        q.push(cur);
        while(q.size()){
            int v=q.front();
            q.pop();
            for(__typeof(E[v].begin()) e=E[v].begin();e!=E[v].end();e++) if(e->cap>0&&lev[e->to]<0) lev[e->to]=lev[v]+1,q.push(e->to);
        }
    }

    V dfs(int from,int to,V cf){
        if(from==to){
            return cf;
        }
        for(;itr[from]<E[from].size();itr[from]++){
            edge* e=&E[from][itr[from]];
            if(e->cap>0&&lev[from]<lev[e->to]){
                V f=dfs(e->to,to,min(cf,e->cap));
                if(f>0){
                    e->cap-=f;
                    E[e->to][e->reve].cap += f;
                    return f;
                }
            }
        }
        return 0;
    }

    V maxflow(int from,int to){
        V fl=0,tf;
        while(1){
            bfs(from);
            if(lev[to]<0) return fl;
            memset(itr,0,sizeof(itr));
            while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
        }
    }
};
VV(pii) vv;
int dd[55][55];
bool used[55];
int ff[55];
int n;
struct FoxMeeting {
  vector<int> A;
  vector<int> B;
  vector<int> L;
  vector<int> foxes;
  vint tfox;
  bool dfs(int x,int pre){
    // if(used[x]) return 0;
    bool ret=false;
    if(ff[x]) ret=true;
    rep(i,vv[x].size()){
        if(vv[x][i].F==pre) continue;
        if(dfs(vv[x][i].F,x)) ret=true;
    }
    return used[x]=ret;
  }
  bool check(int d,int r){
    tfox=foxes;
    rep(i,tfox.size()){
        int pos=foxes[i];
        rep(j,n){
            if(dd[foxes[i]][j]>d) continue;
            if(dd[foxes[i]][j]+dd[j][r]==dd[foxes[i]][r]&&dd[pos][r]>dd[j][r]){
                pos=j;
            }
        }
        tfox[i]=pos;
    }
    rep(i,n) ff[i]=0,used[i]=false;
    rep(i,tfox.size()){
        ff[tfox[i]]++;
    }
    dfs(tfox[0],-1);
    MaxFlow_dinic<int> mf;
    int start=1000;
    int goal=1001;
    // dump(r);
    rep(i,foxes.size()){
            mf.add_edge(start,foxes[i],1);
    }
    int cnt=0;
    rep(i,n){
        if(used[i]){
            cnt++;
            mf.add_edge(i+100,goal,1);
        }
    }
    rep(i,n){
        if(!used[i]) continue;
        rep(j,foxes.size()){
            if(dd[i][foxes[j]]>d) continue;
            mf.add_edge(foxes[j],100+i,1);
        }
    }
    if(mf.maxflow(start,goal)==cnt) return true;
    return false;
  }
  int maxDistance(vector<int> _A, vector<int> _B, vector<int> _L, vector<int> _foxes) {
    A = _A, B = _B, L = _L, foxes = _foxes;
    n=A.size()+1;
    rep(i,A.size()){
        A[i]--;
        B[i]--;
    }
    rep(i,foxes.size()){
        foxes[i]--;
    }
    int l=-1,r=INF;
    // int n=A.size()+1;
    vv=VV(pii)(n);
    rep(i,n) rep(j,n){
        dd[i][j]=INF;
    }
    rep(i,n){
        dd[i][i]=0;
    }
    rep(i,A.size()){
        dd[A[i]][B[i]]=L[i];
        dd[B[i]][A[i]]=L[i];
    }
    rep(k,n) rep(i,n) rep(j,n) dd[i][j]=min(dd[i][j],dd[i][k]+dd[k][j]);
    // rep(i,n) rep(j,n) cout<<i<<" "<<j<<" "<<dd[i][j]<<endl;
    rep(i,A.size()){
        vv[A[i]].PB(pii(B[i],L[i]));
        vv[B[i]].PB(pii(A[i],L[i]));
    }
    // cout<<endl;
    while(r-l>1){
        int mid=(r+l)>>1;
        bool ok=false;
        rep(i,n){
            bool tmp=check(mid,i);
            if(tmp){
                // cout<<"pos "<<i<<endl;
            }
            ok|=tmp;
        }
        // cout<<mid<<" "<<(ok?"ok":"no")<<endl;
        if(ok){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    
    return r;
  }
};

// CUT begin
ifstream data("FoxMeeting.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> A, vector<int> B, vector<int> L, vector<int> foxes, int __expected) {
    time_t startClock = clock();
    FoxMeeting *instance = new FoxMeeting();
    int __result = instance->maxDistance(A, B, L, foxes);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> A;
        from_stream(A);
        vector<int> B;
        from_stream(B);
        vector<int> L;
        from_stream(L);
        vector<int> foxes;
        from_stream(foxes);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, B, L, foxes, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1433306615;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "FoxMeeting (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
