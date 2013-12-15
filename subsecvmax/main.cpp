#include <cstdio>
#define DN 100005

int n,v[DN],sol=1,bi=1,lgc=1;

int main()
{
    freopen("subsecvmax.in","r",stdin);
    freopen("subsecvmax.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&v[i]);
    for(int i=2; i<=n; ++i) {
        if(v[i]>=v[i-1]) ++lgc;
        else lgc=1;
        if(lgc>sol) {
            sol=lgc;
            bi=i-lgc+1;
        }
    }
    printf("%d %d",bi,sol);
    return 0;
}
