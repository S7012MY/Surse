#include <cstdio>
#include <algorithm>
using namespace std;

int m,n,p,v[700005],rc1,rc2,sm,nrmaj;

int main()
{
    freopen("livada1.in","r",stdin);
    freopen("livada1.out","w",stdout);
    scanf("%d %d %d",&m,&n,&p);
    nrmaj=n/2;
    for(int j=1; j<=m; ++j) {
        for(int i=1; i<=n; ++i) scanf("%d",&v[i]);
        int c1=1,c2=1;
        for(int i=2; i<=n; ++i) {
            if(v[i]==v[i-1]) ++c2;
            else c2=1;
            if(c2>rc2) rc2=c2;
        }
        sort(v+1,v+n+1);
        for(int i=2; i<=n; ++i) {
            if(v[i]==v[i-1]) ++c1;
            else c1=1;
            if(c1>nrmaj) {
                ++rc1;
                break;
            }
        }
    }
    printf("%d\n%d",rc1,rc2);
    return 0;
}
