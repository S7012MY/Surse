#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#define MULT 2000000000
#define DN 100005
#define x first
#define y second
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;
typedef set<per>::iterator is;
int n,a,b,dist[DN],v[DN],sp[DN];
vector<per> gr[DN];
bitset<DN> viz;
set<per>s;

class cmp {
    public:
        bool operator () (const int &a,const int &b) {return dist[a]>dist[b];}
};
priority_queue<int,vector<int>,cmp> q;

void dijkstra() {
    for(q.push(0);q.size(); q.pop()) {
        int mn=q.top();viz[mn]=0;
        for(it i=gr[mn].begin(); i!=gr[mn].end(); ++i) {
            int n=i->x,cst=i->y;
            if(dist[n]>dist[mn]+cst) {
                dist[n]=dist[mn]+cst;
                if(!viz[n]) {
                    q.push(n);
                    viz[n]=1;
                }
            }
        }
    }
}

void brute() {
    for(int i=1; i<=n; ++i) {
            dist[i]=MULT;
            scanf("%d",&v[i]);
            sp[i]=sp[i-1]+v[i];
            gr[i-1].push_back(make_pair(i,v[i]));
        }
        for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) if(sp[j]-sp[i-1]>a && sp[j]-sp[i-1]<=b)
            gr[i-1].push_back(make_pair(j,a));
        dijkstra();
}

void cazpart() {
    int lst=1;
    for(int i=1; i<=n; ++i) {
        dist[i]=MULT;
        sp[i]=sp[i-1]+v[i];
        gr[i-1].push_back(make_pair(i,v[i]));
    }
    for(int i=1; i<=n; ++i) {
        for(int j=lst; j<=n; ++j) if(sp[j]-sp[i-1]>b) {
            lst=j-1;
            break;
        }
        if(sp[lst]-sp[i-1]>a && sp[lst]-sp[i-1]) gr[i-1].push_back(make_pair(lst,a));
    }
    dijkstra();
}

int main()
{
    freopen("ripstick.in","r",stdin);
    freopen("ripstick.out","w",stdout);
    scanf("%d %d %d",&n,&a,&b);
   //if(n<=1000) {
   //     brute();
   // }else {
        //dist=bst
        int qst=a,qdr=b,vins=0,tp=1;
        is lb,ub;

        for(int i=1; i<=n; ++i) {
            scanf("%d",&v[i]);
            if(v[i]<0) tp=0;
        }
    /*    if(tp) {
            cazpart();
            printf("%d\n",dist[n]);
            return 0;
        }*/
        dist[1]=v[1];
        s.insert(make_pair(v[1],0));
        for(int i=2; i<=n; ++i) {
            qst-=v[i]; qdr-=v[i]; vins+=v[i];

            int vl=dist[i-1]+v[i];
            lb=s.lower_bound(make_pair(qst,-MULT));
            ub=s.upper_bound(make_pair(qdr,MULT));
            if(ub->x==qdr) ++ub;
            for(is iz=lb; iz!=ub; ++iz) vl=min(vl,iz->y+a);

            dist[i]=vl;
           // deb(vl)
           // deb(qst) deb(qdr) deb(v[i]-vins) debnl
           s.insert(make_pair(v[i]-vins,dist[i-1]));
        }
   // }
    printf("%d\n",dist[n]);
    return 0;
}
