#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#define DN 505
#define DM 6*DN*DN
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

int n,m,mf[DN][DN],nri;
char mi[DN][DN];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};//vectori de directie
int a[DM],b[DM],c[DM],ind[DM],nrm,nrConectate;
int pre[DM];

inline bool check(int a, int b) {//vad sa nu ies din matrice
    return (a>=0 && b>=0 && a<n && b<m);
}

inline bool cmp(const int &a, const int &b) {
    return c[a]<c[b];
}

void dfs(int i,int j) {//marchez toata insula nri
    mi[i][j]='0';
    mf[i][j]=nri;
    for(int d=0; d<4; ++d) {
        int ii=i+dx[d],jj=j+dy[d];
        if(check(ii,jj) && mi[ii][jj]!='0') dfs(ii,jj);
    }
}

void fam(int sx, int sy) {//formez muchiile care pleaca din sx si sy
    for(int d=0; d<4; ++d) {
        int nx=sx+dx[d],ny=sy+dy[d],dst=0;
        if(mf[nx][ny] || !check(nx,ny)) continue;
        for(;check(nx,ny) && !mf[nx][ny];nx+=dx[d],ny+=dy[d],++dst);
        if(!check(nx,ny) || mf[nx][ny]==mf[sx][sy]) continue;
        a[++nrm]=mf[sx][sy]; b[nrm]=mf[nx][ny]; c[nrm]=dst; ind[nrm]=nrm;
        //deb(a[nrm]) deb(b[nrm]) deb(c[nrm]) debnl
    }
}

inline int find(int x) {
    if(pre[x]==x) return x;
    pre[x]=find(pre[x]);
    return pre[x];
}

void unite(int x, int y) {
    if(rand()&1) pre[x]=y;
    else pre[y]=x;
}

int main()
{
    srand(time(NULL));
    freopen("insule.in","r",stdin);
    freopen("insule.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; ++i) scanf("%s",mi[i]);
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
        if(mi[i][j]!='0') {
            ++nri;
            dfs(i,j);
        }
    for(int i=1; i<=nri; ++i) pre[i]=i;
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) if(mf[i][j])
        fam(i,j);
    sort(ind+1,ind+nrm+1,cmp);//sortez muchiile dupa cost
    //kruskal
    int cst=0;
    for(int i=1; i<=nrm; ++i) if(find(a[ind[i]])!=find(b[ind[i]])) {
		++nrConectate;
        cst+=c[ind[i]];
        unite(find(a[ind[i]]),find(b[ind[i]]));
    }
	//while(1);
    if(nrConectate==nri-1) printf("%d",cst);
    else printf("-1");
    return 0;
}
