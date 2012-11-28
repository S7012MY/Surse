#include <iostream>
#include <fstream>
#define DN 100005
using namespace std;

int n,K,s[DN];

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
        s[i]=s[i-1];
        f>>nr;
        if(isp(nr))++s[i];
    }
    int i,j=0,k=0,rez=0;
    for(i=1; i<=n; ++i) {
       if(s[i]>s[i-1]) {
           for(j=k;s[i]-s[j+1]>K;++j);
           if(s[i]-s[j+1]==K && s[j+1]>s[j]) ++j;
           for(;s[i]-s[k+1]>=K;++k);
       }
       if(s[i]-s[k]==K) rez+=k-j+1;
    }
    g<<rez;
    return 0;
}
