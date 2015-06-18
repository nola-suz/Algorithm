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

void mainmain(){
	int h,w;
	cin>>h>>w;
	vvint vv;
	initvv(vv,h,w);
	rep(i,h){
		rep(j,w){
			char t;
			cin>>t;
			if(t=='B'){
				vv[i][j]=-1;
			}
			else{
				vv[i][j]=1;
			}
		}
	}
	int ans=0;
	for(int i=h-1;i>=0;--i){
		for(int j=w-1;j>=0;--j){
			if(vv[i][j]!=0){
				// cout<<i<<" "<<j<<endl;
				int t=vv[i][j];
				ans++;
				rep(k,i+1){
					rep(l,j+1){
						vv[k][l]-=t;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}


signed main() {
    mainmain();
}