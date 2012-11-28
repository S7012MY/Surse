#include <fstream>
using namespace std;

int n,s[25],dp[(1<<21)],viz[(1<<21)];

int memo(int state) {
    if(dp[state]!=-1) return dp[state];
    dp[state]=0;
    int m=0;
    for(int i=0; i<n; ++i)
        if(state&(1<<i)){
            if(m==s[i]-1) dp[state]+=memo(state^(1<<i));
            if(m<s[i]) m=s[i];
        }
    return dp[state];
}

int main()
{
    ifstream f("invcs.in");
    ofstream g("invcs.out");
    f>>n;
    for(int i=1; i<(1<<n); ++i) dp[i]=-1;
    for(int i=0; i<n; ++i) {
        f>>s[i];
        if(1==s[i]) dp[1<<i]=1;
    }
    g<<memo((1<<n)-1);
    return 0;
}
