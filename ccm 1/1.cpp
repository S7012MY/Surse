#include <fstream>
#define M 9901
using namespace std;

int l,r,m,a,b,ccm[20][1<<17]={1},z[20][20];

int main()
{
	ifstream f("ccm.in");
	ofstream g("ccm.out");
	f>>l>>r>>m;
	for(int i=0; i<m; ++i) {
		f>>a>>b;
		z[a][b]=1;
	}
	int lim=(1<<r)-1;
	for(int i=1; i<=l; ++i) for(int msk=0; msk<=lim; ++msk) {
		ccm[i][msk]=ccm[i-1][msk];
		for(int j=1; j<=r; ++j) if((1<<(j-1))&msk && z[i][j])
			ccm[i][msk]=(ccm[i][msk]+ccm[i-1][msk^(1<<(j-1))])%M;
	}
	a=b=0;
	for(int msk=lim; 0<msk; --msk) if(ccm[l][msk]) {
		for(int j=0; j<r; ++j) if(msk&(1<<j)) ++b;
		break;
	}
	for(int msk=lim; 0<msk; --msk) {
		int nrb=0;
		for(int j=0; j<r; ++j) if(msk&(1<<j)) ++nrb;
		if(nrb==b) a=(a+ccm[l][msk])%M;
	}
	g<<b<<' '<<a;
	return 0;
}