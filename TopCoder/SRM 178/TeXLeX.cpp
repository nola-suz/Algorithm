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
bool is_hex(char t){
    if('0'<=t&&t<='9') return true;
    if('a'<=t&&t<='f') return true;
    return false;
}
bool check(string in){
    // cout<<"check "<<in<<endl;
    if(is_hex(in[0])&&is_hex(in[1])){
        return true;
    }
    return false;
}
char to_hex(string t){
    // cout<<"to hex "<<t<<endl;
    char ret=0;
    if('0'<=t[0]&&t[0]<='9'){
        ret=t[0]-'0';
    }
    else{
        ret=t[0]-'a'+10;
    }
    // cout<<"ret "<<(int)ret<<endl;
    ret*=(char)16;
    // cout<<"ret "<<(int)ret<<endl;
    if('0'<=t[1]&&t[1]<='9'){
        ret+=t[1]-'0';
    }
    else{
        ret+=t[1]-'a'+10;
    }
    return ret;
}
struct TeXLeX {
  string input;
  vector<int> getTokens(string _input) {
    input = _input;
    string s=input;
    // cout<<CHAR_MAX<<endl;
    rep(i,int(s.size())-2){
        // cout<<s<<endl;
        if(s.substr(i,2)=="^^"){
            if(i+2==s.size()-1){
                s=s.substr(0,i)+s.substr(i+2);
                if(s[i]>63) s[i]-=64;
                else s[i]+=64;
                i--;
                continue;
            }
            else if(check(s.substr(i+2,2))){
                char t=to_hex(s.substr(i+2,2));
                int t1=t;
                // cout<<endl;
                // cout<<t1<<endl;
                // cout<<"t2 "<<t<<" "<<int(t)<<endl;
                s=s.substr(0,i)+s.substr(i+3);
                s[i]=t;
                i--;
                continue;
            }
            else{
                s=s.substr(0,i)+s.substr(i+2);
                if(s[i]>63) s[i]-=64;
                else s[i]+=64;
                i--;
                continue;
            }
        }
    }
    // cout<<s<<endl;
    vint ans;
    rep(i,s.size()){
        ans.PB((s[i]+256)%256);
    }
    return ans;
  }
};

// CUT begin
ifstream data("TeXLeX.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(string input, vector<int> __expected) {
    time_t startClock = clock();
    TeXLeX *instance = new TeXLeX();
    vector<int> __result = instance->getTokens(input);
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
        string input;
        from_stream(input);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(input, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1430127450;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TeXLeX (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
