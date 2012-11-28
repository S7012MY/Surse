#include <cstdio>
#include <queue>
#include <vector>
#include <bitset>
#define DN 355
#define MULT (1<<30)
#define mp make_pair
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int n,m,s,d,pre[DN],cp[DN][DN],rez;
double dist[DN];
vector<per> gr[DN];
bitset<DN> iq;

class cmp {
    public:
    inline bool operator()(const int &a,const int &b) {
        return dist[a]>dist[b];
    }
};

priority_queue<int,vector<int>,cmp > pq;

bool bf() {
    iq&=0;
    for(int i=1; i<=n; ++i) {
        pre[i]=-1;
        dist[i]=MULT;
    }
    pre[s]=dist[s]=0;
    for(pq.push(s);pq.size();) {
        int fr=pq.top();
        pq.pop();
        iq[fr]=0;
        for(it i=gr[fr].begin();i!=gr[fr].end(); ++i) {
            if(i->x==s) continue;
            if(cp[fr][i->x]>0 && dist[i->x]>dist[fr]+i->y) {
                pre[i->x]=fr;
                dist[i->x]=dist[fr]+i->y;
                if(!iq[i->x]) {
                    iq[i->x]=1;
                    pq.push(i->x);
                }
            }
        }
    }
    return dist[d]!=MULT;
}

int main()
{
    freopen("fmcm.in","r",stdin);
    freopen("fmcm.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&s,&d);
    int cst;
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        double d;
        scanf("%d %d %d %lfd",&a,&b,&c,&d);
        cp[a][b]=c;
        gr[a].push_back(mp(b,d));
        gr[b].push_back(mp(a,-d));
    }
    for(;bf();) {
        int cap=MULT,nc;
        for(nc=d;pre[nc];nc=pre[nc]) cap=min(cap,cp[pre[nc]][nc]);
        for(nc=d;pre[nc];nc=pre[nc]) {
            cp[pre[nc]][nc]-=cap;
            cp[nc][pre[nc]]+=cap;
        }
        rez+=cap*dist[d];
    }
    printf("%d",rez);
    for(int i=0; i<=n-1; ++i) for(int j=i+1; j<=n-1; ++j) if(cp[i][j]==0) {
        printf("%d %d\n",i,j);
    }
    return 0;
}
