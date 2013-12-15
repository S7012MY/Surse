#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 100005
using namespace std;

ifstream f("atena.in");
ofstream g("atena.out");
typedef vector<int>::iterator it;

int n1,m1,n2,m2,na,nb;
vector<int> gr[DN],cc[DN];
bitset<DN> viz;

void read(int &n, int &m) {
    f>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
}

void dfs(int s,int c) {
    viz[s]=1;
    if(c) cc[na].push_back(s);
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i,c);
}

int main()
{
    read(n1,m1); read(n2,m2);
    for(int i=1; i<=n1; ++i) if(!viz[i]) ++na,dfs(i,1);
    for(int i=n1+1; i<=n1+n2; ++i) if(!viz[i]) ++nb,dfs(i,0);
    if(na!=nb) {
        g<<"NU";
        return 0;
    }
    g<<"DA\n";
    int cate=n2-nb;
    for(int i=1; i<=na; ++i) {
        for(;cate && cc[i].size();--cate) {
            g<<1<<' '<<cc[i][cc[i].size()-1]<<'\n';
            cc[i].pop_back();
        }
        if(cc[i].size()) {
            g<<cc[i].size()<<' ';
            for(int j=0; j<cc[i].size(); ++j) g<<cc[i][j]<<' ';
            g<<'\n';
        }
    }
    return 0;
}

