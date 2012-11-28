#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <cstring>
#define x first
#define y second
#define DN 605
#define MULT 99999999
using namespace std;

typedef pair<int,int> per;
typedef vector<int>::iterator it;

bitset<DN> viz;
vector<int> gr[DN];
queue<int> c;
int n,m,k,s,dest,cnt[DN],cst[DN][DN],cap[DN][DN],fl[DN][DN],pre[DN];
per rez,rsp;

bool flx(int dest) {
	viz&=0;//memset(pre,-1,sizeof(pre)); memset(cnt,MULT,sizeof(cnt));
	//for(int i=1; i<=n; ++i) cout<<cnt[i]<<' ';
	for(int i=0; i<=n+m+1; ++i) {
		pre[i]=-1; cnt[i]=MULT;
	}
	cnt[0]=0; viz[0]=1;
	for(c.push(0);c.size();c.pop()) {
		int fr=c.front();
		for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(0<cap[fr][*i] && cnt[fr]+cst[fr][*i]<cnt[*i]) {
			cnt[*i]=cnt[fr]+cst[fr][*i];
			pre[*i]=fr;
			if(0==viz[*i]) {
				viz[*i]=1;
				c.push(*i);
			}
		}
		viz[fr]=0;
	}
	if(cnt[n+m+1]==MULT) return 0;
	rez.y+=cnt[n+m+1];
	++rez.x;
	for(int z=n+m+1;-1!=pre[z]; z=pre[z]) {
		--cap[pre[z]][z]; ++cap[z][pre[z]];
	}
	if(dest>=n && rez.y<rsp.y) rsp=rez;
	//cout<<rez.y<<' ';
	if(rez.x==dest) return 0;
	return 1;
}

int main()
{
	ifstream f("terenuri3d.in");
	ofstream g("terenuri3d.out");
	f>>n>>m>>k;
	for(int i=1; i<=k; ++i) {
		int a,b,c;
		f>>a>>b>>c;
		b+=n;
		gr[a].push_back(b);
		gr[b].push_back(a);
		cap[a][b]=1;
		cst[a][b]=-c; cst[b][a]=c;
	}
	for(int i=1; i<=n; ++i) {
		gr[0].push_back(i); gr[i].push_back(0);
		cap[0][i]=1;
	}
	for(int i=1; i<=m; ++i) {
		gr[n+i].push_back(n+m+1);
		gr[n+m+1].push_back(n+i);
		cap[n+i][n+m+1]=1;
	}
	for(;flx(n+2););
	
	memset(cap,0,sizeof(cap));
	for(int i=1; i<=n; ++i) cap[0][i]=1;
	for(int i=1; i<=m; ++i) cap[n+i][n+m+1]=1;
	for(int i=1; i<=n; ++i) for(it j=gr[i].begin(); j!=gr[i].end(); ++j) if(*j>0) cap[i][*j]=1;
	rez=make_pair(0,0);
	
	for(;flx(rsp.x););
	g<<(-rez.y)<<'\n'<<rez.x<<'\n';
	for(int i=1; i<=n; ++i) for(it j=gr[i].begin(); j!=gr[i].end(); ++j) if(0==cap[i][*j] && 0<(*j))
		g<<i<<' '<<((*j)-n)<<'\n';
	return 0;
}
