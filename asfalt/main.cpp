#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>
#define DN 505
#define MULT 2000000000
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef set<int>::iterator is;
typedef vector<int>::iterator it;
typedef vector<per>::iterator ip;

bitset<DN> viz;
int n,m,s,d,fl[DN][DN],cp[DN][DN],dist[DN],pre[DN];
vector<per> gr[DN];
vector<int> g[DN];
set<int> gm[DN];
queue<int> c;

void dmin() {
    for(int i=1; i<=n; ++i) dist[i]=MULT;
    dist[s]=0;
    for(c.push(s);c.size();c.pop()) {
        int mn=c.front();
        for(ip i=gr[mn].begin(); i!=gr[mn].end(); ++i)
            if(dist[i->x]>dist[mn]+i->y) {
                dist[i->x]=dist[mn]+i->y;
                gm[i->x].clear();
                gm[i->x].insert(mn);
                c.push(i->x);
            }
            else if(dist[i->x]==dist[mn]+i->y) gm[i->x].insert(mn);
    }

    viz[d]=1;
    for(c.push(d);c.size(); c.pop()) {
        int fr=c.front();
        for(is i=gm[fr].begin(); i!=gm[fr].end(); ++i) {
            g[fr].push_back(*i);
            g[*i].push_back(fr);
            cp[*i][fr]=1;
            if(!viz[*i]){
                c.push(*i);
                viz[*i]=1;
            }
        }
    }
}

bool bfs() {
    viz&=0;
    pre[d]=-1;
    viz[s]=1;
    for(c.push(s);c.size();c.pop()) {
        int fr=c.front();
        for(it i=g[fr].begin(); i!=g[fr].end(); ++i)
            if(!viz[*i] && fl[fr][*i]<cp[fr][*i]) {
                viz[*i]=1;
                pre[*i]=fr;
                c.push(*i);
            }
    }
    return pre[d]!=-1;
}

int main()
{
    freopen("asfalt.in","r",stdin);
    freopen("asfalt.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&s,&d);
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        gr[a].push_back(make_pair(b,c));
        gr[b].push_back(make_pair(a,c));
    }
    dmin();

    int c=0;
    for(;bfs();) {
        ++c;
        for(int i=d; i!=s; i=pre[i]) {
            ++fl[pre[i]][i];
            --fl[i][pre[i]];
        }
    }

    printf("%d\n",c);
    for(int i=1; i<=n; ++i) for(it j=g[i].begin(); j!=g[i].end(); ++j)
        if(viz[i] && !viz[*j] && dist[i]<dist[*j])
            printf("%d %d\n",i,*j);
    return 0;
}
