#include <iostream>
#include <vector>
#define DN 50005
#define x first
#define y second
#pragma comment(linker, "/STACK:1000000000")
using namespace std;

typedef pair<int, int> per;
typedef vector<per>::iterator it;
int n,dist[DN],sz,eu[10*DN],d[10*DN],f[DN],gls,gld;
vector<per> gr[DN];
per rq,ai[20*DN];

void dfs(int s,int t,int niv) {
    eu[++sz]=s;
    d[sz]=niv;
    if(0==f[s]) f[s]=sz;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(i->x!=t) {
        dist[i->x]=dist[s]+i->y;
        dfs(i->x,s,niv+1);
        eu[++sz]=s;
        d[sz]=niv;
    }
}

void build(int vn, int ls, int ld) {
    if(ls==ld) {
        ai[vn].x=d[ls];
        ai[vn].y=eu[ls];
        return;
    }
    int fs=vn<<1,m=(ls+ld)>>1;
    build(fs,ls,m); build(fs+1,m+1,ld);
    ai[vn]=min(ai[fs],ai[fs+1]);
}

void query(int vn, int ls, int ld) {
    if(gld<ls || gls>ld) return;
    if(gls<=ls && ld<=gld) {
        rq=min(rq,ai[vn]);
        return;
    }
    int fs=vn<<1,m=(ls+ld)>>1;
    if(gls<=m) query(fs,ls,m);
    if(m<gld) query(fs+1,m+1,ld);
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
    dfs(1,-1,1);
    build(1,1,sz);
    for(cin>>n;n--;) {
        int a,b;
        rq.x=99999;
        cin>>a>>b;
        gls=min(f[a],f[b]); gld=max(f[a],f[b]);
        query(1,1,sz);
        //cout<<rq.y<<'\n';
        cout<<dist[a]+dist[b]-2*dist[rq.y]<<'\n';
    }
    return 0;
}
