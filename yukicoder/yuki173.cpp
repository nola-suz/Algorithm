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

void mainmain(){
	int n;
	cin>>n;
	double ap,bp;
	cin>>ap>>bp;
	// cout<<ap<<" "<<bp<<endl;
	ap*=1000;
	bp*=1000;
	vint a(n),b(n);
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n){
		cin>>b[i];
	}
	sort(ALL(a));
	sort(ALL(b));
	vint atmp=a,btmp=b;
	const int m=1e6;
	vector<double> res(m);
	rep(o,m){
		// cout<<o<<endl;
		a=atmp;
		b=btmp;
		double t1=0;
		double t2=0;
		rep(i,n){
			// cout<<i<<" "<<a.size()<<" "<<b.size()<<endl;
			int ar=rand()%1000;
			int br=rand()%1000;
			int apos=-1;
			int bpos=-1;
			if(i==n-1){
				if(a[0]>b[0]){
					t1+=a[0]+b[0];
				}
				else{
					t2+=a[0]+b[0];
				}
				break;
			}
			if(ar+1<=ap){
				apos=0;
			}
			else{
				apos=rand()%(a.size()-1);
				apos++;
			}
			if(br+1<=bp){
				bpos=0;
			}
			else{
				bpos=rand()%(b.size()-1);
				bpos++;
			}
			if(a[apos]>b[bpos]){
				t1+=a[apos]+b[bpos];
			}
			else{
				t2+=a[apos]+b[bpos];
			}
			// cout<<a[apos]<<" "<<b[bpos]<<endl;
			a.erase(a.begin()+apos);
			b.erase(b.begin()+bpos);
		}
		if(t1>t2) res[o]=1;
	}
	double ans=0.0;
	rep(i,m){
		// cout<<res[i]<<endl;
		ans+=res[i];
	}
	// cout<<ans<<endl;
	ans/=(double)m;
	printf("%.6lf\n",ans);
}


signed main() {
    mainmain();
}