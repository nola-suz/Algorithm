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

vvll vv;
int n,m;
ll dp[2010][2010];
int used[2010];
ll tmp[2010];
int sz[2010];
ll add(ll a,ll b){
	a%=MOD;
	b%=MOD;
	a+=b;
	a%=MOD;
	return a;
}
void foo2(int a,int n){
	ll ret[2010]={};
	rep(i,n){
		if(dp[a][i])rep(j,n){
			if(i+j>=2010) break;
			ret[i+j]=add(ret[i+j],dp[a][i]*tmp[j]);
		}
	}
	
	rep(i,2010){
		tmp[i]=ret[i];
	}
	return;
}
void foo(int a){
	int n=0;
	rep(i,vv[a].size()){
		if(used[vv[a][i]]==0) foo(vv[a][i]);
		n+=sz[vv[a][i]];
	}

	used[a]=1;
	// if(a==2) cout<<"aoao "<<a<<" "<<vv[a].size()<<endl;
	if(vv[a].size()==0){
		dp[a][1]=1LL;
		dp[a][0]=1LL;
		sz[a]=1;
		// puts("end");
		return;
	}

	// puts("aa");
	// return;
	rep(i,2010){
		tmp[i]=dp[vv[a][0]][i];
	}
	reep(i,1,vv[a].size()){
		foo2(vv[a][i],n+1);
	}
	rep(i,2010){
		dp[a][i]=tmp[i];
	}
	dp[a][n+1]=1LL;
	sz[a]=n+1;
	return;
}
void mainmain(){
	cin>>n>>m;
	vv=vvll(n);
	vector<pii> v(n-1);
	rep(i,n-1){
		int a,b;
		cin>>v[i].F>>v[i].S;
	}
	queue<int> q;
	q.push(0);
	while(q.size()){
		int top=q.front();
		q.pop();
		rep(i,v.size()){
			if(v[i].F==top){
				q.push(v[i].S);
				vv[top].PB(v[i].S);
				v.erase(v.begin()+i);
				i--;
			}
			else if(v[i].S==top){
				q.push(v[i].F);
				vv[top].PB(v[i].F);
				v.erase(v.begin()+i);
				i--;
			}
		}
	}
	foo(0);
	cout<<dp[0][m]<<endl;
}


signed main() {
    mainmain();
}