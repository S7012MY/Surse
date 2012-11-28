#include <iostream>
#include <vector>
#include <bitset>
#define DN 1005
using namespace std;

typedef vector<int>::iterator it;
vector<int> gr[DN],gt[DN];
int n,m,ok=1;
bitset<DN> viz;

void dfs(int s) {
    for(it i=gt[s].begin(); i!=gt[s].end(); ++i) if(!viz[*i]) {
        ok=0;
        return;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<m; ++i) {
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gt[y].push_back(x);
    }
    for(int i=0; i<n; ++i) {
        int x;
        cin>>x;
        viz[x]=1;
        dfs(x);
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
    return 0;
}
