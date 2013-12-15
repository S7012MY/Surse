#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#define DN 105
using namespace std;

int n,m,MOD=10007,rez[DN][DN],rf[DN][DN],aux[DN][DN],mi[DN][DN];
int mu[DN][DN];

void inm(int a[DN][DN],int b[DN][DN],int r[DN][DN]) {
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
        int c=0;
        for(int k=0; k<n; ++k) c=(c+1LL*a[i][k]*b[k][j])%MOD;
        r[i][j]=c;
    }
}

void add(int a[DN][DN], int b[DN][DN]) {
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) {
        a[i][j]+=b[i][j];
        if(a[i][j]>=MOD) a[i][j]-=MOD;
    }
}

void lgput(int e) {
    int c[DN][DN];
    memset(rez,0,sizeof(rez));
    memcpy(c,mi,sizeof(c));
    for(int i=0; i<n; ++i) rez[i][i]=1;
    for(int i=0; (1<<i)<=e; ++i) {
        if((1<<i)&e) {
            inm(rez,c,aux);
            memcpy(rez,aux,sizeof(rez));
        }
        inm(c,c,aux);
        memcpy(c,aux,sizeof(aux));
    }
}

void fa(int k) {
    memset(rez,0,sizeof(rez));
    if(k==0) return;
    if(k&1) {
        fa(k-1);
        lgput(k);
        add(rf,rez);
    }else {
        fa(k/2);
        lgput(k/2);
        add(rez,mu);
        inm(rf,rez,aux);
        memcpy(rf,aux,sizeof(rf));
    }
}

int main()
{
    ifstream f("drumuri3.in");
    ofstream g("drumuri3.out");
    int k,q;
    f>>n>>m>>k>>q;
    for(int i=0; i<n; ++i) mu[i][i]=1;
    for(int i=1; i<=m; ++i) {
        int a,b;
        f>>a>>b;
        --a; --b;
        mi[a][b]=mi[b][a]=1;
    }
    fa(k-1);
    for(int i=1; i<=q; ++i) {
        int a,b;
        f>>a>>b;
        --a; --b;
        g<<rf[a][b]<<'\n';
    }
    return 0;
}
