#include <cstdio>

int main()
{
    int pmax=0,v[100],n;
    freopen("2nr.in","r",stdin);
    freopen("2nr.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&v[i]);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(i!=j && v[i]*v[j]>pmax) pmax=v[i]*v[j];
    printf("%d",pmax);
}
