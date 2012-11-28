#include <iostream>
using namespace std;

int n,dp[500][2005];

int main() {
        cin>>n;
        if(n&1) {
                cout<<0;
                return 0;
        }
        dp[0][0]=1;
        for(int i=1; i<=n/2; ++i) for(int s=0; s<=100; ++s)
                for(int j=0; j<10; ++j) {
                	//if(i==1 && j==0) continue;
                	dp[i][s+j]+=dp[i-1][s];
                }
        long long rez=0;
        for(int i=1; i<=100; ++i) rez+=(1LL*dp[n/2][i]*dp[n/2][i]);
        cout<<rez+1;
        return 0;
}

