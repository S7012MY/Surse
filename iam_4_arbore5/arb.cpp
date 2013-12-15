#include <fstream>
#include <vector>
#include <iostream>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;

int n,m,vl[DN],dp[DN],rez;
vector<int> gr[DN];

void dfs(int s, int f) {
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(*i!=f) {
        dfs(*i,s);
        dp[s]+=dp[*i];
    }
    dp[s]+=vl[s];
    if(dp[s]%2==0 && s!=1) ++rez;
}

int main()
{
    ifstream f("arbore5.in");
    ofstream g("arbore5.out");
    f>>n>>m;
    for(int i=1; i<n; ++i) {
        int a,b;
        f>>a>>b;
        //cout<<a<<' '<<b<<'\n';
        cout.flush();
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for(int i=1; i<=m; ++i) {
        int a,b;
        f>>a>>b;
        ++vl[a]; ++vl[b];
    }
    dfs(1,0);
    //for(int i=1; i<=n; ++i) cout<<dp[i]<<' ';
    g<<rez;
    return 0;
}
