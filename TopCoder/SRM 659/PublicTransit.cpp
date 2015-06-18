#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <complex>
#include <map>
#include <set>
#include <climits>
#include <sstream>
#include <fstream>
using namespace std;
 
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second
#define mkp make_pair
 
static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
static const int INF=1<<24;
 
template <class T>
void initvv(vector<vector<T> > &v,int a,int b, const T  &t = T()){
	v.assign(a,vector<T>(b,t));
}
template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}

struct PublicTransit {
  int R;
  int C;
  int minimumLongestDistance(int _R, int _C) {
    R = _R, C = _C;
    int ans=INT_MAX;
    vvint vv;
    initvv(vv,R*C,R*C,INF);
    rep(i,R*C) vv[i][i]=0;
    rep(i,R){
        rep(j,C){
            if(j) vv[i*C+j][i*C+j-1]=vv[i*C+j-1][i*C+j]=1;
            if(j<C-1) vv[i*C+j][i*C+j+1]=vv[i*C+j+1][i*C+j]=1;
            if(i) vv[(i-1)*C+j][i*C+j]=vv[i*C+j][(i-1)*C+j]=1;
            if(i<R-1) vv[(i+1)*C+j][i*C+j]=vv[i*C+j][(i+1)*C+j]=1;
        }
    }
    rep(k,R*C){
        rep(i,R*C){
            rep(j,R*C){
                vv[i][j]=min(vv[i][j],vv[i][k]+vv[k][j]);
            }
        }
    }
    rep(i1,R) rep(j1,C) rep(i2,R) rep(j2,C){
        int tmp=0;
        rep(k1,R) rep(l1,C) rep(k2,R) rep(l2,C){
            tmp=max(tmp,min(vv[k1*C+l1][k2*C+l2],min(vv[k1*C+l1][i1*C+j1]+vv[i2*C+j2][k2*C+l2],vv[k1*C+l1][i2*C+j2]+vv[i1*C+j1][k2*C+l2])));
        }
        ans=min(ans,tmp);
    }
    return ans;
  }
};

// CUT begin
ifstream data("PublicTransit.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int R, int C, int __expected) {
    time_t startClock = clock();
    PublicTransit *instance = new PublicTransit();
    int __result = instance->minimumLongestDistance(R, C);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int R;
        from_stream(R);
        int C;
        from_stream(C);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(R, C, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1431493984;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "PublicTransit (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
