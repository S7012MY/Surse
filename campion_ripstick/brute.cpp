#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <fstream>
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

int main()
{
    freopen("ripstick.in","r",stdin);
    ifstream f("ripstick.out");
    int rez;
    f>>rez;
    scanf("%d %d %d",&n,&a,&b);
    brute();
    if(dist[n]!=rez) {
	fprintf(stderr,"GRESIT!");
	while(1);
    }
    return 0;
}
