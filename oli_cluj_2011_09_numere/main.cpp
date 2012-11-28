#include <cstdio>
#include <bitset>
#include <fstream>
#include <iostream>
#define DN 1000005
using namespace std;

bitset<DN> isp;
int n,cnt,pr[DN],sz;

void c() {
    for(int i=2; i<DN; ++i) if(0==isp[i]){
        pr[++sz]=i;
        for(int j=i+i; j<DN; j+=i) isp[j]=1;
    }
}

int nc(int n) {
    int nc=0;
    for(;n;++nc,n/=10);
    return nc;
}

int izp(long long n) {
    for(long long i=2; i*i<=n; ++i) if(0==n%i) return 0;
    return 1;
}

int main()
{
    freopen("numere.in","r",stdin);
    ifstream f("numere.out");
    scanf("%d",&n);
    c();
    for(int i=1; i<=sz; i+=2) {
        int nr1=pr[i],nr2=pr[i+1];
        int nrc=nc(nr2);
        long long pz=1;
        for(int j=1; j<=nrc; ++j) pz*=10;
        long long nrf=nr1*pz+nr2;
        if(izp(nrf)) ++cnt;
        if(cnt==n) {
            long long r;
            f>>r;
            if(r!=nrf) {
                cerr<<"EROARE";
                while(1);
            }
            cerr<<r<<' '<<nrf<<"\nOK\n";
           return 0;
        }
    }
    printf("ERROR");
    return 0;
}
