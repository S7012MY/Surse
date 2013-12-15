#include <iostream>
#include <fstream>
#include <vector>
#define DN 16005
using namespace std;

typedef vector<int>::iterator it;
int n,nra[DN],vm[DN],sol,nrs;
vector<int> gr[DN];

void dfs(int s,int f) {
	nra[s]=1;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(*i!=f) {
		dfs(*i,s);
		nra[s]+=nra[*i];
		vm[s]=max(vm[s],nra[*i]);
	}
}

int main()
{
	ifstream f("sediu.in");
	ofstream g("sediu.out");
	f>>n;
	for(int i=1; i<n; ++i) {
		int a,b;
		f>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1,0);
	sol=n+1;
	for(int i=1; i<=n; ++i) {
		if(vm[i]<n-nra[i]) vm[i]=n-nra[i];
		if(vm[i]<sol) {
			sol=vm[i];
			nrs=1;
		}else if(vm[i]==sol) ++nrs;
	}
	g<<sol<<' '<<nrs<<'\n';
	for(int i=1; i<=n; ++i) if(vm[i]==sol) g<<i<<' ';
	return 0;
}