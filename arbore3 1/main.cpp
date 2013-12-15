//Dedicatie pt Răzvan Sălăjan
#include <fstream>
#include <vector>
#include <list>
#define DN 1000005
#define MOD 3157
using namespace std;

typedef vector<int>::iterator it;
typedef vector<int>::iterator il;

vector<int> gr[DN],hs[MOD];

int n,x,S,vl[DN],rez;

void ins(int val,int ct) {
    int unde=val%MOD;
    if(unde<0) unde+=MOD;
    if(ct==1) {
        hs[unde].push_back(val);
        return ;
    }
    for(il i=hs[unde].begin(); i!=hs[unde].end();++i) if(*i==val) {
        hs[unde].erase(i);
        return;
    }
}

int find(int val) {
    int unde=val%MOD;
    if(unde<0) unde+=MOD;
    int rez=0;
    for(il i=hs[unde].begin(); i!=hs[unde].end();++i) if(*i==val) ++rez;
    return rez;
}

void dfs(int s,int sum) {
    sum+=vl[s];
    rez+=find(sum-S);
    ins(sum,1);
    for(int i=0;i<gr[s].size(); ++i) dfs(gr[s][i],sum);
    ins(sum,-1);
}

int main()
{
    ins(0,1);
    ifstream f("arbore3.in");
    ofstream g("arbore3.out");
    f>>n>>S;
    for(int i=1; i<=n; ++i) {
        f>>x>>vl[i];
        gr[x].push_back(i);
    }
    dfs(1,0);
    g<<rez;
    return 0;
}
