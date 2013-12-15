#include <iostream>
#include <fstream>
#define DN 5005
using namespace std;

int n,a[DN],dp[DN],pre[DN];

int main()
{
    ifstream f("subsir2.in");
    ofstream g("subsir2.out");
    f>>n;
    for(int i=1; i<=n; ++i) f>>a[i];
    dp[n]=1;
    pre[n]=-1;
    int emin,mmin,pmin;
    for(int i=n-1; 0<i; --i) {
        pmin=0;
        emin=mmin=9999999;
        for(int j=i+1; j<=n; ++j) if(a[i]<=a[j]) {
            if(a[j]<emin) {
                if(dp[j]<mmin) mmin=dp[j], pmin=j;
                else if(dp[j]==mmin && a[j]<a[pmin]) pmin=j;
            }
            emin=min(emin,a[j]);
        }
        if(pmin) {
            dp[i]=dp[pmin]+1;
            pre[i]=pmin;
        }else dp[i]=1,pre[i]=-1;
    }
    emin=mmin=9999999;
    for(int i=1; i<=n; ++i) {
        if(dp[i]<mmin && a[i]<emin) mmin=dp[i], pmin=i;
        if(dp[i]==mmin && a[i]<a[pmin] && a[i]<emin) pmin=i;
        if(a[i]<emin) emin=a[i];
    }
    g<<dp[pmin]<<'\n';
    int i;
    for(i=pmin; pre[i]!=-1; i=pre[i]) g<<i<<' ';
    g<<i;
    return 0;
}
