#include <iostream>
#include <vector>
#define DN 105
using namespace std;

typedef vector<int>::iterator it;
int n,col[DN],ok;
vector<int> gr[DN];

void dfs(int s, int c) {
    col[s]=c;
    for(it i=gr[s].begin(); i!=gr[s].end();++i) {
        if(0==col[*i]) dfs(*i,3-c);
        if(col[*i]!=3-col[s]) ok=1;
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        int nc;
        for(cin>>nc;nc;cin>>nc) gr[i].push_back(nc),gr[nc].push_back(i);
    }
    col[1]=1;
    dfs(1,1);
    if(ok) cout<<-1;
    else for(int i=1; i<=n; ++i) cout<<col[i]-1<<' ';
    return 0;
}
