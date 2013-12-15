#include <cstdio>
#include <cstdlib>
#include <bitset>
#define DN 17
#define BIT(n, i) ((n >> i) & 1)
#define inf -2147483647
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

//E(M1)*E(M2)-2*E(M1)-2*E(M2)-6

int n,v[DN],lm,sl[1<<DN];
bitset< 1<<DN > c;

int lsb(int n) {
    for(int i=0;i<=16; ++i) if(BIT(n,i)) return i;
    //return n^(n&(n-1));
}

int msb(int n) {
    int r=0;
    for(int i=0;i<=16; ++i) if(BIT(n,i)) r=i;
    return r;
}

int nrb(int i) {
	return i?1+nrb(i&(i-1)):0;
}

int memo(int sm) {
    if(c[sm]) return sl[sm];
    //deb(sm)
    //for(int i=lb;i<=mb; ++i) if(BIT(sm,i)) msk+=(1<<i);
    for(int i=1;i<sm;++i) if(0!=(i&sm) && 0==(i&(~sm)) && nrb(i)!=nrb(sm)) {
        int m1=memo(i),m2=memo(sm^i);
        sl[sm]=max(sl[sm],m1*m2-2*m1-2*m2-6);
    }
    c[sm]=1;
    return sl[sm];

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
        c[1<<i]=1;
        sl[1<<i]=v[i];
    }
    printf("%d\n",memo(lm));
    return 0;
}
