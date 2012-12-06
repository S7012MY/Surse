#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>
#define DN 205
using namespace std;

typedef vector<int>::iterator it;

int n,m,mt[DN][DN],l[DN*DN],r[DN*DN];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
vector<int> gr[DN*DN];
bitset<DN> viz;

bool check(int x,int y) {
	return (x>0 && y>0 && x<=n && y<=m && mt[x][y]);
}

int fa(int i, int j) {
	return (n-1)*i+j;
}

bool cupl(int s) {
	if(viz[s]) return 0;
	viz[s]=1;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==r[*i] || cupl(r[*i])) {
		r[*i]=s; l[s]=*i;
		return 1;
	}
	return 0;
}

int main() {
	freopen("asd.in","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) scanf("%d",&mt[i][j]);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(mt[i][j]==0) gr[i].push_back(j);
	for(int ok=1;ok;) {
		ok=0; viz&=0;
		for(int i=1; i<=n; ++i) if(0==l[i]) ok|=cupl(i);
	}
	int cnt=0;
	for(int i=1; i<=n; ++i) cnt+=(l[i]>0);
	cout<<n+m-cnt<<'\n';
	return 0;
}