#include <fstream>
#include <algorithm>
#define DN 605
using namespace std;

int n,l[DN],c[DN],m[DN],cnt,x,y;

int main()
{
	ifstream f("grozavesti.in");
	ofstream g("grozavesti.out");
	f>>n;
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
		if(i==j) f>>m[i];
		else f>>x;
	for(int i=1; i<n; ++i) {
		y=-1; x=m[i];
		for(int j=i+1; j<=n; ++j) if(m[j]<x) {
			x=m[j];
			y=j;
		}
		if(0<y) {
			l[++cnt]=y; c[cnt]=i;
			swap(m[i],m[y]);
		}
	}
	g<<(cnt<<1)<<'\n';
	for(int i=1; i<=cnt; ++i) {
		g<<"L "<<c[i]<<' '<<l[i]<<'\n';
		g<<"C "<<c[i]<<' '<<l[i]<<'\n';
	}
	return 0;
}