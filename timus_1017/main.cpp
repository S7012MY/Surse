#include <iostream>
#define DN 505
using namespace std;

long long n,dp[DN][DN];

int main()
{
    cin>>n;
    for(int i=0; i<n; ++i) dp[i][i]=1;
    for(int i=1; i<n; ++i) for(int j=i-1; 0<=j; --j) dp[i][j]=dp[i-j-1][j+1]+dp[i][j+1];
    cout<<dp[n-1][0]-1;
    return 0;
}
