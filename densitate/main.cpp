#include <cstdio>
#define DN 500005

int n,q,a,b,isp[DN];

int main()
{
    freopen("densitate.in","r",stdin);
    freopen("densitate.out","w",stdout);
    scanf("%d %d",&n,&q);
    for(int i=2; i<=n; ++i) isp[i]=1;
    for(int i=2; i*i<=n; ++i) if(isp[i]) for(int j=i+i; j<=n; j+=i) isp[j]=0;
    for(int i=1; i<=n; ++i) isp[i]+=isp[i-1];
    for(;q--;) {
        scanf("%d %d",&a,&b);
        printf("%d\n",isp[b]-isp[a-1]);
    }
    return 0;
}
