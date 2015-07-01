#include <bits/stdc++.h>
using namespace std;
#define reep(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) reep((i),0,(n))
int main(){
	int n,r;
	while(scanf("%d%d",&r,&n),n||r){
		double rr=r;
		vector<int> v1(2*r+1,0),v2(2*r+1,0);
		rep(i,n){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a=max(a,-r);
			b=min(b,r);
			reep(j,a,b+1){
				if(j-a){
					if(v1[j+r]==0){
						v1[j+r]=c;
					}
					else{
						v1[j+r]=max(v1[j+r],c);
					}
				}
				if(j-b){
					if(v2[j+r]==0){
						v2[j+r]=c;
					}
					else{
						v2[j+r]=max(v2[j+r],c);
					}
				}
			}
		}
		double ans=1e20;
		reep(i,-r,r+1){
			int mx=1e8;
			if(r+i) mx=min(mx,v1[i+r]);
			if(r-i) mx=min(mx,v2[i+r]);
			ans=min(ans,mx+rr-sqrt(rr*rr-pow(abs(i),2)));
		}
		printf("%lf\n",ans);
	}
}