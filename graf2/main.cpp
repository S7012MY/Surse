#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 605
using namespace std;

typedef vector<int>::iterator it;

bitset<DN> viz;
vector<int> gr[DN],gt[DN];
int n,m,st[DN],sz,poz[DN],nr;

void dfs(int s) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
        if(0==viz[*i]) dfs(*i);
        st[++sz]=s;
        poz[s]=sz;
    }
}

void dfst(int s) {
    viz[s]=1;
    for(it i=gt[s].begin(); i!=gt[s].end(); ++i)
        if(0==viz[poz[i]]) dfst(*i);

}

int main()
{
   /* ifstream f("graf2.in");
    ofstream g("graf2.out");
    f>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
        gt[b].push_back(a);
    }
    for(int i=1; i<=n; ++i)
        if(0==viz[i]) dfs(i);
    viz&=0;
    for(int i=1; i<=n; ++i) if(0==viz[i]) {
        ++nr;
        dfst(st[i])
    }
    g<<rez;*/
    return 0;
}
