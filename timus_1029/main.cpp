#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <cstring>
#include <algorithm>
#define DN 505
#define MULT (1LL<<62LL)
#define x first
#define y second
using namespace std;

typedef pair<int, long long> per;
typedef vector<per>::iterator it;
int n,m,pre[DN*DN];
long long mi[DN][DN],dist[DN*DN];
vector<per> gr[DN*DN];
vector<int>sol;
bitset<DN*DN> viz;

class cmp {
public:
        inline bool operator() ( const int& x, const int& y ) { return dist[x]>dist[y]; }
};

priority_queue<int,vector<int>, cmp> hp;

int mn(int a,int b) {
    return m*(a-1)+b;
}

void dijkstra(){
    for(int i=0; i<=m*n; ++i) dist[i]=MULT;
    dist[0]=0;
    for(hp.push(0);hp.size();hp.pop()) {
        int mn=hp.top();
        for(it i=gr[mn].begin(); i!=gr[mn].end(); ++i) {
            int n=i->x,cst=i->y;
            if(dist[n]>dist[mn]+cst) {
                dist[n]=dist[mn]+cst;
                pre[n]=mn;
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
    cin>>n>>m;
    for(int i=0; i<=m*n; ++i) pre[i]=i;
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) cin>>mi[i][j];
    for(int i=1; i<=m; ++i) gr[0].push_back(make_pair(i,mi[1][i]));
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) {
        if(i>1) gr[mn(i-1,j)].push_back(make_pair(mn(i,j),mi[i][j]));
        if(j>1) gr[mn(i,j-1)].push_back(make_pair(mn(i,j),mi[i][j]));
        if(j<m) gr[mn(i,j+1)].push_back(make_pair(mn(i,j),mi[i][j]));
    }
   // for(it i=gr[1].begin(); i!=gr[1].end(); ++i) cout<<i->x<<' '<<i->y<<'\n';
    dijkstra();
    long long bst=MULT;
    int bn;
    for(int i=1; i<=m; ++i) if(bst>dist[mn(n,i)]) {
        bst=dist[mn(n,i)];
        bn=mn(n,i);
    }
    for(;bn!=pre[bn];sol.push_back(bn),bn=pre[bn]);
    reverse(sol.begin(),sol.end());
    for(int i=0; i<sol.size(); ++i) {
        if(sol[i]%m!=0) cout<<sol[i]%m<<' ';
        else cout<<m<<' ';
    }
    //cout<<bst;
    return 0;
}
