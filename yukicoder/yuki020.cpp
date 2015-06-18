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
int dp[210][210][2];
int a[210][210];
int dd[]={1,0,-1,0,1};
bool check(int a,int b,int c){
	if(0<=a&&a<c&&0<=b&&b<c){
		return true;
	}
	return false;
}
void mainmain(){
	int n;
	cin>>n;
	int HP;
	cin>>HP;
	pii O;
	cin>>O.S>>O.F;
	O.F--;
	O.S--;
	rep(i,n){
		rep(j,n){
			cin>>a[i][j];
		}
	}
	rep(i,210) rep(j,210) rep(k,2) dp[i][j][k]=-1;
	priority_queue<pair<int,pair<pii,int>>> pq;
	pq.push(mkp(HP,mkp(pii(0,0),0)));
	while(pq.size()){
		auto top=pq.top();
		pq.pop();
		if(dp[top.S.F.F][top.S.F.S][top.S.S]!=-1) continue;
		// cout<<top.S.F.F<<" "<<top.S.F.S<<" "<<-top.F<<" "<<top.S.S<<endl;
		dp[top.S.F.F][top.S.F.S][top.S.S]=top.F;
		if(top.S.S==0&&top.S.F.F==O.F&&top.S.F.S==O.S){
			top.F*=2;
			top.S.S=1;
			dp[top.S.F.F][top.S.F.S][top.S.S]=top.F;
		}
		rep(i,4){
			auto tmp=top;
			tmp.S.F.F+=dd[i];
			tmp.S.F.S+=dd[i+1];
			if(check(tmp.S.F.F,tmp.S.F.S,n)){
				tmp.F-=a[tmp.S.F.F][tmp.S.F.S];
				if(tmp.F<=0) continue;
				if(dp[tmp.S.F.F][tmp.S.F.S][tmp.S.S]!=-1) continue;
				pq.push(tmp);
			}
		}
	}
	if(dp[n-1][n-1][0]>=1||dp[n-1][n-1][1]>=1){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}


signed main() {
    mainmain();
}