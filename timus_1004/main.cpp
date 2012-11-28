#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <bitset>
#define DN 105
#define VM 9999999
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;
multiset<per> gr[DN];
bitset<DN> viz;
vector<int> sol,sc;
typedef multiset<per>::iterator it;
int n,m,bst,bi,bj,bk,v1[DN*DN],v2[DN*DN],v3[DN*DN],dist[DN],pr[DN];

class cmp {
public:
	inline bool operator() ( const int& x, const int& y ) { return dist[x]>dist[y]; }
};

priority_queue < int, vector< int >, cmp > hp;

void dijkstra(int s, int d) {
    dist[s]=0;
    for(hp.push(s);hp.size();hp.pop()) {
        int mn=hp.top();
        //viz[mn]=0;
        for(it i=gr[mn].begin(); i!=gr[mn].end();++i) {
            int n=i->x,cst=i->y;
            if(dist[n]>dist[mn]+cst) {
                dist[n]=dist[mn]+cst;
                pr[n]=mn;
                if(!viz[n]) {
                    hp.push(n);
                    viz[n]=1;
                }
            }
        }
    }
}

int main()
{
    for(cin>>n;n!=-1;cin>>n) {
        int bst=VM;
        cin>>m;
        for(int i=1; i<=n; ++i) gr[i].clear();
        for(int i=1; i<=m; ++i) {
            int a,b,c;
            cin>>a>>b>>c;
            v1[i]=a;v2[i]=b;v3[i]=c;
            gr[a].insert(make_pair(b,c));
            gr[b].insert(make_pair(a,c));
        }
        for(int i=1; i<=m; ++i) {
            viz&=0;
            for(int j=1; j<=n; ++j) {
                pr[j]=-1;
                dist[j]=VM;
            }
            int a=v1[i],b=v2[i],c=v3[i];
            gr[a].erase(make_pair(b,c));
            gr[b].erase(make_pair(a,c));
            dijkstra(a,b);
            if(bst>dist[b]+c && viz[b]) {
                sc.clear();
                int z=b;
                for(;pr[z]!=-1;sc.push_back(z),z=pr[z]);
                sc.push_back(z);
                if(sc.size()>2){
                    bst=dist[b]+c;
                    sol=sc;
                }
            }
            gr[a].insert(make_pair(b,c));
            gr[b].insert(make_pair(a,c));
        }
        if(bst==VM) cout<<"No solution.\n";
        else {
            for(int i=0; i<sol.size(); ++i) cout<<sol[i]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}
