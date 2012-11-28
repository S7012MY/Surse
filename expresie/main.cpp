#include <cstdio>
#define DN 1005

long long v[DN],n,sum,bst,sc;

long long max(long long a, long long b) {
    if(a>b) return a;
    return b;
}

int main()
{
    freopen("expresie.in","r",stdin);
    freopen("expresie.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1; i<=n; ++i) scanf("%lld",&v[i]),sum+=1LL*v[i];
    for(int i=2; i<n; ++i) for(int j=i+1; j<=n; ++j) {
        if(j!=i+1) sc=sum-v[i-1]-v[i]-v[j-1]-v[j]+1LL*v[i-1]*v[i]+1LL*v[j-1]*v[j];
        else sc=sum-v[i-1]-v[i]-v[j]+v[i-1]*1LL*v[i]*v[j];
        bst=max(bst,sc);
    }
    printf("%lld",bst);
    return 0;
}
