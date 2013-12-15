#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 10005
int i,n,K;
int a[MAXN],pr[MAXN];

int prim(int x) {
	if(x<=1) return 0;
	for(int d=2;d*d<=x;d++)
		if(x%d==0) return 0;
	return 1;
}

int cb(int k, int mod) { // 0-min 1-max
	int st,dr,m,Min,Max;
	st=0; dr=n; Min=n; Max=-1;
	while(st<=dr) {
		m=(st+dr)/2;
		if(mod==0) {
			if(pr[m]>=k) {
				Min=min(Min,m);
				dr=m-1;
			}
			else st=m+1;
		}
		else {
			if(pr[m]<=k) {
				Max=max(Max,m);
				st=m+1;
			}
			else dr=m-1;
		}
	}
	if(mod==0) {
		if(Min==n) return -1;
		else return Min;
	}
	else return Max;
}

int main() {
	freopen("kprime.in","r",stdin);
	freopen("kprime.out","w",stdout);
	
	scanf("%d %d",&n,&K);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for(i=1;i<=n;i++) {
		pr[i]=pr[i-1];
		if(prim(a[i])) pr[i]++;
	}
	
	int rez=0;
	for(i=1;i<=n;i++) {
		if(pr[i]<K) continue;
		int j1,j2;
		j1=cb(pr[i]-K,0);
		j2=cb(pr[i]-K,1);
		rez+=j2-j1+1;
	}
	printf("%d",rez);
	return 0;
}
