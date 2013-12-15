#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define DN 200001
#define DM 250001
#define INF (1<<29)

int m,n,pr[DN],k;
long long dist[DM];
bool viz[DN];
set<int> s[DN];

class cmp {
public:
	inline bool operator() ( const int& x, const int& y ) { return dist[x]>dist[y]; }
};

priority_queue < int, vector< int >, cmp > heap;

struct nod {
	int x,cost;
	nod *urm;
}*v[DN];



void adaugare (int x, int y,int cost) {
	nod *p;
	p=new nod;
	p->urm=v[x];
	p->x=y;
	p->cost=cost;
	v[x]=p;

}

void initializare() {
	int i;
	for(i=1; i<=n; i++) {
		dist[i]=INF;
		pr[i]=-1;
	}
	dist[1]=0;
	pr[1]=1;
}

void dijkstra() {
	int mn,n,cost;
	nod *p;
	for( heap.push(1);!heap.empty();) {
		mn=heap.top();
		heap.pop();
		viz[mn]=false;
		for(p=v[mn];p!=NULL; p=p->urm) {
			n=p->x; cost=p->cost;
			int d=dist[mn];
			for(;s[mn].find(d)!=s[mn].end();) ++cost,++d;
			if(dist[n]>dist[mn]+cost) {
				dist[n]=dist[mn]+cost;
				if(!viz[n]) {
					heap.push(n);
					viz[n]=true;
				}
			}
		}
	}
}

int main()
{
	int i,x,y,c;
	scanf("%d %d",&n,&m);
	for(i=1; i<=m; i++) {
		scanf("%d %d %d",&x,&y,&c);
		adaugare(x,y,c);
		adaugare(y,x,c);
	}
	for(int i=1; i<=n; ++i) {
	    int nr;
	    scanf("%d",&nr);
	    for(int j=1; j<=nr; ++j) {
	        int a;
	        scanf("%d",&a);
	        s[i].insert(a);
	    }
	}
	initializare();
	dijkstra();
    if(dist[n]==INF) printf("-1");
    else printf("%I64d",dist[n]);
	return 0;
}
