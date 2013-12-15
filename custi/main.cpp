#include <iostream>
#include <fstream>
#include <bitset>
#define DN 1005
using namespace std;

bitset<DN> m[DN];
int n,dp[DN][DN],rez[DN];

int main()
{
    ifstream f("custi.in");
    ofstream g("custi.out");
    char c;
    f>>n;
    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
        f>>c;
        if('1'==c) m[i][j]=1;
    }

    for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
        if(m[i][j]) {
            dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            ++rez[dp[i][j]];
        }
    for(int i=n; i; --i) rez[i-1]+=rez[i];
    for(int i=1; i<=n; ++i) g<<rez[i]<<'\n';
    return 0;
}
