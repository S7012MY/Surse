#include <cstdio>
#define DN 200005
#define DV 20005
using namespace std;

int n,t,a[DN],frq[DV],rez=-1,b[DV],am,v;

int main()
{
    freopen("panouri.in","r",stdin);
    freopen("panouri.out","w",stdout);
    scanf("%d %d",&n,&t);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=1; i<=t; ++i) {
        scanf("%d",&v);
        b[v]=1;
    }
    for(int i=1,j=1; i<=n; ++i) {
        for(;am<t && j<=n;++j)
            if(b[a[j]]) {
                if(!frq[a[j]]) ++am;
                ++frq[a[j]];
            }
        int lgc=j-i;
        if(am==t && (0>rez ||rez>lgc)) rez=lgc;
        --frq[a[i]];
        if(0==frq[a[i]]) --am;
    }
    printf("%d",rez-1);
    return 0;
}
