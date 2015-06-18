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
int dp1[110][110];
int dp2[110][110];
vint v;
int n;
int foo(int a,int b){
	if(dp1[a][b]!=-1) return dp1[a][b];
	int ret=0;
	if(v[a]>=v[b]) return dp1[a][b]=0;
	rep(i,a){
		if(abs(v[a]-v[b])>abs(v[i]-v[a])&&v[a]>v[i]){
			ret=max(ret,foo(i,a));
		}
	}
	return dp1[a][b]=ret+1;
}
int foo1(int a,int b){
	if(dp2[a][b]!=-1) return dp2[a][b];
	int ret=0;
	if(v[a]<=v[b]) return dp2[a][b]=0;
	reep(i,b+1,n){
		if(abs(v[a]-v[b])>abs(v[b]-v[i])&&v[b]>v[i]){
			ret=max(ret,foo1(b,i));
		}
	}
	return dp2[a][b]=ret+1;
}
void mainmain(){
	int T;
	cin>>T;
	rep(o,T){
		cin>>n;
		v=vint(n);
		rep(i,n) cin>>v[i];
		int ans=0;
		rep(i,110) rep(j,110) dp1[i][j]=-1;
		rep(i,110) rep(j,110) dp2[i][j]=-1;
		rep(i,n){
			reep(j,0,i){
				foo(j,i);
			}
		}
		rep(i,n){
			reep(j,i+1,n){
				foo1(i,j);
			}
		}
		rep(i,n){
			int t1=0;
			int t2=0;
			// dump(i);
			rep(j,i){
				t1=max(t1,foo(j,i));
				// cout<<j<<" "<<dp1[j][i]<<endl;
			}
			reep(j,i+1,n){
				t2=max(t2,foo1(i,j));
				// cout<<j<<" "<<dp2[i][j]<<endl;
			}
			ans=max(ans,t1+t2+1);
		}
		cout<<ans<<endl;
	}
}


signed main() {
    mainmain();
}