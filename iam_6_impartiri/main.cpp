#include <iostream>
#include <fstream>
#define DN 3005
#define MOD 2113
using namespace std;

int n,m,k,rez;
short nr,sv[DN],so[DN][2],nrm[DN],nrn[DN];

int main()
{
    ifstream f("impartiri.in");
    ofstream g("impartiri.out");
    f>>n>>m>>k;

    //sv[0][0]=so[0][0]=1;
    int mm=max(n,m);
    for(int dm=0; dm<=mm; ++dm){
        for(int i=0; i<=mm; ++i) sv[i]=0;
         for(int ul=1; ul<dm; ++ul) so[ul][dm&1]=so[ul][(dm&1)^1];
         for(int ul=dm; ul<=mm; ++ul) {
            if(dm!=ul) nr=0;
            else nr=1;
            int vl=0;
            if(ul-dm-1>=0) vl=sv[ul-dm-1];
            nr=(nr+sv[ul-1]-vl+MOD)%MOD;
            nr=(nr+so[ul-dm][(dm&1)^1])%MOD;

            if(ul) sv[ul]=(nr+sv[ul-1])%MOD;
            if(dm) so[ul][dm&1]=(nr+so[ul][(dm&1)^1])%MOD;
            if(ul==n)nrn[dm]=nr;
            if(ul==m)nrm[dm]=nr;

        }
    }

    for(int a=1; a<=n; ++a) for(int b=1; b<=m; ++b) if(a*b<=k)
        rez=(rez+nrn[a]*1LL*nrm[b])%MOD;

    g<<rez;
    return 0;
}
