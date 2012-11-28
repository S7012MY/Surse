#include <iostream>
#include <fstream>
#include <cstdlib>
#define MOD 194767
using namespace std;

int n,s,dp[2][90000],smax;

int main()
{
    ifstream f("1-sir.in");
    ofstream g("1-sir.out");
    f>>n>>s;
    smax=(n*(n-1))/2;
    if(abs(s)>smax) {
        g<<"0";
        return 0;
    }
    dp[1][0]=1;
    for(int i=2; i<=n; ++i) for(int j=0; j<=smax; ++j) {
        dp[i&1][j]=dp[(i&1)^1][j+i-1]+dp[(i&1)^1][abs(j-i+1)];
        if(dp[i&1][j]>=MOD) dp[i&1][j]-=MOD;
    }
    g<<dp[n&1][s];
    return 0;
}
