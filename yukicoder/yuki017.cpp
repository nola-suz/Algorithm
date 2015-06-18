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
static const int INF=1<<29;
int dp[55][55];
void mainmain(){
	int n;
	cin>>n;
	rep(i,55){
		rep(j,55){
			dp[i][j]=INF;
		}
	}
	vint v(n);
	rep(i,n) cin>>v[i];
	int m;
	cin>>m;
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		dp[a][b]=dp[b][a]=c;
	}
	rep(i,n) dp[i][i]=0;
	rep(k,n) rep(i,n) rep(j,n) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	int ans=INT_MAX;
	reep(i,1,n-1){
		reep(j,1,n-1){
			if(i==j) continue;
			ans=min(ans,v[i]+v[j]+dp[0][i]+dp[i][j]+dp[j][n-1]);
		}
	}
	// cout<<dp[0][n-1]<<endl;
	cout<<ans<<endl;
}


signed main() {
    mainmain();
}