// prime number hurui
 
const int maxn=1000000;
int f[maxn],prime[maxn];
 
int GenP() {
	int i,tot,p,tmp;
	tot=0;
	for (i=2;i<maxn;++i) f[i]=i;
	for (p=2;p<maxn;++p)
	{
		if (f[p]==p) prime[tot++]=p;
		for (i=0;i<tot && prime[i]<=f[p];++i)
		{
			tmp=prime[i]*p;
			if (tmp<maxn) 
				f[tmp]=prime[i];
			else
				break;
		}
	}
}
/*********************************************************/
// 2-D kika
#define EPS 1e-8
 
typedef complex<double> P;
typedef const P &rP;
typedef pair<P,P> seg;
//naiseki
double dot(rP a, rP b){
    return real(a) * real(b) + imag(a) * imag(b);
}
//gaiseki
double cross(rP a, rP b){
    return real(a) * imag(b) - imag(a) * real(b);
}
double norm(P x){
	return real(x) * real(x) + imag(x) * imag(x);
}
 
int ccw(const seg &s, P c){
    P b = s.second - s.first;
    c -= s.first;
    double cr = cross(b, c);
    if(cr < -EPS){ return 1; }
    if(cr > EPS){ return -1; }
    if(dot(b, c) < -EPS){ return 2; }
    if(norm(b) < norm(c) - EPS){ return -2; }
    return 0;
}
 
bool intersectSS(const seg &s, const seg &t){
    return ccw(s, t.first) * ccw(s, t.second) <= 0 &&
           ccw(t, s.first) * ccw(t, s.second) <= 0;
}
 
double distanceSP(const seg &s, rP c){
    rP a = s.first, b = s.second;
    if(dot(b - a, c - a) <= 0.0) return abs(c - a);
    if(dot(a - b, c - b) <= 0.0) return abs(c - b);
    return abs(cross(b - a, c - a)) / abs(b - a);
}
 
double distanceSS(const seg &s, const seg &t){
    if(intersectSS(s, t)){ return 0.0; }
    return min(min(distanceSP(s, t.first), distanceSP(s, t.second)),
               min(distanceSP(t, s.first), distanceSP(t, s.second)));
}

/********************************************************************************************/
typedef complex<double> P;
 
// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)
// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
 
// ベクトルaの絶対値を求める
double length = abs(a);
 
// 2点a,b間の距離を求める
double distance = abs(a-b);
 
// ベクトルaの単位ベクトルを求める
P b = a / abs(a);
 
// ベクトルaの法線ベクトルn1,n2を求める
P n1 = a * P(0, 1);
P n2 = a * P(0, -1);
 
// ベクトルaの単位法線ベクトルun1,un2を求める
P un1 = (a * P(0, +1)) / abs(a);
P un2 = (a * P(0, -1)) / abs(a);
 
// 内積 (dot product) : a・b = |a||b|cosΘ
double dot(P a, P b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
 
// 外積 (cross product) : a×b = |a||b|sinΘ
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
 
// 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
int is_orthogonal(P a1, P a2, P b1, P b2) {
  return EQ( dot(a1-a2, b1-b2), 0.0 );
}
 
// 2直線の平行判定 : a//b <=> cross(a, b) = 0
int is_parallel(P a1, P a2, P b1, P b2) {
  return EQ( cross(a1-a2, b1-b2), 0.0 );
}
 
// 点cが直線a,b上にあるかないか
int is_point_on_line(P a, P b, P c) {
  return EQ( cross(b-a, c-a), 0.0 );
}
 
// 点cが線分a,b上にあるかないか(1)
int is_point_on_line(P a, P b, P c) {
  return EQ( cross(b-a, c-a), 0.0 ) &&
         (dot(b-a, c-a) > -EPS) &&
         (dot(a-b, c-b) > -EPS);
}
 
// 点cが線分a,b上にあるかないか(2)
int is_point_on_line(P a, P b, P c) {
  // |a-c| + |c-b| <= |a-b| なら線分上
  return (abs(a-c) + abs(c-b) < abs(a-b) + EPS);
}
 
// 点a,bを通る直線と点cとの距離
double distance_l_p(P a, P b, P c) {
  return abs(cross(b-a, c-a)) / abs(b-a);
}
 
// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}
 
// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(P a1, P a2, P b1, P b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}
 
// a1,a2を端点とする線分とb1,b2を端点とする線分の交点計算
P intersection_ls(P a1, P a2, P b1, P b2) {
  P b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);
 
  return a1 + (a2-a1) * t;
}
 
// a1,a2を通る直線とb1,b2を通る直線の交差判定
int is_intersected_l(P a1, P a2, P b1, P b2) {
  return !EQ( cross(a1-a2, b1-b2), 0.0 );
}
 
// a1,a2を通る直線とb1,b2を通る直線の交点計算
P intersection_l(P a1, P a2, P b1, P b2) {
  P a = a2 - a1; P b = b2 - b1;
  return a1 + a * cross(b, b1-a1) / cross(b, a);
}
/********************************************************************************************/
//rand

class XorShift{
public:
  static int rand();
private:
  static unsigned int x;
  static unsigned int y;
  static unsigned int z;
  static unsigned int w;
  static unsigned int t;
};
unsigned int XorShift::x = 123456789;
unsigned int XorShift::y = 362436069;
unsigned int XorShift::z = 521288629;
unsigned int XorShift::w = 88675123;
unsigned int XorShift::t = 1;
 
int XorShift::rand()
{
  t = x ^ (x << 11);
  x = y;
  y = z;
  z = w;
  w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  return w & 0x7fffffff;
}

/*********************************************************************/
//struct example
struct state{
    int pos, bit, dist;
    bool operator< (const state &s) const{
        return dist > s.dist;
    }
};
/*********************************************************************/
int gcd(int m,int n){
	// 引数に０がある場合は０を返す
	if((0==m)||(0==n)) return 0;
	// ユークリッドの方法
	while(m!=n){
		if(m>n) m=m-n;
		else n=n-m;
	}
	return m;
}
int lcm(int m,int n){
	// 引数に０がある場合は０を返す
	if ((0==m)||(0==n)) return 0;
	
	return ((m/gcd(m,n))*n); // lcm = m*n/gcd(m,n)
}
/*********************************************************************/
//Fenwick tree(BIT)
template <class Tp>
class fenwick_tree{
	std::vector<Tp> bit;
public:
	fenwick_tree(){}
	explicit fenwick_tree(std::size_t n) : bit(n + 1) {}
	Tp sum(std::size_t i) const{
		Tp s = 0;
		while(i){
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(std::size_t i, Tp x){
		while(i < bit.size()){
			bit[i] += x;
			i += i & -i;
		}
	}
	void clear(){
		bit.clear();
	}
	void assign(std::size_t n){
		bit.assign(n + 1, Tp());
	}
	void swap(fenwick_tree &f){
		bit.swap(f.bit);
	}
};
/*********************************************************************/
class UF {
	public:
	static const int ufmax=100052;
	int ufpar[ufmax],ufrank[ufmax],ufcnt[ufmax];
	UF() { init();}
	void init(){int i; rep(i,ufmax) { ufpar[i]=i; ufrank[i]=0; ufcnt[i]=1; } }
	int find(int x) {	return (ufpar[x]==x)?(x):(ufpar[x] = find(ufpar[x]));}
	int operator[](int x) {return find(x);}
	int count(int x) {return ufcnt[find(x)];}
	void unite(int x,int y) {
		x = find(x); y = find(y);
		if(x==y) return;
		if(ufrank[x]<ufrank[y]) ufpar[x]=y, ufcnt[y]+=ufcnt[x];
		else {ufpar[y]=x; ufcnt[x]+=ufcnt[y]; if(ufrank[x]==ufrank[y]) ufrank[x]++;}
	}
};
/**********************************************************************/
struct handler{
	typedef ll val_t;
	typedef ll opr_t;
	handler(){}
	static val_t def_val(){ return 0; }
	static opr_t def_lazy(){ return 0; }
	static val_t resolve(const val_t &x, const opr_t &y, ll l, ll r){
		return x + y*(r-l);
	}
	static opr_t push(const opr_t &x, const opr_t &y){
		return x + y;
	}
	static val_t merge(const val_t &x, const val_t &y){
		return x + y;
	}
};
 
template<typename Handler, int RESERVE = 536870912>
struct SegTreeDynamicLazy{
	typedef typename Handler::val_t val_t;
	typedef typename Handler::opr_t opr_t;
	Handler hdl;
	struct Node{
		static Node *pool;
		static int ptr;
		static Node* New(const Node *v){
			if(!pool) pool = (Node*)malloc(RESERVE);
			return &(pool[ptr++] = v ? *v : Node());
		}
		static void allClear(){
			ptr = 0;
		}
		Node *lch, *rch;
		val_t val;
		opr_t lazy;
		Node(Node *v=0):val(Handler::def_val()), lazy(Handler::def_lazy()){
			if(v){
				(*this) = *v;
			}else lch = rch = 0;
		}
	};
	Node* root;
	ll n;
	
	SegTreeDynamicLazy(ll size):hdl(),n(size){
		root = Node::New(0);
	}
	
	Node* push(Node *v, ll l, ll r, const int &pers=0){
		opr_t lz = v->lazy;
		v->lazy = hdl.def_lazy();
		if(r-l<=1) return v;
		if(pers || !v->lch) v->lch = Node::New(v->lch);
		if(pers || !v->rch) v->rch = Node::New(v->rch);
		v->lch->lazy = hdl.push(v->lch->lazy, lz);
		v->rch->lazy = hdl.push(v->rch->lazy, lz);
		v->lch->val = hdl.resolve(v->lch->val, lz, l, (l+r)/2);
		v->rch->val = hdl.resolve(v->rch->val, lz, (l+r)/2, r);
		return v;
	}
	Node *update(ll a,ll b,const opr_t &x, Node *v,ll l,ll r, const int &pers){
		if(r<=a||b<=l) return v;
		if(pers || !v) v = Node::New(v);
		if(a<=l&&r<=b){
			v->lazy = hdl.push(v->lazy, x);
			v->val = hdl.resolve(v->val, x, l, r);
			return v;
		}
		push(v, l, r, pers);
		v->lch = update(a, b, x, v->lch, l, (l+r)/2, pers);
		v->rch = update(a, b, x, v->rch, (l+r)/2, r, pers);
		v->val = hdl.merge(v->lch->val, v->rch->val);
		return v;
	}
	val_t query(ll a,ll b,Node *v,ll l,ll r, const int &pers){
		if(r<=a||b<=l||!v) return hdl.def_val();
		push(v, l, r, pers);
		if(a<=l&&r<=b) return v->val;
		return hdl.merge(query(a, b, v->lch, l, (l+r)/2, 1), 
						 query(a, b, v->rch, (l+r)/2, r, 1));
	}
	Node *update(ll a, ll b, opr_t x, Node *r = 0, int pers=0){return update(a, b, x, r?r:root, 0, n, pers);}
	val_t query(ll a, ll b, Node *r = 0, int pers=0){return query(a, b, r?r:root, 0, n, pers);}
//	祖先ノードの遅延評価が終わっていなければならない
	val_t get(Node *v, ll l, ll r){return push(v, l, r)->val;}
	ll lb(function<bool(val_t)> func){
		Node *v = root;
		ll l=0, r=n;
		if(!func(v->val)) return -1;
		while(l+1<r){
			push(v, l, r);
			ll med = (l+r)/2;
			if(func(v->rch->val)){
				v = v->rch;
				l = med;
			}else{
				v = v->lch;
				r = med;
			}
		}
		return l;
	}
	val_t operator[](size_t i){return query(i, i+1);}
	friend ostream& operator<<(ostream &os, SegTreeDynamicLazy<Handler> &t){
		rep(i, t.n) os << (i ? ", " : "[") << "(" << i << ")" << t.query(i, i+1);
		return os << "]";
	}
};
template<class H, int R> typename SegTreeDynamicLazy<H, R>::Node* SegTreeDynamicLazy<H, R>::Node::pool;
template<class H, int R> int SegTreeDynamicLazy<H, R>::Node::ptr;
 /*********************************************************************************************/
/* 普通のSegment Tree*/
struct Data{
	int n,p;
	bool operator<(const Data &a)const{
		return n<a.n;
	}
};
 
int SIZE,seg[MAX*2-1];
 
void add(int k,int v){
	k += SIZE-1;
	seg[k] += v;
	while(k>0){
		k = (k-1)/2;
		seg[k] += v;
	}
}
 
void init(int n){
	SIZE = 1;
	while(SIZE<n) SIZE *= 2;
	for(int i=0;i<n;i++) add(i,1);
}
 
int getSum(int a,int b,int k,int l,int r){
	if(r<=a || b<=l) return 0;
	if(a<=l && r<=b) return seg[k];
	return getSum(a,b,k*2+1,l,(l+r)/2)+getSum(a,b,k*2+2,(l+r)/2,r);
}
/*******************************************************************************/
/*bibary index tree*/
struct BIT{
    vector<ll> sums;
    BIT(int n) : sums(n,0LL) {}
 
    // v[at] += by
    void add(int at, ll by) {
        while(at < sums.size()){
            sums[at] += by;
            at |= at + 1;
        }
    }
 
    // v[0] + ... + v[at]
    ll get(int at) {
        ll res = 0;
        while(at >= 0) {
            res += sums[at];
            at = (at & (at + 1)) - 1;
        }
        return res;
    }
 
    // --- optional ---
    int size() const { return sums.size(); }
    ll operator [](int idx) const { return sums[idx]; }
};
/*******************************************************************************/
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
/****************************************************************************/ 
//逆元 O(N)
#include <cassert>
int N=100010;
#define MOD 1000000007LL
ll inv[N];
for (long long i = 1; i < N; i++) {
    inv[i] = (i == 1) ? 1 : (MOD - (MOD / i) * inv[MOD % i] % MOD);
    assert(inv[i] * i % MOD == 1);
}
//逆元 y=MOD-2 (MODは素数) O(log y)
ll powmod(ll x,ll y){
	ll a=1;
	while(y){
		if(y&1) a=a*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return a;
}
/******************/
//逆元（ユークリッドの互除法）
ll extgcd(ll a, ll b, ll& x, ll& y){
    ll d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else{
        x = 1; y = 0;
    }
    return d;
}
ll inv_mod(ll a, ll mod){
    ll x, y;
    extgcd(a, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}
/***************************************************************************/
typedef complex<double> P;
namespace std {
  bool operator <(const P &a, const P &b) {
    if(a.real() != b.real()) return a.real() < b.real();
    return a.imag() < b.imag();
  }
}
 
double dot(P a, P b) {
  return a.real()*b.real() + a.imag()*b.imag();
}
 
double cross(P a, P b) {
  return a.real()*b.imag() - a.imag()*b.real();
}
 
int ccw(P p, P a, P b) {
  a -= p;
  b -= p;
  if(cross(a,b) > EPS) return 1;
  if(cross(a,b) < -EPS) return -1;
  if(dot(a,b) < -EPS) return 2;
  if(norm(b)-norm(a) > EPS) return -2;
  return 0;
}
vector<P> convex_hull(vector<P> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2*n);
  for(int i = 0; i < n; ch[k++] = ps[i++])
    while(k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0&&ccw(ch[k-2], ch[k-1], ps[i]) !=-2) --k;
  for(int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--])
    while(k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0&&ccw(ch[k-2], ch[k-1], ps[i]) !=-2) --k;
  ch.resize(k-1);
  return ch;
}
/****************************************************************************************/
// 最小費用流(Min Cost Flow)

template <class T> class MinCostFlow{
public:
  void addEdge(int from, int dest, int capacity, T cost);
  void terminateNegativeLoop(); // This requires all negative loops to be touched.
  T minCostFlow(int flow_source, int flow_target, int flow);
 
  MinCostFlow(int vertex_num);
  MinCostFlow(){}
 
private:
  class Edge{
  public:
    int dest;
    int capacity;
    int reversed_index;
    T cost;
    
    Edge(int dest, int capacity, int reversed_index, T cost){
      this->dest = dest;
      this->capacity = capacity;
      this->reversed_index = reversed_index;
      this->cost = cost;
    }
  };
  T negative_loop_cost;
  int vertex_num;
  std::vector<std::vector<Edge>> edges;
};
 
template <class T>
inline MinCostFlow<T>::MinCostFlow(int vertex_num){
  this->vertex_num = vertex_num;
  negative_loop_cost = 0;
  edges = std::vector<std::vector<Edge>>(vertex_num);
}
 
template <class T>
inline void MinCostFlow<T>::addEdge(int from, int dest, int capacity, T cost){
  Edge e0(dest, capacity, edges[dest].size(),  cost);
  Edge e1(from,        0, edges[from].size(), -cost);
  edges[from].push_back(e0);
  edges[dest].push_back(e1);
}
 
template <class T>
inline T MinCostFlow<T>::minCostFlow(int flow_source, int flow_target, int flow){
  std::vector<std::tuple<T, bool>> costs(vertex_num);
  T total = 0;
  std::vector<int> pre_v(vertex_num);
  std::vector<int> pre_e(vertex_num);
  while(0 < flow){
    for(int vertex = 0; vertex < vertex_num; ++vertex) costs[vertex] = std::make_tuple(0, false);
    costs[flow_source] = std::make_tuple(0, true);
    for(bool updated = true; updated;){
      updated = false;
      for(int vertex = 0; vertex < vertex_num; ++vertex){
        if(!std::get<1>(costs[vertex])) continue;
        for(int edge_index = 0; edge_index < edges[vertex].size(); ++edge_index){
          Edge &e = edges[vertex][edge_index];
          if(e.capacity == 0) continue;
          if(std::get<1>(costs[e.dest]) && std::get<0>(costs[e.dest]) <= std::get<0>(costs[vertex]) + e.cost) continue;
          costs[e.dest] = std::make_tuple(std::get<0>(costs[vertex]) + e.cost, true);
          pre_v[e.dest] = vertex;
          pre_e[e.dest] = edge_index;
          updated = true;
        }
      }
    }
    if(!std::get<1>(costs[flow_target])) return -1;
    int minimum_flow = flow;
    for(int vertex = flow_target; vertex != flow_source; vertex = pre_v[vertex]){
      minimum_flow = std::min(minimum_flow, edges[pre_v[vertex]][pre_e[vertex]].capacity);
    }
    flow -= minimum_flow;
    
    total += minimum_flow * std::get<0>(costs[flow_target]);
    for(int vertex = flow_target; vertex != flow_source; vertex = pre_v[vertex]){
      Edge &e = edges[pre_v[vertex]][pre_e[vertex]];
      e.capacity -= minimum_flow;
      edges[vertex][e.reversed_index].capacity += minimum_flow;
    }
  }
  return total + negative_loop_cost;
}
 
template <class T> 
void MinCostFlow<T>::terminateNegativeLoop(){
  std::vector<int> pre_v(vertex_num);
  std::vector<int> pre_e(vertex_num);
  std::vector<int> used(vertex_num);
  std::vector<T> distances(vertex_num);
 
  while(true){
    int vertex_in_loop = -1;
    for(int i = 0; i < vertex_num; i++) used[i] = distances[i] = 0;
    for(int step = 0; step <= vertex_num; ++step){
      bool updated=false;
      for(int vertex = 0; vertex < vertex_num; ++vertex){
        for(int edge_index = 0; edge_index < edges[vertex].size(); ++edge_index){
          Edge &e = edges[vertex][edge_index];
          if(e.capacity == 0 || distances[e.dest] <= distances[vertex] + e.cost) continue;
          distances[e.dest] = distances[vertex] + e.cost;
          pre_v[e.dest] = vertex;
          pre_e[e.dest] = edge_index;
          vertex_in_loop = e.dest;
          updated = true;
        }
      }
      if(!updated) return;
    }
 
    for(; !used[vertex_in_loop]; vertex_in_loop = pre_v[vertex_in_loop]) used[vertex_in_loop] = true;
    
    T total_cost = 0;
    int minimum_capacity = edges[pre_v[vertex_in_loop]][pre_e[vertex_in_loop]].capacity;
    int cur = vertex_in_loop;
    do{
      total_cost += edges[pre_v[cur]][pre_e[cur]].cost;
      minimum_capacity = std::min(minimum_capacity, edges[pre_v[cur]][pre_e[cur]].capacity);
      cur = pre_v[cur];
    }while(cur != vertex_in_loop);
 
    negative_loop_cost += total_cost * minimum_capacity;
    
    cur = vertex_in_loop;
    do{
      Edge &e = edges[pre_v[cur]][pre_e[cur]];
      e.capacity -= minimum_capacity;
      edges[cur][e.reversed_index].capacity += minimum_capacity;
      cur = pre_v[cur];
    }while(cur != vertex_in_loop);
  }
}
/*******************************************************************************************************************/
// Mod int
// const int MOD = 1000000007;
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
//
/*******************************************************************************************************************/
//mincostflow 2nd
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
    static const int MV = 300;//頂点数
    vector<edge> E[MV];
    T dist[MV];
    int prev_v[MV], prev_e[MV], NV;
    
    MinCostFlow() { init(MV); }
    void init(int NV=MV) { this->NV=NV; for(int i=0;i<MV;i++) E[i].clear();}
    void addEdge(int x,int y, int cap, T cost) {
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
/*****************************************************************************************************/
//saikoro
#include <vector>
 
using namespace std;
 
typedef vector<int> Dice;
enum {TOP, FRONT, RIGHT, LEFT, BACK, BOTTOM};
#define rotate_swap(x, a, b, c, d) swap(x[a], x[b]); swap(x[b], x[c]); swap(x[c], x[d]);
 
void rotate_r(Dice& dice) {rotate_swap(dice, TOP, LEFT, BOTTOM, RIGHT);}
void rotate_l(Dice& dice) {rotate_swap(dice, TOP, RIGHT, BOTTOM, LEFT);}
void rotate_f(Dice& dice) {rotate_swap(dice, TOP, BACK, BOTTOM, FRONT);}
void rotate_b(Dice& dice) {rotate_swap(dice, TOP, FRONT, BOTTOM, BACK);}
void rotate_w(Dice& dice) {rotate_swap(dice, BACK, LEFT, FRONT, RIGHT);}
void rotate_c(Dice& dice) {rotate_swap(dice, BACK, RIGHT, FRONT, LEFT);}
 
vector<Dice> generate_all(Dice dice) {
 	vector<Dice> res;
  	for (int i = 0; i < 6; ++i) {
    	for (int j = 0; i < 4; ++j) res.emplace_back(dice), rotate_w(dice);
	    if (i % 2) rotate_f(dice);
	    else rotate_r(dice);
	return res;
}
/*****************************************************************************************************/