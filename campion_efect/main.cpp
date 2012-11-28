#include <cstdio>
#define DN 17
#define inf -2147483647
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

//E(M1)*E(M2)-2*E(M1)-2*E(M2)-6

int n,v[DN],lm,sl[1<<DN];

inline int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int main()
{
    freopen("efect.in","r",stdin);
    freopen("efect.out","w",stdout);
    scanf("%d",&n);
    lm=(1<<n)-1;
    for(int i=0; i<=lm; ++i) sl[i]=inf;
    for(int i=0; i<n; ++i) {
        scanf("%d",&v[i]);
        sl[1<<i]=v[i];
    }
    for(int s=1; s<=lm; ++s)
        for(int i=s&(s-1);i>0;i=s&(i-1))
            sl[s]=max(sl[s],1LL*sl[i]*sl[i^s]-2LL*sl[i]-2LL*sl[i^s]-6LL);
    printf("%d\n",sl[lm]);
    return 0;
}
