#include <fstream>
#define LL long long
#define rp put
using namespace std;


LL n,a=1,b=1,nrl,rez;

inline LL put(LL x, int n)
{
    LL r;

    for(r=1; n; n>>=1)
    {
        if(n&1)
          r=1LL*r*x;
        x=1LL*x*x;
    }
    return r;
}

int main()
{
    ifstream f("prodiv.in");
    ofstream g("prodiv.out");
    f>>n;
    LL cn=n;
    for(LL i=2; i*i<=cn; ++i) {
        if(n==1) break;
        if(0==n%i) {
            int pt=0;
            for(;0==n%i;++pt,n/=i);
            a*=put(i,pt/2); b*=put(i,pt/2);
            if(pt&1) {
                ++nrl;
                b*=i;
            }
        }
    }
    if(n>1) ++nrl;
    rez=(1LL<<nrl);
    g<<a<<' '<<b<<'\n'<<rez;
    return 0;
}
