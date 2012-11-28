#include <iostream>
#define DN 10005
using namespace std;

int s,f,dp[DN],viz[DN];

bool brute(int n, int i) {
    for(int j=1; j<=100; ++j) if(i==(n*j)/100 && 0==(n*j)%100) return 1;
    return 0;
}

int memo(int n) {
    if(-1!=viz[n]) return dp[n];
    for(int i=1; i<=n && i+n<=f; ++i) if((100*i)%n==0) dp[n]=max(dp[n],memo(n+i)+1);
    //for(int i=1; i<=n && i+n<=f; ++i) if(brute(n,i)) dp[n]=max(dp[n],memo(n+i)+1);
    viz[n]=1;
    return dp[n];
}

int main()
{
    cin>>f>>s;
    for(int i=s; i<=f; ++i) viz[i]=-1,dp[i]=1;
    cout<<memo(s);
    //for(int i=s; i<=f; ++i) cout<<dp[i]<<' ';
    return 0;
}
