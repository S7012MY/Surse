#include <iostream>
#include <vector>
#include <algorithm>
#define DN 1005
using namespace std;

typedef vector<int>::iterator it;

int n,k,dp[DN];
vector<int> gr[DN];

void dfs(int s,int f) {
	dp[s]=0;
	for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(f!=*i) {
		dfs(*i,s);
		if(0==dp[*i]) dp[s]=1;
	}
	//cout<<s<<' '<<dp[0][s]<<' '<<dp[1][s]<<'\n';
}

int main(){
	cin>>n>>k;
	for(int i=1; i<n; ++i) {
		int a,b;
		cin>>a>>b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	sort(gr[k].begin(),gr[k].end());
	dfs(k,-1);
	for(it i=gr[k].begin(); i!=gr[k].end(); ++i) if(0==dp[*i]) {
		cout<<"First player wins flying to airport "<<*i;
		return 0;
	}
	cout<<"First player loses";
	return 0;
}
