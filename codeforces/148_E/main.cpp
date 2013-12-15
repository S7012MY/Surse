#include <iostream>
#include <bitset>
#include <vector>
#define DN 3005
using namespace std;

typedef vector<int>::iterator it;
vector<int> gr[DN],arb[DN];

int n,acc[DN],snod;
bitset<DN>viz,ma[DN],marc;

void ac(int s,int f) {
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
        if(!viz[*i]) ac(*i,s);
        if(*i!=f) acc[s]+=acc[*i];
    }
    ++acc[s];
   // cerr<<s<<' '<<f<<' '<<acc[s]<<'\n';
}

void mr(int s) {
    marc[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!marc[*i]) mr(*i);
}

int nfii(int s,int f) {
    int r=0;
    if(!marc[s]) ++r;
    for(it i=arb[s].begin(); i!=arb[s].end(); ++i) if(*i!=f) r+=nfii(*i,s);
    return r;
}

void dfs(int s) {
    viz[s]=1;
    for(it i=arb[s].begin(); i!=arb[s].end(); ++i) if(!viz[*i] && nfii(*i,s)) {
        if(!ma[s][*i]) ++snod;
        dfs(*i);
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<n; ++i) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        arb[a].push_back(b);
        arb[b].push_back(a);
        ma[a][b]=1;
    }
    for(int i=1; i<=n; ++i) if(!viz[i]) ac(i,-1);
    int bnod=0,nod;
    for(int i=1; i<=n; ++i) if(acc[i]>bnod){
        bnod=acc[i];
        nod=i;
    }
    mr(nod);
   // for(int i=1; i<=n; ++i) cerr<<marc[i]<<' ';
    //cerr<<'\n'<<nod<<' '<<nfii(4,1)<<'\n';
    int sol=(1<<30);
    for(int i=1; i<=n; ++i) {
        viz&=0;
        snod=0;
        dfs(i);
        sol=min(sol,snod);
       // cerr<<i<<' '<<snod<<'\n';
    }
    cout<<sol;
    return 0;
}
