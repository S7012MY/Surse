#include <fstream>
#include <algorithm>
#define LL long long
#define MULT 0x3f3f3f3f
#define DN 100005
using namespace std;

int n,v[DN],lst[DN];
LL rez;

int form(int i,int j) {
	LL ret;
	if(v[i]==v[j]) return MULT;
	ret=(1LL*j*v[j]-1LL*i*v[i])/(v[j]-v[i]);
	return min(ret,1LL*MULT);
}

int main()
{
	ifstream f("avioane.in");
	ofstream g("avioane.out");
	f>>n;
	for(int i=1; i<=n; ++i) f>>v[i];
	sort(v+1,v+n+1);
	rez=1LL*v[1]*n;
	int ls,ld;
	lst[ls=ld=0]=1;
	for(int i=2; i<=n; ++i) {
		for(;1<=ld-ls && form(lst[ld],i)<=form(lst[ld-1],lst[ld]);--ld);
		lst[++ld]=i;
		if(1<=ld-ls && form(lst[ls],lst[ls+1])==i) ++ls;
		rez=max(rez,1LL*(n-i+1)*v[i]+1LL*v[lst[ls]]*(i-lst[ls]));
	}
	g<<rez;
	return 0;
}
