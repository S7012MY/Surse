#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 100005
using namespace std;

typedef vector<int> graf[DN];
typedef vector<int>::iterator it;
bitset<DN> viz;
graf gr,gt,sol/*nu e graf*/;
int n,m,nr,q,v[DN],poz[DN];

void dfs(int sursa) {
    viz[sursa]=1;
    for(it i=gr[sursa].begin(); i!=gr[sursa].end(); ++i) if(0==viz[*i]) dfs(*i);
    v[++q]=sursa;
    poz[sursa]=q;
}

void dfst(int sursa) {
    viz[poz[sursa]]=1;
    for(it i=gt[sursa].begin(); i!=gt[sursa].end(); ++i) if(0==viz[poz[*i]]) dfst(*i);
    sol[nr].push_back(sursa);
}

int main()
{
    ifstream f("ctc.in");
    ofstream g("ctc.out");
    f>>n>>m;
    for (int i=1; i<=m; ++i) {
        int x,y;
        f>>x>>y;
        gr[x].push_back(y);
        gt[y].push_back(x);
    }
    for (int i=1; i<=n; ++i) if(0==viz[i]) dfs(i);
    viz&=0;
    for(int i=n; 0<i; --i) if(0==viz[i]) {
        ++nr;
        dfst(v[i]);
    }
    g<<nr<<'\n';
    for (int j=1; j<=nr; ++j) {
        for(it i=sol[j].begin();i!=sol[j].end(); ++i) g<<(*i)<<' ';
        g<<'\n';
    }
    return 0;
}

