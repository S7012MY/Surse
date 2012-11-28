#include <iostream>
#include <fstream>
#define MOD 9973
using namespace std;

int dp[1005];

int main()
{
    int n,k,rez=1;
    ifstream f("stiva2.in");
    ofstream g("stiva2.out");
    f>>n>>k;
    for(int i=1; i<=n; ++i) dp[i]=1;
    for(int i=2; i<=k; ++i) dp[i]=(dp[i-1]*2)%MOD;
    for(int i=k+1; i<=n; ++i)
        for(int j=1; j<=k; ++j) dp[i]=(dp[i]*dp[i-j])%MOD;
    g<<dp[n];
    return 0;
}
