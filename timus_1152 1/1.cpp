#include <iostream>
#include <queue>
#define DN (1<<21)
#define MULT 50005
using namespace std;

int n,v[21],cst[DN],dp[DN];
queue<int> c;

void dfs(int state) {
	for(c.push(state);c.size(); c.pop()) {
		int fr=c.front();
		for(int i=0; i<n; ++i) {
			int nxt=fr|(1<<i);
			if(0==i) nxt|=(1<<(n-1))|(1<<(i+1));
			else if(n-1==i) nxt|=((1<<(i-1))|1);
			else nxt|=(1<<(i-1))|(1<<(i+1));
			if(dp[nxt]>dp[fr]+cst[nxt]) {
				dp[nxt]=dp[fr]+cst[nxt];
				c.push(nxt);
			}
		}
	}
}

int main() {
	cin>>n;
	for(int i=0; i<n; ++i) cin>>v[i];
	for(int i=0; i<(1<<n); ++i) {
		for(int j=0; j<n; ++j) if(!(i&(1<<j))) cst[i]+=v[j];
		dp[i]=MULT;
	}
	dp[0]=0;
	dfs(0);
	cout<<dp[(1<<n)-1];
	return 0;
}