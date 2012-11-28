#include <iostream>
#include <fstream>
#define DN 100005
#define MOD 999983
using namespace std;

int n,k,nrs,v[10],sz,am[10];

inline int lgput(int b,int e) {
    if(e==0) return 1;
    if(e==1) return b;
    if(e&1) return (1LL*lgput(b,e-1)*b)%MOD;
    else {
        int hp=lgput(b,e/2);
        return (1LL*hp*hp)%MOD;
    }
}

void back(int t) {
    if(t>8) return;
    if(t==8) {
        int rc=1;
        for(int i=1; i<=sz; ++i) rc=(rc*1LL*am[v[i]])%MOD;
        nrs+=rc;
        if(nrs>=MOD) nrs-=MOD;
    }
    for(int i=1; i<=8; ++i) if(am[i]){
        v[++sz]=i;
        back(t+i);
        --sz;
    }
}

int main()
{
    ifstream f("tango.in");
    ofstream g("tango.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) {
        int x;
        f>>x;
        ++am[x];
    }
    back(0);
    cout<<nrs;
    g<<lgput(nrs,k/8);
    return 0;
}
