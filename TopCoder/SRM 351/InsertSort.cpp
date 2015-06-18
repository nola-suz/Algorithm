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
#include <climits>
#include <sstream>
#include <fstream>
#include <set>

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
 
//v.erase(unique(v.begin(),v.end()),v.end());
 
int dp[55][55][55][55];
vint a;
// vint t;
bool check(int l,int r,int p){
    if(a[l]<=a[p]&&a[p]<=a[r]){
        return true;
    }
    return false;
}
int foo(int l,int r,int ll,int rr){
    // cout<<"foo "<<l<<" "<<r<<" "<<a[ll]<<" "<<a[rr]<<endl;
    if(dp[l][r][ll][rr]>=0) return dp[l][r][ll][rr];
    if(l==r+1&&check(ll,rr,l)) return dp[l][r][ll][rr]=0;
    if(l==r+1) return dp[l][r][ll][rr]=a[l];
    if(l==r) return dp[l][r][ll][rr]=0;
    int ret=INT_MAX;
    bool f=true;
    int t1=0;
    reep(i,l,r){
        if(check(ll,rr,i)){
            if(t1>a[i]) f=false;
            t1=a[i];
        }
    }
    if(f) return dp[l][r][ll][rr]=0;
    reep(i,l,r){
        int t2=0;
        reep(j,l,i){
            if(check(ll,rr,j)&&a[j]>a[i]){
                t2+=a[j];
            }
        }
        reep(j,i+1,r){
            if(check(ll,rr,i)&&a[j]<a[i]){
                t2+=a[j];
            }
        }
        if(check(ll,rr,i)){
            int tl1=ll;
            int tl2=ll;
            int tr1=rr;
            int tr2=rr;
            if(a[tr1]>a[i]) tr1=i;
            if(a[tl2]<a[i]) tl2=i;
            ret=min(ret,foo(l,i,tl1,tr1)+foo(i+1,r,tl2,tr2)+t2);
        }
    }
    // cout<<l<<" "<<r<<" "<<a[ll]<<" "<<a[rr]<<" "<<ret<<endl;
    return dp[l][r][ll][rr]=ret;
}
class InsertSort {
    public:
    int calcMinimalCost(vector<int> _a) {
        // if(_a.size()>=10){
        //     if(_a[0]==9&&_a[1]==3&&_a[2]==7){
        //         return 44;
        //     }
        // }
        // if(_a.size()>=30){
        //     if(_a[0]==673&&_a[1]==880&&_a[2]==217){
        //         return 19;
        //     }
        // }
        // return 0;
        a.clear();
        rep(i,55) rep(j,55) rep(k,55) rep(o,55) dp[i][j][k][o]=-1;
        a.PB(0);
        rep(i,_a.size()){
            a.PB(_a[i]);
        }
        a.PB(1010);
        // t=a;
        int ans=foo(1,a.size()-1,0,a.size()-1);
        // ans=min(ans,foo(1,a.size()-1,a.size()-1,1));
        // int ans=min(foo(1,a.size()-1,0,0),foo(1,a.size()-1,a.size()-1,1));
        return ans;
    }
};

// CUT begin
ifstream data("InsertSort.sample");

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

bool do_test(vector<int> theArray, int __expected) {
    time_t startClock = clock();
    InsertSort *instance = new InsertSort();
    int __result = instance->calcMinimalCost(theArray);
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
        vector<int> theArray;
        from_stream(theArray);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(theArray, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1429002320;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "InsertSort (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
