#include <cstdio>
#include <vector>
#include <bitset>
#define DN 205
using namespace std;

typedef vector<int>::iterator it;

int n,m,mt[DN][DN],l[DN*DN],r[DN*DN];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
vector<int> gr[DN*DN];

int main() {
	freopen("asd.in","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) scanf("%d",&n,&m);
	
	return 0;
}