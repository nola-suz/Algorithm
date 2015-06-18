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

vvint vv;
vvint used;
int h,w;
int dd[]={1,0,-1,0,1};
int mask[]={2,3,0,1};
bool check(int a,int b){
	if(0<=a&&a<h&&0<=b&&b<w) return true;
	return false;
}
bool foo(int a,int b,int c){
	if(used[a][b]==1) return true;
	used[a][b]=1;
	bool ret=false;
	rep(i,4){
		if(i==c) continue;
		int aa=a+dd[i];
		int bb=b+dd[i+1];
		if(check(aa,bb)){
			if(vv[aa][bb]!=vv[a][b]) continue;
			ret|=foo(aa,bb,mask[i]);
		}
	}
	return ret;
}
void mainmain(){
	cin>>w>>h;
	initvv(vv,h,w);
	initvv(used,h,w,0);
	rep(i,h) rep(j,w) cin>>vv[i][j];
	bool f=false;
	rep(i,h){
		rep(j,w){
			if(used[i][j]==0){
				if(foo(i,j,-1)){
					// cout<<i<<" "<<j<<" "<<vv[i][j]<<endl;
					f=true;
				}
			}
		}
	}
	if(f) cout<<"possible"<<endl;
	else cout<<"impossible"<<endl;
}


signed main() {
    mainmain();
}