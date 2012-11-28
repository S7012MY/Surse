#include <iostream>
#include <vector>
#define DN 6005
using namespace std;

typedef vector<int>::iterator it;
int n,cst[DN],dp[2][DN],a=-1,b=-1;

vector<int> gr[DN];

void dfs(int s, int f) {
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(*i!=f) dfs(*i,s);
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
        if(dp[0][*i]>0) dp[1][s]+=dp[0][*i];
        if(dp[1][*i]>0) dp[0][s]+=dp[1][*i];
    }
    if(cst[s]>0) dp[1][s]+=cst[s];
    dp[1][s]=max(dp[1][s],dp[0][s]);
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>cst[i];
    for(;a!=0 || b!=0;) {
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    dfs(1,-1);
    cout<<max(dp[0][1],dp[1][1]);
    return 0;
}
