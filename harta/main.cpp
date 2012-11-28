#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstring>
#define DN 305
using namespace std;

typedef vector<int>::iterator it;
int n,cap[DN][DN],fl[DN][DN],pre[DN],s,d;
vector<int> gr[DN];

bool bfs() {
	memset(pre,-1,sizeof(pre));
	pre[s]=-2;
	queue<int> c;
	for(c.push(s); c.size(); c.pop()) {
		int fr=c.front();
		for(int i=s; i<=d; ++i) if(-1==pre[i] && cap[fr][i]>fl[fr][i]) {
			c.push(i);
			pre[i]=fr;
		}
	}
	return pre[d]!=-1;
}


int main()
{
    ifstream f("harta.in");
	ofstream g("harta.out");
	f>>n;
	d=2*n+2;
	for(int i=1; i<=n; ++i) {
	    int a,b;
	    f>>a>>b;
	    cap[s][i]=a;
	    cap[i+n][d]=b;
	    for(int j=1; j<=n; ++j) if(j!=i) ++cap[i][j+n];
	}

	int r=0,c;
	for(;bfs();) {
		for(int i=1; i<=d; ++i) if(fl[i][d]<cap[i][d]) {
			c=cap[i][d]-fl[i][d];
			for(int y=i;pre[y]!=-2;y=pre[y]) c=min(c,cap[pre[y]][y]-fl[pre[y]][y]);
			r+=c;
			fl[i][d]+=c;
			fl[d][i]-=c;
			for(int y=i;pre[y]!=-2;y=pre[y]) {
				fl[pre[y]][y]+=c;
				fl[y][pre[y]]-=c;
			}
		}
	}
	g<<r<<'\n';
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(fl[i][j+n]) {
	    g<<i<<' '<<j<<'\n';
	}
    return 0;
}
