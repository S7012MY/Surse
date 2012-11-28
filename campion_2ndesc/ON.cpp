#include <cstdio>
#define MOD 666013
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,nr[100005]={0,1,2,4},rez,nrp;

int main()
{
    freopen("2ndesc.in","r",stdin);
    freopen("2ndesc2.out","w",stdout);
    scanf("%d",&n);
    for(int i=4; i<=n; ++i) nr[i]=(nr[i-1]+nr[i-2]+nr[i-3])%MOD;
    printf("%d",nr[n]);
    return 0;
}
