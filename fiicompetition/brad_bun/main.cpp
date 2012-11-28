#include <cstdio>
#define LL long long
#define deb(n) fprintf(stderr,"%lld ",(n));

LL sp[35];
int n;

LL fa(int nr) {
    if(nr==1) return 1;
    int i=0;
    for(;(1LL<<i)<nr;++i);
    --i;
    return 2*fa(nr-(1<<i));
}

int main()
{
    freopen("brad.in","r",stdin);
    freopen("brad.out","w",stdout);
    scanf("%d",&n);
    sp[0]=1;
    for(int i=1; i<32; ++i) sp[i]=sp[i-1]+(1LL<<i);
    int p=0;
    for(;sp[p]<n;++p);
    --p;
    //deb(n-sp[p])
    printf("%lld",fa(n-sp[p]));
    return 0;
}
