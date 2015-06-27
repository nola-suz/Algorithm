#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;

#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
#define PB push_back
vvint vv;
bool vis1[1<<10];
int vis2[1<<10][1<<10];
int saiki(int a,int b,int c){
	if(vis2[a][b]>=0) return vis2[a][b];
	vis2[a][b]=2;
	for(int y:vv[a]){
		if(y==c) return vis2[a][b]=1;
		if(y+b!=(y|b)) continue;
		if(saiki(y,y|b,c)==1) return vis2[a][b]=1;
	}
	return 2;
}
int main(){
	int n;
	while(cin>>n,n){
		string s;
		cin>>s;
		vv=vvint(1<<10);
		rep(i,1<<10) vis1[i]=false;
		rep(i,1<<10) rep(j,1<<10) vis2[i][j]=-1;
		int state=0;
		vvint ww(1<<10);
		bool ans=false;
		rep(i,s.size()){
			if(s[i]=='u'){
				state=0;
				continue;
			}
			int t=s[i]-'0';
			if(state&(1<<t)) ans=true;
			if(s[i+1]=='u') continue;
			state|=1<<t;
			ww[state].PB(s[i+1]-'0');
		}
		rep(i,1<<10){
			for(int x:ww[i]){
				rep(j,1<<10){
					if(i==j) continue;
					if(!(j&(1<<x))) continue;
					if(i+j!=(i|j)) continue;
					vv[i].PB(j);
				}
			}
		}
		rep(i,1<<10){
			if(ww[i].size()==0) continue;
			if(saiki(i,i,i)==1) ans=true;
		}
		puts(ans?"UNSAFE":"SAFE");
	}
}