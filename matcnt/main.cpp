#include <iostream>
#include <fstream>
#define DN 100005
#define MOD 200003
using namespace std;

int n,a[DN]={1},inv=MOD/2+1,fct=1;

ifstream f("matcnt.in");
ofstream g("matcnt.out");

int main()
{
    f>>n;
    for(int i=2; i<=n; ++i) fct=(fct*1LL*i)%MOD;
    for(int i=3; i<=n; ++i) {
        a[i]=(a[i-3]*1LL*(i-2))%MOD;
        a[i]=(a[i]*1LL*inv)%MOD;
        a[i]=(a[i]+a[i-1])%MOD;
        a[i]=(a[i]*1LL*(i-1))%MOD;
    }
    g<<(a[n]*1LL*fct)%MOD;
    return 0;
}
