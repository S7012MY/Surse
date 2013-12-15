#include <iostream>
#include <fstream>
#include <vector>
#define DN 20
#define DX 1<<20
#define MULT 100000000
using namespace std;

typedef vector<int>::iterator it;

int n,m,cost[DN][DN],dp[DX][DN],sol;
vector<int> gr[DN];

int main()
{
    ifstream f("hamilton.in");
    ofstream g("hamilton.out");
    f>>n>>m;
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cost[i][j]=MULT;
    for(int i=1; i<=m; ++i) {
        int x,y;
        f>>x>>y;
        gr[y].push_back(x);
        f>>cost[x][y];
    }
    for(int i=0; i<(1<<n); ++i) for(int j=0; j<n; ++j) dp[i][j]=MULT;
    dp[1][0]=0;
    for(int i=0; i<(1<<n); ++i) for(int j=0; j<n; ++j) if(i&(1<<j))
        for(it k=gr[j].begin(); k!=gr[j].end(); ++k) if(i&(1<<(*k))) dp[i][j]=min(dp[i][j],dp[i^(1<<j)][*k]+cost[*k][j]);
    sol=MULT;
    for(it k=gr[0].begin(); k!=gr[0].end(); ++k) sol=min(sol,dp[(1<<n)-1][*k]+cost[*k][0]);
    if(MULT==sol) g<<"Nu exista solutie\n";
    else g<<sol;
    return 0;
}

