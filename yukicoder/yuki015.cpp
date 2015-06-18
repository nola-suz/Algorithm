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
vector<pii> vl;
vector<pii> vr;
vvint ans;
int l,r;
void foo(int a,int b){
	// cout<<a<<" "<<b<<endl;
	ans.PB(vint(0));
	rep(i,l){
		if((1<<i)&a){
			ans.back().PB(i+1);
		}
	}
	rep(i,r){
		if((1<<i)&b){
			ans.back().PB(i+1+l);
		}
	}
}
void mainmain(){
	int n;
	int m;
	cin>>n>>m;
	vint v(n);
	rep(i,n) cin>>v[i];
	l=n/2;
	r=n-l;
	rep(i,1<<l){
		int t=0;
		rep(j,l){
			if((1<<j)&i){
				t+=v[j];
			}
		}
		vl.PB(pii(t,i));
	}
	rep(i,1<<r){
		int t=0;
		rep(j,r){
			if((1<<j)&i){
				t+=v[j+l];
			}
		}
		vr.PB(pii(t,i));
	}
	sort(ALL(vl));
	sort(ALL(vr));
	rep(i,vl.size()){
		// cout<<vl[i].F<<" "<<vl[i].S<<endl;
		int t=m-vl[i].F;
		auto it=lower_bound(ALL(vr),pii(t,-INF));
		while(1){
			if(it==vr.end()) break;
			pii tt=*it;
			if(tt.F==t){
				foo(vl[i].S,tt.S);
				it++;
			}
			else{
				break;
			}
		}
	}
	sort(ALL(ans));
	// cout<<"aa "<<ans.size()<<endl;
	rep(i,ans.size()){
		rep(j,ans[i].size()){
			if(j) cout<<" ";
			cout<<ans[i][j];
		}
		cout<<endl;
	}
}


signed main() {
    mainmain();
}