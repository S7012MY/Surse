#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#define DN 205
#define x first
#define y second
using namespace std;

typedef pair<double, double> per;
typedef vector<pair<int, double> >::iterator it;
int a,b,n;
double dist[DN],v1,v2,pre[DN];
per pct[DN];
vector<pair<int, double> > gr[DN];
bitset<DN> viz;
vector<int> sol;

class cmp {public:bool operator () (const int &a, const int &b) { return dist[a]>dist[b];}};
priority_queue<int, vector<int>, cmp> c;

double dst(per a, per b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void dijkstra() {
    for(c.push(0);c.size();c.pop()) {
        int mn=c.top();
        viz[mn]=0;
        for(it i=gr[mn].begin(); i!=gr[mn].end(); ++i) if(dist[i->x]>dist[mn]+i->y) {
            dist[i->x]=dist[mn]+i->y;
            pre[i->x]=mn;
            if(0==viz[i->x]) c.push(i->x),viz[i->x]=1;
        }
    }
}

int main()
{
    cin>>v1>>v2;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>pct[i].x>>pct[i].y;
    for(;;){
        int a,b;
        cin>>a>>b;
        if(0==a && 0==b) break;
        double cst=dst(pct[a],pct[b])/v2;
        gr[a].push_back(make_pair(b,cst));
        gr[b].push_back(make_pair(a,cst));
    }
    cin>>pct[0].x>>pct[0].y;
    cin>>pct[n+1].x>>pct[n+1].y;
    for(int i=0; i<=n+1; ++i)
        for(int j=i+1; j<=n+1; ++j) {
            double cst=dst(pct[i],pct[j])/v1;
            gr[i].push_back(make_pair(j,cst));
            gr[j].push_back(make_pair(i,cst));
        }
    for(int i=1; i<=n+1; ++i) dist[i]=99999999,pre[i]=i;
    dijkstra();
    //for(int i=1; i<=n+1; ++i) cout<<dist[i]<<' ';
    cout<<fixed<<setprecision(7)<<dist[n+1]<<'\n';
    for(int i=n+1;pre[i]!=i;sol.push_back(i),i=pre[i]);
    reverse(sol.begin(),sol.end());
    sol.pop_back();
    cout<<sol.size()<<' ';
    for(int i=0; i<sol.size(); ++i) cout<<sol[i]<<' ';
    return 0;
}
