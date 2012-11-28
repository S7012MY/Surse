#include <iostream>
#include <vector>
#include <queue>
#define DN 100005
#define MULT 999999
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef vector<int>::iterator it;
vector<int> gr[DN],sol;
int n,lg[DN],target,pre[DN],d[DN],dest,dmin=MULT;
per p[DN];
queue<int> c;

int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>p[i].x>>p[i].y,d[i]=MULT,pre[i]=i;
    cin>>target>>p[n+1].x>>p[n+1].y;
    d[n+1]=1;
    pre[n+1]=n+1;
    for(int i=1; i<=n+1; ++i) for(int j=1; j<=n+1; ++j)
        if(i!=j && p[i].x==p[j].x || p[i].y==p[j].x) gr[i].push_back(j);
    for(c.push(n+1);c.size();c.pop()) {
        int fr=c.front();
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(d[*i]>d[fr]+1) {
            d[*i]=d[fr]+1;
            pre[*i]=fr;
            c.push(*i);
        }
    }
    for(int i=1; i<=n; ++i) if((p[i].x==target || p[i].y==target) && dmin>d[i]) {
        dest=i;
        dmin=d[i];
    }
    if(dmin==MULT) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=dest;pre[i]!=i;sol.push_back(i),i=pre[i]);
    cout<<sol.size()<<'\n';
    for(int i=sol.size()-1; 0<=i; --i) cout<<sol[i]<<'\n';
    return 0;
}
