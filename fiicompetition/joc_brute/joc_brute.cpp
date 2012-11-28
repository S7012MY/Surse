#include <cstdio>
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
#define DN 20005
#define DV 105
#define MULT 9999999

int n,d[DN],p[DN],rez=MULT;

inline int min(int a, int b) {
    if(a<b) return a;
    return b;
}

int main()
{
    freopen("joc.in","r",stdin);
    freopen("joc.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; ++i) scanf("%d %d",&d[i],&p[i]);
    for(int i=0; i<(1<<n); ++i) {
        int vc=100,cnt=0,ok=1;
        for(int j=0; j<n; ++j)
            if(i&(1<<j)) {
                ++cnt;
                vc=min(100,vc+d[j]);
            }else {
                if(vc-p[j]+d[j]<=0) {
                    ok=0;
                    break;
                }
                vc=min(100,vc+d[j]-p[j]);
            }
            if(ok) rez=min(rez,cnt);
    }
    printf("%d ",rez);
    return 0;
}
