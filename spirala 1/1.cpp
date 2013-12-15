#include <iostream>
#include <fstream>
#include <queue>
#define DN 55
#define x first
#define y second
using namespace std;

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int n,m;
int dmax[DN][DN],rc,rez;
int v[DN][DN];

inline bool check(int a, int b) {
	return (0<a && 0<b && a<=n && b<=m && 1!=v[a][b]);
}

void dfs(int a, int b, int nr, int s,int d) {
	if(0==dmax[a][b]) {
		dmax[a][b]=nr;
		//cout<<a<<' '<<b<<' '<<nr<<'\n';
		rc=max(rc,nr);
	} else return;
	if(check(a+dx[d],b+dy[d]))
		dfs(a+dx[d],b+dy[d],nr+1,s,d);
	d=(d+s+4)%4;
	if(check(a+dx[d],b+dy[d])) dfs(a+dx[d],b+dy[d],nr+1,s,d);
	dmax[a][b]=0;
}

int main()
{
	ifstream f("spirala3.in");
	ofstream g("spirala3.out");
	f>>n>>m;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) f>>v[i][j];
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if(0==v[i][j]) for(int s=0; s<2; ++s) for(int d=0; d<4; ++d) {
		rc=0;
		if(s==0) dfs(i,j,1,-1,d);
		else dfs(i,j,1,1,d);
		rez=max(rez,rc);
	}
	//cout<<rez<<' ';
	g<<rez;
	f.close(); g.close();
	return 0;
}
