#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <bitset>
#define deb(n) fprintf(stderr,"%d",(n));
#define DN 711
#define MULT 0x3f3f3f3f
using namespace std;


vector<pair <int, int> > graf[DN];
vector<pair <int, int> >::iterator it;
bitset<DN> viz;
int n,m,e,d[DN],mat[DN][DN],c[DN][DN],flux[DN][DN],ind[DN][DN],f[DN],sursa,dest=700;

class cmp
{public:
		bool operator () (const int &x, const int &y) { return d[x]>d[y];}
};

priority_queue<int, vector<int>,cmp>heap;

bool b() {
    int x;
    viz&=0;
    memset(d,MULT,sizeof(d));
    d[dest]=MULT,d[sursa]=0;
    f[sursa]=f[dest]=0;
    viz.set(sursa);
    for(heap.push(sursa);!heap.empty();) {
        x=heap.top(); heap.pop();
        viz.flip(x);
        for(it=graf[x].begin();it!=graf[x].end();++it)
            if(c[x][it->first]>flux[x][it->first]&&d[it->first]>d[x]+it->second) {
                f[it->first]=x;
                d[it->first]=d[x]+it->second;
                if(!viz.test(it->first)) {
                    heap.push(it->first);
                    viz.set(it->first);
                }
            }
    }
    return d[dest]!=MULT;
}

int main()
{
	int i,x,y,cost;
	//freopen("cmcm.in","r",stdin);
	//freopen("cmcm.out","w",stdout);
	scanf("%d",&n);
	for(i=1; i<=n; ++i) for(int j=1; j<=n; ++j) scanf("%d",&mat[i][j]);
	for(i=1; i<=n; ++i) {
	    for(int j=1; j<=n; ++j) {
	        int cst=0;
	        int x=i,y=j+n+1;
	        for(int k=1; k<=n; ++k) if(k!=j) cst+=mat[k][i];
            ind[x][y]=i;
            c[sursa][x]=c[y][dest]=c[x][y]=1;
            graf[x].push_back(make_pair(y,cst));
            graf[y].push_back(make_pair(x,-cst));
            if(!viz.test(x)) {
                graf[sursa].push_back(make_pair(x,0));//adaugam muchie de la nodul sursa la x de cost 0
                graf[x].push_back(make_pair(sursa,0));
                viz.set(x);//am vizitat nodul x
            }
            if(!viz.test(y)) {
                graf[dest].push_back(make_pair(y,0)); // adaugam muchie de la y la dest de cost 0;
                graf[y].push_back(make_pair(dest,0));
                viz.set(y);
            }
        }
	}
	//x=0; y=0; e=n+m+2;
	for(x=0, y=0, e=n+n+2;b();++x,y+=d[dest])
	    for(i=dest;i;i=f[i]) ++flux[f[i]][i], --flux[i][f[i]];
    printf("%d",y);
    /*for(y=1;y<=n&&x;++y)
        for(it=graf[y].begin();it!=graf[y].end();++it) if(flux[y][it->first]>0) {
            --x;
            printf("%d ",ind[y][it->first]);
        }*/
    return 0;
}
