#include <iostream>
using namespace std;

long long l,r,mod,k,lg;

bool pot(long long nr) {
    if(nr==1) return 1;
    ++nr;
    long long nzero=lg/nr;
    if(nzero>=k) return 1;
    nzero=0;
    for(long long cnr=nr;cnr<=r;cnr*=nr) {
        if(cnr>=l && cnr<=r) ++nzero;
    }
    if(nzero>=k) return 1;
    return 0;
}

int main()
{
    cin>>mod>>l>>r>>k;
    lg=r-l+1;
    long long ls=1,ld=2,rez,m;
    rez=lg/k;
    for(;pot(rez);++rez);
    for(;!pot(rez);--rez);
    cout<<rez%mod;
    return 0;
}

