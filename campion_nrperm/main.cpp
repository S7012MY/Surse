#include <cstdio>
#include <bitset>
#define DN 70
#define deb(n) fprintf(stderr,"%llu ",(n));
#define debi(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

bitset<DN> clc[DN];
int n,p[DN];
unsigned long long r,F[DN][DN],sp[DN][DN];

void memo(int i,int j) {
    if(clc[i][j]) return;
    memo(i-1,j); memo(i,j+1);
    clc[i][j]=1;
    F[i][j]=F[i-1][j]+F[i][j+1];
}

int main()
{
    freopen("nrperm.in","r",stdin);
    freopen("nrperm.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&p[i]);
        clc[i][n+1]=clc[0][i]=1;
    }
    clc[1][n]=1; F[1][n]=1;
    for(int i=1; i<=n; ++i) for(int j=i; j<=n; ++j) memo(i,j),sp[i][j]=F[i][j]+sp[i-1][j-1];
    int ls=p[1]-1,ld=p[1]+1;
    r+=sp[p[1]-1][p[1]-1];
    for(int x=2; x<=n; ++x) {
        if(p[x]==ld) {
            r+=F[ls][ld-1];
            ld=p[x]+1;
        }
        else ls=p[x]-1;
    }
    printf("%llu\n",r+1ULL);
    return 0;
}
