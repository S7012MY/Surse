#include <cstdio>
#include <algorithm>
#define DN 1005
#define DM 10005
#define MULT (1<<30)
#define x first
#define y second
#define LL long long
#define deb(n) fprintf(stderr,"%lld ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

typedef pair<int,pair<int,int> > per;

int n,m;
per muc[DM];
int dmin[DN][DN];

int main()
{
    freopen("viteza2.in","r",stdin);
    freopen("viteza2.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        muc[i].x=c; muc[i].y.x=a; muc[i].y.y=b;
        muc[i+m].x=c; muc[i+m].y.x=b; muc[i+m].y.y=a;
    }
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) dmin[i][j]=MULT;

    sort(muc+1,muc+2*m+1);
    for(int i=1; i<=n; ++i) dmin[i][i]=0;

    for(int i=1; i<=2*m; ++i) {
        int a=muc[i].y.x,b=muc[i].y.y,cst=muc[i].x;
        for(int j=1; j<=n; ++j) dmin[j][b]=min(dmin[j][b],dmin[j][a]+cst);
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            if(MULT==dmin[i][j]) printf("-1 ");
            else printf("%d ",dmin[i][j]);
        }
        printf("\n");
    }
    return 0;
}
