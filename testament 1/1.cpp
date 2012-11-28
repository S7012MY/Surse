#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define DN 100005
using namespace std;

int n,m,ext[DN],x[DN],y[DN],ind[DN],stk[DN],p;
vector<int> pti;
ofstream g("testament.out");

bool cmp(const int &a,const int &b) {
	return (x[a]<x[b] || (x[a]==x[b] && (y[a]<y[b])));
}

bool cmp2(const int &a, const int &b) {
	return((y[a]-y[p])*(x[b]-x[p])<(y[b]-y[p])*(x[a]-x[p]));
}
	
bool det(int i1, int i2, int i3) {
	return(x[i1]*y[i2]+x[i2]*y[i3]+x[i3]*y[i1]-y[i1]*x[i2]-y[i2]*x[i3]-y[i3]*x[i1])<=0;
}

void ic() {
	int sz=0;
	p=pti[0];
	sort(pti.begin()+1,pti.end(),cmp2);
	stk[++sz]=pti.front();
	for(int i=0; i<pti.size(); ++i) {
		for(;sz>=2 && det(stk[sz-1],stk[sz],pti[i]);--sz);
		stk[++sz]=pti[i];
	}
	for(int i=1; i<=sz; ++i) ext[stk[i]]=1;
	g<<sz<<' '<<n-sz<<' ';
	for(int i=0; i<pti.size(); ++i) if(ext[pti[i]]) g<<pti[i]<<' ';
	for(int i=0; i<pti.size(); ++i) if(!ext[pti[i]]) g<<pti[i]<<' ';
	g<<'\n';
}

int main()
{
	ifstream f("testament.in");
	f>>n>>m;
	int l=n*m;
	for(int i=1; i<=l; ++i) {
		f>>x[i]>>y[i];
		ind[i]=i;
	}
	sort(ind+1,ind+l+1,cmp);
	for(int i=1; i<=l; i+=n) {
		pti.clear();
		for(int j=i; j<i+n; ++j) pti.push_back(ind[j]);
		ic();
	}
	return 0;
}
