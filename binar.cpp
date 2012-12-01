#include <iostream>
#include <fstream>
using namespace std;

int n,m,ind[2005],v[2005];
string mt[2005];

void so(int l,int s,int d) {
	int a=s-1,b=d+1;
	for(int i=s; i<=d; ++i)
		if(mt[l][ind[i]]=='0') v[++a]=ind[i];
		else v[--b]=ind[i];
	for(int i=l; i<=a; ++i) ind[i]=v[i];
	for(int i=d; i>a; --i) ind[i]=v[i];
	if(l==n) return;
	if(l!=a) so(l+1,s,a);
	/*if(d>b)*/ so(l+1,a+1,d);
}

int main() {
	ifstream f("binar.in");
	ofstream g("binar.out");
	f>>n>>m;
	f.get();
	for(int i=0; i<n; ++i) getline(f,mt[i]);
	for(int i=0; i<m; ++i) ind[i]=i;
	so(0,0,m-1);
	for(int i=0; i<m; ++i) cout<<ind[i]+1<<'\n';
	return 0;
}