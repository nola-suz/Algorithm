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
bool prime[200100];
int foo(int x){
	while(x>9){
		int t=0;
		while(x){
			t+=x%10;
			x/=10;
		}
		x=t;
	}
	return x;
}
void mainmain(){
	int K,N;
	cin>>K>>N;
	rep(i,200100) prime[i]=true;
	prime[0]=prime[1]=false;
	for(int i=2;i*i<=200100;i++){
		if(prime[i]){
			for(int j=i*i;j<200100;j+=i){
				prime[j]=false;
			}
		}
	}
	vint v;
	reep(i,K,N+1){
		if(prime[i]){
			v.PB(i);
		}
	}
	set<int> se;
	int pos=0;
	int ans1=0;
	int ans2=0;
	rep(i,v.size()){
		int t=foo(v[i]);
		// cout<<v[i]<<" "<<t<<endl;
		if(se.find(t)!=se.end()){
			while(foo(v[pos])!=t){
				se.erase(foo(v[pos]));
				pos++;
			}
			pos++;
		}
		else{
			se.insert(t);
		}
		// cout<<se.size()<<endl;
		if(ans1<=se.size()){
			ans1=se.size();
			ans2=pos;
		}
	}
	cout<<v[ans2]<<endl;
}


signed main() {
    mainmain();
}