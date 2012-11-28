#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 1000005
using namespace std;

typedef vector<int>::iterator it;
int n,m,p;
vector<int> gt[DN];
bitset<DN> viz;

void dfs(int s) {
    viz[s]=0;
    for(it i=gt[s].begin(); i!=gt[s].end(); ++i) if(viz[*i]) dfs(*i);
}

int main()
{
    ifstream f("berarii2.in");
    ofstream g("berarii2.out");
    f>>n>>m>>p;
    for(int i=0; i<m; ++i) {
        int a,b;
        f>>a>>b;
        gt[b].push_back(a);
    }
    for(int i=1; i<=n; ++i) viz[i]=1;
    for(int i=0; i<p; ++i) {
        int a;
        f>>a;
        dfs(a);
    }
    g<<viz.count()<<'\n';
    for(int i=1; i<=n; ++i) if(viz[i]) g<<i<<'\n';
    return 0;
}
