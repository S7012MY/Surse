#include <iostream>
#include <iomanip>
#include <vector>
#define DN 50005
#define x first
#define y second
#pragma comment(linker, "/STACK:16777216")
using namespace std;

typedef pair<int, int> per;
typedef vector<per>::iterator it;

int n,nrf[DN];
double st;
vector<per> gr[DN];

void dfs(int &s, int &f) {
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(i->x!=f) {
        dfs(i->x,s);
        nrf[s]+=nrf[i->x];
    }
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(i->x!=f) {
        st+=(i->y*1LL*(1LL*nrf[i->x]*(n*1LL-nrf[i->x])));
    }
    ++nrf[s];
    //cout<<s<<' '<<nrf[s]<<'\n';
}

int main()
{
    cin>>n;
    for(int i=1; i<n; ++i) {
        int a,b,c;
        cin>>a>>b>>c;
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
    }
    int a=1,b=0;
    dfs(a,b);
    //cout<<st<<'\n';
    cout<<fixed<<setprecision(4)<<2*st/((double)n*(n-1));
    return 0;
}
