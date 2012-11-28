#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define DN 50001
#define DM 250001
#define INF 999999

int m,n,pr[DN],dist[DM],k;
bool viz[DN];

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
	for( heap.push(1);!heap.empty();heap.pop()) {
		mn=heap.top();
		viz[mn]=false;
		for(p=v[mn];p!=NULL; p=p->urm) {
			n=p->x; cost=p->cost;
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
	freopen("dijkstra.in","r",stdin);
	freopen("dijkstra.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1; i<=m; i++) {
		scanf("%d %d %d",&x,&y,&c);
		adaugare(x,y,c);
	}
	initializare();
	dijkstra();
	for(i=2; i<=n; i++) {
		if(dist[i]==INF) dist[i]=0;
		printf("%d ",dist[i]);
	}
	return 0;
}
