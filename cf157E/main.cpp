#include <iostream>
#include <vector>
#include <bitset>
#define DN 100005
using namespace std;

typedef vector<int>::iterator it;

bitset<DN> viz;
int n,m,fs[DN*2],lst[DN*2],rez[DN],ai[4*DN],nr[4*DN],sz;
vector<int> gr[DN],leg[DN];

void dfs(int s) {
    viz[s]=1;
    fs[s]=++sz;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(!viz[*i]) dfs(*i);
    lst[s]=sz;
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<n; ++i) {
      int a,b;
      cin>>a>>b;
      gr[a].push_back(b);
      gr[b].push_back(a);
    }
    return 0;
}
