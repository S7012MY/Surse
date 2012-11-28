#include <fstream>
#include <vector>
#include <bitset>
#define DN 50005
using namespace std;

typedef vector<int>::iterator it;
int gls,gld,n,m,c,ai[4*DN],cm[4*DN][80],fp[DN],lp[DN],sz,cc=1,rq[DN];
vector<int> gr[DN];
bitset<DN> viz;

void dfs(int s) {
	viz[s]=1;
	fp[s]=++sz;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==viz[*i]) dfs(*i);
	lp[s]=sz;
}

void update(int vn, int ls, int ld) {
	if(ls==ld && ls>=gls && ls<=gld) {
		ai[vn]=cc;
		for(int i=0; i<=c; ++i) cm[vn][i]=0;
		cm[vn][cc]=1;
		return;
	}
	int fs=vn<<1,m=(ls+ld)>>1;
	update(fs,ls,m);
	update(fs+1,m+1,ld);
	for(int i=0; i<=c; ++i) cm[vn][i]=cm[fs][i]+cm[fs+1][i];
	++cm[vn][ai[vn]];
}

void query(int vn, int ls, int ld) {
	if(gls<=ls && ld<=gld) {
		for(int i=0; i<=c; ++i) rq[i]+=cm[vn][i];
		return;
	}
	int fs=vn<<1,m=(ls+ld)>>1;
	query(fs,ls,m);
	query(fs+1,m+1,ld);
}

int main()
{
	ifstream f("color4.in");
	ofstream g("color4.out");
	f>>n>>m>>c;
	for(int i=1; i<n; ++i) {
		int a,b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	dfs(1);
	gls=1; gld=sz;
	update(1,1,n);
	for(int i=1; i<=m; ++i) {
		int tip,x;
		f>>tip;
		if(0==tip) {
			f>>x>>cc;
			gls=fp[x]; gld=lp[x];
			update(1,1,n);
		}else {
			f>>x;
			gls=fp[x]; gld=lp[x];
			query(1,1,n);
			int cb,cnt=0;
			for(int i=0; i<=c; ++i) if(rq[i]>cnt) {
				cnt=rq[i];
				cb=i;
			}
			g<<cb<<' '<<cnt<<'\n';
		}
	}
	return 0;
}
