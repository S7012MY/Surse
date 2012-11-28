#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define DN 40
using namespace std;

int n,MOD,rez[DN][DN],rf[DN][DN],aux[DN][DN],mi[DN][DN];
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

int countTours(vector<string> g, int k, int m) {
    n=g.size(); MOD=m;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) if('Y'==g[i][j]) mi[i][j]=1;
        mu[i][i]=1;
    }
    fa(k-1);
    int r=0;
    for(int i=0; i<n; ++i) r=(r+rf[i][i])%MOD;
    return r;
}

int main()
{
    vector<string> apel;
    apel.resize(8);
    apel[0]="NYNNNNN";
    apel[1]="NNYNNNN";
    apel[2]="NNNYNNN";
    apel[3]="NNNNYNN";
    apel[4]="NNNNNYN";
    apel[6]="NNNNNNY";
    apel[7]="YNNNNNN";
    cout<<countTours(apel,40,13);
    return 0;
}
