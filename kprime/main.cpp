#include <iostream>
#include <fstream>
#define DN 100005
using namespace std;

int n,K,pp[DN],sz;

int isp(int n) {
    if(n==1) return 0;
    for(int i=2; i*i<=n; ++i) if(0==n%i) return 0;
    return 1;

}

int main()
{
    ifstream f("kprime.in");
    ofstream g("kprime.out");
    f>>n>>K;
    for(int i=1,nr;i<=n; ++i) {
        f>>nr;
        if(isp(nr)) pp[++sz]=i;
    }
    pp[sz+1]=n+1;
    int rez=0;
    for(int i=1; i<=sz-K+1; ++i)
        rez+=(pp[i]-pp[i-1])*(pp[i+K]-pp[i+K-1]);
    g<<rez;
    return 0;
}
