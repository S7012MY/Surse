#include <iostream>
#include <fstream>
#define TMAX 10
#define MOD 999983
using namespace std;

int nr[TMAX],fr[TMAX];
int n,k;

inline int lgput(int b,int e) {
    int rez=1,var=b;
    for(;e>0;) {
        if(e&1) rez=(rez*1LL*var)%MOD;
        e>>=1;
        var=(var*1LL*var)%MOD;
    }
    return rez;
}

int main()
{
    ifstream f("tango.in");
    ofstream g("tango.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) {
        int x;
        f>>x;
        ++fr[x];
    }
    nr[0]=1;
    for(int i=0; i<=8; ++i) {
        for(int j=1; j<=8; ++j) if(i+j<=8) {
            nr[i+j]+=(nr[i]*1LL*fr[j])%MOD;
            if(nr[i+j]>=MOD) nr[i+j]-=MOD;
        }
    }
    g<<lgput(nr[8],k/8);
    return 0;
}
