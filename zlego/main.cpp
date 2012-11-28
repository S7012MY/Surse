#include <cstdio>
#define DN 250005

int t,n,pi[DN],h[DN];
long long vl[DN];

void p() {
    for(int i=2,q=0;i<=n; ++i) {
        for(;q && h[q+1]!=h[i];q=pi[q]);
        if(h[q+1]==h[i]) ++q;
        pi[i]=q;
    }
}

int main()
{
    freopen("zlego.in","r",stdin);
    freopen("zlego.out","w",stdout);
    for(scanf("%d",&t);t;--t) {
        scanf("%d",&n);
        for(int i=1; i<=n;++i) scanf("%d",&h[i]);
        for(int i=1; i<=n;++i) scanf("%lld",&vl[i]);
        p();
        for(int i=n; i>0; --i) vl[pi[i]]+=vl[i];
        for(int i=1; i<=n; ++i) printf("%lld\n",vl[i]);
    }
    return 0;
}
