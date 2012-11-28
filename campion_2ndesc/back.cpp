#include <cstdio>
#define MOD 666013
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,nr[2000005],rez,nrp;

void back(int p,int lst) {
    if(p>rez) return;
    if(p==rez) {
        ++nrp;
        //for(int i=1; i<=nr[0]; ++i) deb(nr[i])
        //debnl
        return;
    }
    for(int i=2; i<10; i*=2) {
        nr[++nr[0]]=i;
        back(p*i,i);
        --nr[0];
    }
}

int main()
{
    freopen("2ndesc.in","r",stdin);
    freopen("gen.out","w",stdout);
    scanf("%d",&n);
    for(int n=1; n<31; ++n) {
        rez=(1<<n);
        nrp=0;
        back(1,1);
        deb(n) deb(nrp) debnl
        printf("%d %d",n,nrp);
    }
    return 0;
}
