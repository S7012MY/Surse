#include <iostream>
#include <fstream>
#define DN 100005
using namespace std;

int n,k,s[DN],nr,rez;

int isp(int nr) {
	if(nr==1) return 0;
	for(int i=2; i*i<=nr; ++i) if(0==nr%i) return 0;
	return 1;
}

int cb(int cc,int ld) {
	int ls=1;
	for(;ls<ld;) {
		int m=(ls+ld)>>1;
		if(s[m]<cc) ls=m+1;
		else ld=m;
	}
	return ls;
}

int main()
{
	ifstream f("kprime.in");
	ofstream g("kprime.out");
	f>>n>>k;
	for(int i=1; i<=n; ++i) {
		s[i]=s[i-1];
		f>>nr;
		if(isp(nr)) ++s[i];
		int cc=s[i]-k;
		if(cc<0) continue;
		int f=cb(cc,i);
		int l=cb(cc+2,i);
		if(s[l]!=cc) --cc;
		if(l<=0 || f<=0) continue;
		cout<<i<<' '<<f<<' '<<l<<' '<<cc<<'\n';
		cout<<s[i]<<' '<<s[f]<<' '<<s[l]<<"\n\n";
		rez+=l-f+1;
	}
	g<<rez;
}
