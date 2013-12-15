#include <algorithm>
#include <fstream>
#define x first
#define y second
#define DN 105
#define MULT 1000000
using namespace std;

typedef pair<int, int> PER;

int n,a, dp[DN][DN][DN];
PER p[DN],pf[DN];

int memo(int ls, int ld, int h) {
	if(dp[ls][ld][h]) return dp[ls][ld][h]-1;
	//caut punctele deasupra p[h].y, doar alea ma intereseaza
	int dind=0,ind[DN];
	for(int i=ls;i<=ld; ++i) if(pf[i].y>=pf[h].y) ind[++dind]=i;
	if(0==dind) {//nu am puncte deasupra
		dp[ls][ld][h]=1;
		return 0;
	}else if(1==dind) {
		dp[ls][ld][h]=2;
		return 1;
	}
	int vm=MULT;
	for(int i=1; i<dind; ++i) {
		int vc=memo(ls,ind[i],h)+memo(ind[i+1],ld,h);
		vm=min(vm,vc);
	}
	//caut arie
	int ar=MULT;
	if(pf[ind[dind]].x-pf[ind[1]].x) ar=(a/(pf[ind[dind]].x-pf[ind[1]].x));
	int hmin=MULT,cont=0,gasit;
	for(int i=1; i<=dind; ++i) if(pf[ind[i]].y>ar) {
		++cont;
		if(pf[ind[i]].y<hmin) {
			hmin=pf[ind[i]].y;
			gasit=i;
		}
	}
	if(cont!=dind) if(hmin!=MULT) vm=min(vm,1+memo(ls,ld,ind[gasit]));
	else vm=min(vm,1);
	dp[ls][ld][h]=vm+1;
	return vm;
}

int main()
{
	ifstream f("photo.in");
	ofstream g("photo.out");
	f>>n>>a;
	//pf[0].x=-1; pf[0].y=0;
	for(int i=1; i<=n; ++i) f>>pf[i].x>>pf[i].y;
	sort(pf+1,pf+n+1);
	g<<memo(1,n,0);
	return 0;
}
