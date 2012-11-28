#include <iostream>
using namespace std;

int n,k,dp[50][2];

int main() {
	cin>>n>>k;
	dp[1][1]=k-1;
	for(int i=2; i<=n; ++i) {
		dp[i][0]=dp[i-1][1];
		dp[i][1]=(dp[i-1][0]+dp[i-1][1])*(k-1);
	}
	cout<<dp[n][0]+dp[n][1];
	return 0;
}
