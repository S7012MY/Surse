#include <queue>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
#define DM 55
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

typedef vector<int>::iterator it;

int m,n,cut[DM][DM],dist[DM],s2,dmax,pre[DM];
vector<int> gr[DM],rez;
bitset<DM> viz;
queue<int> c;

bool sp(int a, int b) {//b incape in a
    for(int i=1; i<=n; ++i) if(cut[b][i]>=cut[a][i]) return 0;
    return 1;
}

void bfs(int s) {
    for(int i=1; i<=m; ++i) dist[i]=pre[i]=0;
    for(c.push(s);c.size(); c.pop()) {
        int fr=c.front();
        viz[fr]=1;
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(dist[*i]<dist[fr]+1) {
            dist[*i]=dist[fr]+1;
            pre[*i]=fr;
            c.push(*i);
        }
    }
}

int main()
{
    freopen("cutii.in","r",stdin);
    freopen("cutii.out","w",stdout);
    for(;scanf("%d %d",&m,&n)!=-1;) {
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) scanf("%d",&cut[i][j]);
            dist[i]=0;
            gr[i].clear();
            sort(cut[i]+1,cut[i]+n+1);
        }
        for(int i=1; i<=m; ++i) for(int j=1; j<=m; ++j) if(sp(i,j)) gr[j].push_back(i);

        dmax=-1;
        for(int i=1; i<=m; ++i) {//bfs din fiecare nod
            viz&=0;
            bfs(i);
            s2=-1;
            for(int j=1; j<=m; ++j) if(dmax<dist[j] && viz[j]) {
                dmax=dist[j];
                s2=j;
            }
            if(s2!=-1) {
                rez.clear();
                for(;s2;s2=pre[s2]) rez.push_back(s2);
            }
        }

        reverse(rez.begin(),rez.end());
        printf("%d\n",rez.size());
        for(int i=0; i<rez.size(); ++i) printf("%d ",rez[i]);
        printf("\n");
    }
    for(int i=1; i<=m; ++i) for(int j=1; j<=m; ++j) if(sp(i,j)) gr[j].push_back(i);
    return 0;
}
