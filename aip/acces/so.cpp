 #include <cstdio>
#include <bitset>
#define DN 1005
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

int r[DN][DN],n,m,q;
bitset<DN> v[DN],viz[DN];
const int dx[]={1,0},dy[]={0,1};

bool check(int a,int b) {
    if(a>n || b>m) return 0;
    return 1;
}

void innd(int a, int b, int val) {
    viz[a][b]=1;
    r[a][b]=val;
    for(int d=0; d<2; ++d) if(check(a+dx[d],b+dy[d]) && 0==viz[a+dx[d]][b+dy[d]] && v[a+dx[d]][b+dy[d]]) innd(a+dx[d],b+dy[d],val);
}

int main()
{
    freopen("acces.in","r",stdin);
    freopen("acces.out","w",stdout);
    scanf("%d %d",&n,&m);
    int a;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        scanf("%d",&a);
        if(a) v[i][j]=1;
    }
    if(0==v[1][1]) r[1][1]=1;
    for(int i=2; i<=m; ++i)
        if(0==v[1][i]) r[1][i]=r[1][i-1]+1;
        else innd(1,i,0);
    for(int i=2; i<=n; ++i)
        if(0==v[i][1]) r[i][1]=r[i-1][1]+1;
        else innd(i,1,0);
    for(int i=2; i<=n; ++i) for(int j=1; j<=m; ++j)
        if(0==v[i][j]) {
            if(v[i-1][j-1]) {
                if(v[i-1][j]) r[i][j]=r[i][j-1]+1;
                else if(v[i][j-1]) r[i][j]=r[i-1][j]+1;
                else if(0==v[i-1][j] && 0==v[i][j-1]) r[i][j]=r[i-1][j]+r[i][j-1]-r[i-1][j-1]+1;
            }else {
                if(v[i-1][j]) r[i][j]=r[i][j-1]+1;
                else if(v[i][j-1]) r[i][j]=r[i-1][j]+1;
                else if(0==v[i-1][j] && 0==v[i][j-1]) r[i][j]=r[i-1][j]+r[i][j-1]-r[i-1][j-1]+1;
            }
        }else if(v[i][j] && 0==viz[i][j] && 0==v[i-1][j-1]) innd(i,j,r[i-1][j-1]);
    scanf("%d", &q);
    for(int i=1; i<=q; ++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",r[a][b]);
    }
    return 0;
}

