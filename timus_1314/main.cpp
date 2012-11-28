#include <iostream>
#include <vector>
#include <queue>
#define DN 33000
using namespace std;

typedef vector<int>::iterator it;

vector<int> gr[DN];
int n,k,a,b,dst[DN],cine[DN];
queue<int> c;

void bfs(int s) {
    dst[s]=1;
    cine[s]=s;
    for(c.push(s);c.size(); c.pop()) {
        int fr=c.front();
        for(it i=gr[fr].begin();i!=gr[fr].end(); ++i)
            if(0==dst[*i] || dst[*i]>dst[fr]+1) {
                dst[*i]=dst[fr]+1;
                cine[*i]=s;
                c.push(*i);
            }
    }
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>k;
        cin>>a;
        for(int i=2; i<=k; ++i) {
            cin>>b;
            gr[a].push_back(b);
            gr[b].push_back(a);
            a=b;
        }
    }
    cin>>k;
    for(int i=1; i<k; ++i) {
        cin>>a;
        bfs(a);
    }
    cin>>a;
    bfs(a);
    for(int i=1; i<DN; ++i) if(cine[i]==a) cout<<i<<'\n';
    return 0;
}
