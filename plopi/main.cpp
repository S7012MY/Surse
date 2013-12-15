#include <fstream>
#include <vector>
#define DN 100005
#define LL long long
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;
int n;
LL rez,dp[DN][2];
vector<per> gr[DN];

void dfs(int s) {
    dp[s][0]=1;
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(!dp[i->x][0])  {
        dfs(i->x);
        rez+=dp[s][0]*dp[i->x][i->y^1];
        rez+=dp[s][1]*dp[i->x][i->y];
        dp[s][0]+=dp[i->x][i->y];
        dp[s][1]+=dp[i->x][i->y^1];
    }
}

int main()
{
    ifstream f("plopi.in");
    ofstream g("plopi.out");
    f>>n;
    for(int i=1; i<n; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        gr[a].push_back(make_pair(b,c&1));
        gr[b].push_back(make_pair(a,c&1));
    }
    dfs(1);
    g<<rez;
    return 0;
}
