#include <cstdio>
#include <vector>
#define DN 2005
#define M1 "Suspicious bugs found!\n"
#define M2 "No suspicious bugs found!\n"
using namespace std;

typedef vector<int>::iterator it;
int n,m,tip[DN],ok;
vector<int> gr[DN];

void dfs(int s, int t) {
	tip[s]=t;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
		if(-1==tip[*i]) dfs(*i,t^1);
		else if(t==tip[*i]) ok=0;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; ++i) {
		scanf("%d %d",&n,&m);
		ok=1;
		for(int i=1; i<=n; ++i) {
			gr[i].clear();
			tip[i]=-1;
		}
		for(int i=1; i<=m; ++i) {
			int a,b;
			scanf("%d %d",&a,&b);
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		for(int i=1; i<=n; ++i) if(-1==tip[i]) dfs(i,1);
		printf("Scenario #%d:\n",i);
		if(!ok) printf(M1);
		else printf(M2);
	}
	return 0;
}
