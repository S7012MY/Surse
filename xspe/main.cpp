#include <cstdio>
#define DN 1000005

int n,s[DN],st[DN],vf,sol[DN];

int main()
{
    freopen("xspe.in","r",stdin);
    freopen("xspe.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&s[i]);
    for(int i=n; i>0; --i) {
        sol[i]=s[i];
        for(;vf && st[vf]>=s[i];--vf);
        if(vf) sol[i]+=st[vf];
        st[++vf]=s[i];
    }
    for(int i=1; i<=n; ++i) printf("%d ",sol[i]);
    return 0;
}
