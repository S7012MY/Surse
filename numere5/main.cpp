#include <cstdio>
#define LL long long

LL st,el,n,nrz,sc;

LL gauss(LL n) {
    return (n*(n+1LL))/2LL;
}

LL sum(LL a, LL b) {
    return gauss(b)-gauss(a-1LL);
}

int main()
{
    freopen("numere5.in","r",stdin);
    freopen("numere5.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        scanf("%lld",&el);
        if(0==el) ++nrz;
        else st+=el;
    }
    //fprintf(stderr,"%d",sum(2,4));
    sc=sum(1,n*n);
    for(int i=1; i<=n*n; ++i) if(sum(i,i+nrz-1)+st==sc) {
        printf("%d %d",i,i+nrz-1);
        return 0;
    }
    return 0;
}
