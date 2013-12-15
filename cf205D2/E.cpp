#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#define DN 1000005
using namespace std;

typedef vector<int>::iterator it;

int n,dp[2][2][DN];
vector<int> gr[DN],gt[DN];
string s;
bitset<DN> viz;

void dfs(int s) {
  viz[s]=1;
  for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i);
}

void dft(int s) {
  viz[s]=1;
  for(it i=gt[s].begin(); i!=gt[s].end(); ++i) if(!viz[*i]) dft(*i);
}

int main() {
  cin>>s; n=s.size();
  for(int i=0; i<n; ++i) {
    int nx=i+1; if(nx>=n) nx=0;
    if(s[i]=='0') {gr[i].push_back(nx); gt[nx].push_back(i);}
    else {gt[i].push_back(nx); gr[nx].push_back(i);}
  }
  dfs(0);dft(0);
  dp[0][0][0]=0;
  dp[1][1][0]=1;
  for(int i=1; i<n; ++i) {
    int back=0;
    //for(it j=gr[i].begin(); j!=gr[i].end(); ++j) if(*j==i-1) back=1;
    //for(it j=gt[i].begin(); j!=gt[i].end(); ++j) if(*j==i-1) back=1;
    if(!viz[i]) {
      dp[0][1][i]=max(dp[0][0][i-1]+1,dp[0][1][i-1]);
      dp[1][1][i]=max(dp[1][0][i-1]+1,dp[1][1][i-1]);
      dp[0][0][i]=max(dp[0][0][i-1],dp[0][1][i-1]);
      dp[1][0][i]=max(dp[1][0][i-1],dp[1][1][i-1]);
    }else {

    }
    cout<<i<<' '<<back<<' '<<viz[i]<<' '<<dp[0][0][i]<<' '<<dp[0][1][i]<<' '<<dp[1][0][i]<<' '<<dp[1][1][i]<<'\n';
  }
  int r=max(max(dp[0][0][n-1],dp[0][1][n-1]),max(dp[1][0][n-1],dp[1][1][n-1]));
  cout<<r;
}
