#include <fstream>
#include <cstring>
#define DQ 100005
using namespace std;

int n,m,c[DQ][11][11],nm=11,inc,sfc,nrm=DQ,e[DQ];

bool cf(int p) {
   for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(c[p][i][j]!=nm) return 0;
   return 1;
}

int main()
{
	ifstream f("joc15.in");
	ofstream g("joc15.out");
	f>>n>>m;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
		f>>c[1][i][j];
		nm=min(nm,c[1][i][j]);
	}
	inc=sfc=1;
	for(;inc<=sfc;) {
		if(cf(inc)) {
			nrm=min(nrm,e[inc]);
			continue;
		}
		int pi=i/(M-1)+1;
		if(i%(M-1)==0) --pi;
		
	}
	return 0;
}