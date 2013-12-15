#include <iostream>
#include <fstream>
#include <vector>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;

int n,m,sol[DN],sz,viz[DN];
vector<int> gr[DN];

void dfs(int s) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i);
    sol[++sz]=s;
}

int main()
{
    ifstream f("sortaret.in");
    ofstream g("sortaret.out");
    f>>n>>m;
    for(int i=0; i<m; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
    }
    for(int i=1; i<=n; ++i) if(!viz[i]) dfs(i);
    for(int i=sz;i;--i) g<<sol[i]<<' ';
    return 0;
}
