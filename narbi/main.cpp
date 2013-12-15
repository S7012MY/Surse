#include <iostream>
#include <fstream>
#define LL long long
using namespace std;


LL form(LL n){
    LL rez=0,lim=n<<1LL;
    for(int j=1; (1LL<<j)<=lim; ++j) {
        LL i=(1LL<<j);
        LL i2=(i>>1);
        if(n>=i)rez+=((n>>j)<<(j-1));
        if((n&(i-1))-(i2)>=0) rez+=(n&(i-1))-(i2)+1;
    }
    return rez;
}

long long n,k,xp,xc,fp,fc;

int main()
{
    ifstream f("narbi.in");
    ofstream g("narbi.out");
    f>>n>>k>>xp;
    fp=form(xp);
    if(k==n) g<<fp<<'\n';
    int mod=(1<<4)-1LL;
    for(int i=2; i<=n; ++i) {
        xc=xp+1LL+(fp&mod);
        fc=form(xc);
        if(n-i<k) g<<fc<<'\n';
        xp=xc;
        fp=fc;
    }
    return 0;
}
