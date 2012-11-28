#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;
int n,m,nrc,unde[DN],st[DN],sz,poz[DN];
bitset<DN> viz;
vector<int> gr[DN],gt[DN];

void dfs(int s) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i)
        if(!viz[*i])dfs(*i);
    st[++sz]=s;
    poz[s]=sz;
}

void dft(int s) {
    viz[poz[s]]=1;
    for(it i=gt[s].begin(); i!=gt[s].end(); ++i) if(!viz[poz[*i]])
        dft(*i);
    unde[s]=nrc;
    //cout<<s<<' '<<nrc<<'\n';
}

int gin[DN],gout[DN],nri,nro;

int main()
{
    ifstream f("drum4.in");
    ofstream g("drum4.out");
    f>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b;
        f>>a>>b;
        gr[a].push_back(b);
        gt[b].push_back(a);
    }
    for(int i=1; i<=n; ++i) if(!viz[i]) dfs(i);
    viz&=0;
    for(int i=n; i; --i) if(!viz[i]) {
        ++nrc;
        dft(st[i]);
    }
    if(nrc==1) {
        g<<0;
        return 0;
    }
   // cout<<nrc;
    for(int i=1; i<=n; ++i)
        for(it j=gr[i].begin(); j!=gr[i].end(); ++j)
            if(unde[i]!=unde[*j]) {
                ++gin[unde[i]];
                ++gout[unde[*j]];
            }
    for(int i=1; i<=nrc; ++i) {
        if(!gin[i]) ++nri;
        if(!gout[i]) ++nro;
    }
    g<<max(nri,nro);
    return 0;
}
