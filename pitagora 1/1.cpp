#include <fstream>
using namespace std;

int k,d=1,a[100],m[100],t,b;

bool desc(int val, int nt) {
	int ls=1,mj,ld=44722;
	if(val-nt<=3) return 0;
	for(;0!=ld-ls-1;) {
		mj=(ls+ld)>>1;
		if(val-mj*mj==nt-1) {
			a[++t]=mj; m[t]=1;
			a[++t]=1; m[t]=nt-1;
			return 1;
		}
		if(val-mj*mj<nt-1) ld=mj;
		else ls=mj;
	}
	if(desc(val-ls*ls,nt-1)) {
		a[++t]=ls;
		m[t]=1;
		return 1;
	}
	return 0;
}

int main()
{
	ifstream f("pitagora.in");
	ofstream g("pitagora.out");
	int k;
	f>>k;
	for(;;) {
		if(desc(d*d,k)) break;
		++d;
	}
	g<<d<<'\n'<<t<<'\n';
	for(int i=1; i<=t; ++i) g<<m[i]<<' '<<a[i]<<'\n';
	return 0;
}