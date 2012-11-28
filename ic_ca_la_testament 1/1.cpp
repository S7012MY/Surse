//infasuratoare ca la testament
#include <iostream>
#include <iomanip>
#include <fstream>
#define DN 1200005
using namespace std;

int n,ind[DN],stk[DN],p;
double x[DN],y[DN];

bool cmp(const int &a,const int &b) {
	return (x[a]<x[b] || (x[a]==x[b] && (y[a]<y[b])));
}

bool cmp2(const int &a, const int &b) {
	return((y[a]-y[p])*(x[b]-x[p])<(y[b]-y[p])*(x[a]-x[p]));
}
	
bool det(int i1, int i2, int i3) {
	return(x[i1]*y[i2]+x[i2]*y[i3]+x[i3]*y[i1]-y[i1]*x[i2]-y[i2]*x[i3]-y[i3]*x[i1])<=0;
}

int main()
{
	ifstream f("infasuratoare.in");
	ofstream g("infasuratoare.out");
	f>>n;
	for(int i=1; i<=n; ++i) {
		f>>x[i]>>y[i];
		ind[i]=i;
	}
	
	int sz=0;
	sort(ind+1,ind+n+1,cmp);
	p=ind[1];
	sort(ind+1,ind+n+1,cmp2);
	stk[++sz]=ind[1];
	for(int i=1; i<=n; ++i) {
		for(;sz>=2 && det(stk[sz-1],stk[sz],ind[i]);--sz);
		stk[++sz]=ind[i];
	}
	g<<sz<<'\n';
	//for(int i=1; i<=sz; ++i) g<<fixed<<setprecision(6)<<x[stk[i]]<<' '<<y[stk[i]]<<'\n';
	return 0;
}
