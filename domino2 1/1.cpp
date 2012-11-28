//regula idioata
#include <fstream>
using namespace std;

ifstream f("domino2.in");
ofstream g("domino2.out");
int n;

void pr(int p) {
	g<<2*p-1<<' '<<2*p<<'\n';
	g<<2*p<<" 1\n";
	g<<1<<' '<<2*p+1<<'\n';
	g<<2*p+1<<' '<<2<<'\n';
	for(int i=1; i<p-1; ++i) {
		g<<2*i<<' '<<2*p<<'\n';
		g<<2*p<<' '<<2*i+1<<'\n';
		g<<2*i+1<<' '<<2*p+1<<'\n';
		g<<2*p+1<<' '<<2*i+2<<'\n';
	}
	g<<2*p-2<<' '<<2*p<<'\n';
	g<<2*p<<' '<<2*p<<'\n';
	g<<2*p<<' '<<2*p+1<<'\n';
	g<<2*p+1<<' '<<2*p+1<<'\n';
	if(2*p+1<n) pr(p+1);
	g<<2*p+1<<' '<<2*p-1<<'\n';
}

int main()
{
	f>>n;
	if(1==n) g<<"1 1";
	else if(2==n) g<<"1 1\n1 2\n2 2\n";
	else if(!(n&1)) g<<"-1";
	else {
		g<<"3 3\n3 1\n1 1\n1 2\n2 2\n2 3\n";
		if(n>3) pr(2);
	}
	return 0;
}
	