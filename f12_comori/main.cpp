#include <cstdio>
#include <queue>
#define DK 15
#define DN 105
#define x first
#define y second
#define MULT 1000000
#define mp make_pair
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

typedef pair<int,pair<int,int> > per;
int n,m,k,spec[DK],vl[DK],dmin[DN][DN],dp[1<<DK][DK],fin,rez;

vector<per> gr[DN];

void rf() {
	for(int k=1; k<=n; ++k)
		for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j)dmin[i][j]=min(dmin[i][j],dmin[i][k]+dmin[k][j]);
}

queue<per> c;

int main() {
	freopen("comori.in","r",stdin);
	freopen("comori.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	fin=(1<<k)-1;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) dmin[i][j]=MULT;
	for(int i=1; i<=m; ++i) {
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		dmin[a][b]=min(dmin[a][b],c);
		dmin[b][a]=min(dmin[b][a],c);
	}
	for(int i=0; i<k; ++i) {
		scanf("%d %d",&spec[i],&vl[i]);
		dp[(1<<i)][i]=vl[i];
		rez=max(rez,dp[(1<<i)][i]);
		c.push(mp((1<<i),mp(0,i)));
	}
	rf();
	/*for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) deb(dmin[i][j])
		debnl
	}*/
	for(;c.size();c.pop()) {
		int state=c.front().x,tp=c.front().y.x,lst=c.front().y.y;
		//deb(state) deb(tp) deb(lst) debnl
		for(int i=0; i<k; ++i) if(!(state&(1<<i))) {
			int snou=state|(1<<i);
			if(dp[snou][i]<dp[state][lst]+vl[i]-tp-dmin[spec[lst]][spec[i]]) {
				dp[snou][i]=dp[state][lst]+vl[i]-tp-dmin[spec[lst]][spec[i]];
				rez=max(rez,dp[snou][i]);
				c.push(mp(snou,mp(tp+dmin[spec[lst]][spec[i]],i)));
			}
		}
	}
	for(int i=0; i<k; ++i) rez=max(rez,dp[fin][i]);
	printf("%d",rez);
	return 0;
}
