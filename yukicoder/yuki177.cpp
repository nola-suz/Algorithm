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
// #define DEBUG
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
void mainmain(){
	MaxFlow_dinic<int> dinic;
	int W;
	cin>>W;
	int n;
	cin>>n;
	rep(i,n){
		int a;
		cin>>a;
		dinic.add_edge(0,i+1,a);
	}
	int m;
	cin>>m;
	rep(i,m){
		int a;
		cin>>a;
		dinic.add_edge(100+i+1,200,a);
	}
	rep(i,m){
		int t;
		cin>>t;
		vint v(n,0);
		rep(j,t){
			int b;
			cin>>b;
			v[b-1]=1;
		}
		rep(j,n){
			if(v[j]==0){
				dinic.add_edge(j+1,100+i+1,INT_MAX);
			}
		}
	}
	int ans=dinic.maxflow(0,200);
	if(ans>=W) puts("SHIROBAKO");
	else puts("BANSAKUTSUKITA");
}


signed main() {
    mainmain();
}