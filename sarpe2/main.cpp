#include <cstdio>
#define DN 1000
#define DM 100001
#define MOD 666013

const int dx[]={-1, -1, -1, 0, 1, 1, 1, 0},dy[]={-1, 0, 1, 1, 1, 0, -1, -1};
int n,m,nr[DN][DN],ma[DN][DN],v[DM],nrc,rez;

bool check(int a,int b) {
    return(0<=a && 0<=b && a<n &&b<n);
}

static inline int memo(int i,int j) {
    if(-1!=nr[i][j]) return nr[i][j];
    nr[i][j]=0;
    for(int d=0; d<8; ++d) {
        int ii=i+dx[d],jj=j+dy[d];
        if(check(ii,jj) && ma[i][j]-1==ma[ii][jj]) nr[i][j]+=memo(ii,jj);
    }
    nr[i][j]%=MOD;
    return nr[i][j];
}

int main()
{
    freopen("sarpe2.in","r",stdin);
    freopen("sarpe2.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; ++i) {
        scanf("%d",&nrc);
        v[nrc]=i+1;
    }
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
        scanf("%d",&ma[i][j]);
        nr[i][j]=-1;
        ma[i][j]=v[ma[i][j]];
        if(1==ma[i][j]) nr[i][j]=1;
    }
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) if(m==ma[i][j]) rez=(rez+memo(i,j))%MOD;
    printf("%d",rez);
    return 0;
}
