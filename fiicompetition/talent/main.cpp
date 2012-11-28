#include <iostream>
#include <fstream>
#define LL long long
#define DN 10005
#define VMAX 1000000000
using namespace std;

//form a * ( f - s + 1 ) / ( a + b ) + min ( ( f - s + 1 ) % ( a + b ) , a )

struct talent {
	int s,f,a,b;
} v[DN];

int n;

bool check(int lim) {
	LL sum=0;
	for(int i=1; i<=n; ++i) {
		int s=v[i].s,f=min(v[i].f,lim),a=v[i].a,b=v[i].b;
		sum+=a*1LL * ( f - s + 1 ) / ( a + b ) + min ( ( f - s + 1 ) % ( a + b ) , a );
	}
	//cout<<sum
	if(sum&1LL) return 1;
	return 0;
}

int main() {
	ifstream f("talent.in");
	ofstream g("talent.out");
	f>>n;
	for(int i=1; i<=n; ++i) f>>v[i].s>>v[i].f>>v[i].a>>v[i].b;
	int ls=1,ld=VMAX,m,sol,ok=0;
	for(;ls<ld;) {
		m=ls+(ld-ls)/2;
		cout<<ls<<' '<<m<<' '<<ld<<'\n';
		if(check(m)) {
			sol=m;
			ld=m-1;
		}
		else ls=m+1;
	}
	for(;check(sol);--sol);
	g<<sol+1;
	return 0;
}
