#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;

vector<int> gr[DN];
int n,m,cst[DN],vl[DN],viz[DN];

void dfs(int s) {
    ++viz[s];
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) {
        vl[s]=min(vl[s],vl[*i]);
        if(viz[*i]<2) dfs(*i);
        vl[s]=min(vl[s],vl[*i]);
    }
}

int main()
{
    ifstream f("srevni.in");
    ofstream g("srevni.out");
    f>>n>>m;
    for(int i=1; i<=n; ++i) {
        f>>cst[i];
        vl[i]=cst[i];
    }
    for(int i=0; i<m; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
    }
    for(int i=1; i<=n; ++i) {
        if(viz[i]<2) dfs(i);
        g<<vl[i]<<' ';
    }
    return 0;
}
