#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <bitset>
#define DN 55
using namespace std;

typedef vector<int>::iterator it;

vector<int> gr[DN];
int n,m,rez[DN*DN],cnt;
map<pair<int, int>, int> mp;
bitset<DN*DN> viz;

void dfs(int s) {
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) {
        int x=s,y=*i;
        if(x>y) swap(x,y);
        if(!viz[mp[make_pair(x,y)]]) {
            viz[mp[make_pair(x,y)]]=1;
            rez[mp[make_pair(x,y)]]=++cnt;
            dfs(*i);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; ++i) {
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        mp[make_pair(x,y)]=i;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    dfs(1);
    cout<<"YES\n";
    for(int i=1; i<=m; ++i) cout<<rez[i]<<' ';
    return 0;
}
