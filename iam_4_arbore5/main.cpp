/*#include <vector>
#include <cstdio>
#define deb(n) fprintf(stderr,"%d",(n));
#define foreach(V) for(typeof (V).begin() it = (V).begin(); it != (V).end(); ++it)
#define DN 100005
#define DL 20
using namespace std;
int n,m,k;
int l[DN<<1],euler[DN<<1],lg[DN<<1],prim[DN],rmq[DL][DN<<2],rez;
bool vl[DN];
vector<int>g[DN];
vector<int>::iterator it;

void dfs(int sursa,int nivel,int f){
    euler[++k]=sursa;
    l[k]=nivel;
    prim[sursa]=k;
    foreach(g[sursa]) if(*it!=f) {
        dfs(*it,nivel+1,sursa);
        euler[++k]=sursa;
        l[k]=nivel;
    }
}

void df(int s, int f,bool c) {
    c^=vl[s];
    foreach(g[s]) if(*it!=f) {
        if(c==0) ++rez;
        df(*it,s,c);
    }
}

void init_rmq() {
    int i,o,j;
    for(i=2;i<=k; ++i) lg[i]=lg[i/2]+1;
    for(i=1;i<=k; ++i) rmq[0][i]=i;
    for(i=1; (1<<i)<k;++i)
        for(j=1; j<=k-(1<<i);++j) {
            o=1<<(i-1);
            rmq[i][j]=rmq[i-1][j];
            if(l[rmq[i-1][j+o]]<l[rmq[i][j]]) rmq[i][j]=rmq[i-1][j+o];
        }
}

int lca (int x,int y) {
    int dif,o,rez,sh,a=prim[x],b=prim[y];
    if(a>b) {
        int aux=a;
        a=b;
        b=aux;
    }
    dif=b-a+1;
    o=lg[dif];
    rez=rmq[o][a];
    sh=dif-(1<<o);
    if(l[rez]>l[rmq[o][a+sh]]) rez=rmq[o][a+sh];
    return euler[rez];
}

int main()
{
	int i,x,y;
	freopen("arbore5.in","r",stdin);
	freopen("arbore5.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=2; i<=n; ++i) {
	    int a,b;
	    scanf("%d %d",&a,&b);
	    g[a].push_back(b);
	    g[b].push_back(a);
	}
	dfs(1,0,0);
	init_rmq();
	for(i=1; i<=m; ++i) {
	    scanf("%d %d",&x,&y);
	    int lc=lca(x,y);
	    //fprintf(stderr,"%d ",lc);
	    vl[lc]=!vl[lc]; vl[x]=!vl[x]; vl[y]=!vl[y];
	}
	//for(int i=1; i<=n; ++i) fprintf(stderr,"%d ",vl[i]);
	df(1,0,0);
	printf("%d",rez);
	return 0;
}*/
