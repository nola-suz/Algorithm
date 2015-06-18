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
const int M=5100100;
bool prime[M];
void mainmain(){
	int n;
	cin>>n;
	set<int> se1,se2;
	rep(i,n){
		int t;
		cin>>t;
		se1.insert(t);
	}
	rep(i,M){
		prime[i]=true;
	}
	rep(i,2) prime[i]=false;
	for(int i=2;i*i<=M;i++){
		if(prime[i]){
			for(int j=i*i;j<M;j+=i){
				prime[j]=false;
			}
		}
	}
	int pos=1;
	int ans=-1;
	bool f=false;
	rep(i,5000001){
		if(prime[i]){
			if(f) ans=max(ans,i-1-pos);
			int t=i;
			while(t){
				se2.insert(t%10);
				t/=10;
			}
			f=true;
			rep(j,10){
				if(se1.find(j)==se1.end()&&se2.find(j)!=se2.end()){
					f=false;
					se2.clear();
					pos=i+1;
				}
				else if(se1.find(j)!=se1.end()&&se2.find(j)==se2.end()){
					f=false;
				}
			}
		}
	}
	f=true;
	rep(j,10){
		if(se1.find(j)==se1.end()&&se2.find(j)!=se2.end()){
			f=false;
			se2.clear();
		}
		else if(se1.find(j)!=se1.end()&&se2.find(j)==se2.end()){
			f=false;
		}
	}
	if(f) ans=max(ans,5000000-pos);
	cout<<ans<<endl;
}


signed main() {
    mainmain();
}