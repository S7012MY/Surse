#include <iostream>
#include <vector>
#include <queue>
#define DN 1005
using namespace std;

typedef vector<int>::iterator it;
vector<int> gr[DN];
int n,rx[DN],ry[DN],viz[DN],dist[DN],cy=-998;
queue<int> c;

int main()
{
    cin>>n;
    for(int i=1; i<n; ++i) {
        int a,b;
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    rx[1]=-1000; ry[1]=-1000;
    for(c.push(1);c.size();c.pop()) {
        int fr=c.front();
        viz[fr]=1;
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(!viz[*i]) {
            c.push(*i);
            rx[*i]=rx[fr]+1; ry[*i]=cy;
            cy+=2;
        }
    }
    for(int i=1; i<=n; ++i) cout<<rx[i]<<' '<<ry[i]<<'\n';
    return 0;
}
