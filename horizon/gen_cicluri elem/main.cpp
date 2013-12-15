#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
#define DN 205
using namespace std;

typedef vector<int>::iterator it;

vector<int> gr[DN],arb[DN],drum;
bitset<DN> viz;
vector<vector<int> > sol;

int ma[DN][DN],a[DN*DN],b[DN*DN];
int n,m,gb;

void farb(int s) {
    viz[s]=1;
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(viz[*i]==0) {
        ma[s][*i]=ma[*i][s]=2;
        arb[s].push_back(*i);
        arb[*i].push_back(s);
        farb(*i);
    }
}

void dfs(int s) {
    viz[s]=1;
    //fout<<s<<' ';
    drum.push_back(s);
    if(s==gb) sol.push_back(drum);
    for(it i=arb[s].begin(); i!=arb[s].end(); ++i) if(0==viz[*i]) dfs(*i);
    drum.pop_back();
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin>>n>>m;
    for(int i=1; i<=m; ++i) {
        int aa,ab;
        fin>>aa>>ab;
        gr[aa].push_back(ab);
        gr[ab].push_back(aa);
        a[i]=aa; b[i]=ab;
        ma[aa][ab]=ma[ab][aa]=1;
    }
    for(int i=1; i<=n; ++i) if(0==viz[i]) farb(i);
    for(int i=1; i<=m; ++i) if(1==ma[a[i]][b[i]]) {
        viz&=0;
        gb=b[i];
        dfs(a[i]);
    }
    fout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); ++i) {
        fout<<sol[i].size()<<' ';
        for(int j=0; j<sol[i].size(); ++j) fout<<sol[i][j]<<' ';
        fout<<'\n';
    }
    return 0;
}
