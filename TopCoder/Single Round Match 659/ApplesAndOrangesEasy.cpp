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
template <class Tp>
class fenwick_tree{
    std::vector<Tp> bit;
public:
    fenwick_tree(){}
    explicit fenwick_tree(std::size_t n) : bit(n + 1) {}
    Tp sum(std::size_t i) const{
        Tp s = 0;
        while(i){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(std::size_t i, Tp x){
        while(i < bit.size()){
            bit[i] += x;
            i += i & -i;
        }
    }
    void clear(){
        bit.clear();
    }
    void assign(std::size_t n){
        bit.assign(n + 1, Tp());
    }
    void swap(fenwick_tree &f){
        bit.swap(f.bit);
    }
};

struct ApplesAndOrangesEasy {
  int N;
  int K;
  vector<int> info;
  int maximumApples(int _N, int _K, vector<int> _info) {
    N = _N, K = _K, info = _info;
    int ap=K/2;
    fenwick_tree<int> bi(N+1000);
    rep(i,info.size()){
        bi.add(info[i],1);
    }
    reep(i,1,N+1){
        bool f=true;
        reep(j,i-K+1,i+1){
            if(j<1) continue;
            if(j+K-1>N) continue;
            if(bi.sum(j+K-1)-bi.sum(j-1)>=ap){
                f=false;
                break;
            }
        }
        if(f&&bi.sum(i)-bi.sum(i-1)==0) bi.add(i,1);
    }
    int ans=bi.sum(N);
    return ans;
  }
};

// CUT begin
ifstream data("ApplesAndOrangesEasy.sample");

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

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
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

bool do_test(int N, int K, vector<int> info, int __expected) {
    time_t startClock = clock();
    ApplesAndOrangesEasy *instance = new ApplesAndOrangesEasy();
    int __result = instance->maximumApples(N, K, info);
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
        int N;
        from_stream(N);
        int K;
        from_stream(K);
        vector<int> info;
        from_stream(info);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(N, K, info, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1431478842;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ApplesAndOrangesEasy (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
