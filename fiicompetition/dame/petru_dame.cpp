#include <cstdio>
#define DN 1005
#define DD 105
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

bool at[DN][DN],fol[DN][DN];
int n,m,dx[DD],dy[DD],nrd,nrp,rez;
const int x[]={-1,-1,-1,0,1,1, 1, 0},
          y[]={-1, 0, 1,1,1,0,-1,-1};

void marc(int px, int py) {
    for(int d=0; d<8; ++d) {
        int sx=px,sy=py;
        for(;sx>0 && sy>0 && sx<=n && sy<=m && !at[sx][sy]; sx+=x[d],sy+=y[d])
            fol[sx][sy]=1;
    }
}

int main()
{
    freopen("dame.in","r",stdin);
    freopen("dame.out","w",stdout);
    scanf("%d %d",&n,&m);
    scanf("%d",&nrd);
    for(int i=0; i<nrd; ++i)
        scanf("%d %d",&dx[i],&dy[i]);
    scanf("%d",&nrp);
    for(int i=0; i<nrp; ++i) {
        int x,y;
        scanf("%d %d",&x,&y);
        at[x][y]=fol[x][y]=1;
    }
    for(int i=0; i<nrd; ++i) marc(dx[i],dy[i]);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(!fol[i][j]) ++rez;
    printf("%d",rez);
    return 0;
}
