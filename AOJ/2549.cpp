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
#include <iomanip>
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
#define LDcout(x,n) fixed<<setprecision(n)<<x

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
template <class T> class MinCostFlow {
public:
    // struct edge { int to, capacity; T cost;int reve;};
    class edge{
    public:
        int to;
        int capacity;
        T cost;
        int reve;
    
        edge(int _to, int _capacity, int _reve, T _cost){
          this->to = _to;
          this->capacity = _capacity;
          this->reve = _reve;
          this->cost = _cost;
        }
    };
    static const int MV = 1100;//頂点数
    vector<edge> E[MV];
    T dist[MV];
    int prev_v[MV], prev_e[MV], NV;
    
    MinCostFlow() { init(MV); }
    void init(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
    void add_edge(int x,int y, int cap, T cost) {
        E[x].push_back(edge(y,cap,E[y].size(),cost));
        E[y].push_back(edge(x,0,E[x].size()-1,-cost)); /* rev edge */
    }
    
    T minCost(int from, int to, int flow) {
        T res=0;
        T inf=std::numeric_limits<T>::max()/2;
        memset(prev_v,0,sizeof(prev_v));
        memset(prev_e,0,sizeof(prev_e));
        while(flow>0) {
            fill(dist, dist+NV, inf);
            dist[from]=0;
            bool up=true;
            while(up) {
                up=false;
                for(int v=0;v<NV;++v) {
                    if(dist[v]==inf) continue;
                    for(int i=0;i<E[v].size();++i) {
                        edge &e=E[v][i];
                        if(e.capacity>0 && dist[e.to]>dist[v]+e.cost) {
                        	cout<<e.to<<" "<<v<<endl;
                        	system("sleep 1");
                            dist[e.to]=dist[v]+e.cost;
                            prev_v[e.to]=v;
                            prev_e[e.to]=i;
                            up=true;
                        }
                    }
                }
            }
            if(dist[to]==inf) return -1;
            int lc=flow;
            for(int v=to;v!=from;v=prev_v[v]){
                lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
            }
            flow -= lc;
            res += lc*dist[to];
            for(int v=to;v!=from;v=prev_v[v]) {
                edge &e=E[prev_v[v]][prev_e[v]];
                e.capacity -= lc;
                E[v][e.reve].capacity += lc;
            }
        }
        return res;
    }
};
void mainmain(){
	int n;
	int s;
	cin>>n>>s;
	s--;
	vector<pll> v(n);
	rep(i,n){
		cin>>v[i].F>>v[i].S;
	}
	int start=n+1;
	int goal=n+2;
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
	vector<vector<pll> ed(n);
	rep(i,n){
		mf.add_edge(start,i,1,-max(0LL,v[i].S-max(v[i].F,vv[s][i])));
		cout<<"s "<<i<<" "<<max(0LL,v[i].S-max(v[i].F,vv[s][i]))<<endl;
		mf.add_edge(i,goal,1,0LL);
	}
	rep(i,n){
		rep(j,n){
			if(i==j) continue;
			mf.add_edge(i,j,1,-max(0LL,v[j].S-max(v[j].F,vv[i][j]+v[i].S)) );
			// cout<<i<<" "<<j<<" "<<max(0LL,v[j].S-max(v[j].F,vv[i][j]+v[i].S))<<endl;
		}
	}
	ll ans=mf.minCost(start,goal,1);
	cout<<ans<<endl;
}


signed main() {
	ios_base::sync_with_stdio(false);
  	cout<<fixed<<setprecision(0);
    mainmain();
}