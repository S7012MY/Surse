#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define DN 50005
#define x first
#define y second
using namespace std;

typedef vector<pair<int,long long> >::iterator it;
long long n,k,a[DN],din[DN],nxt[DN],lg[DN];
vector<pair<int, long long> > gr[DN];

void dfs(int s, int f) {
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(i->x!=f) {
        dfs(i->x,s);
        if(din[s]<din[i->x]+i->y) {
            din[s]=din[i->x]+i->y;
            nxt[s]=i->x;
            lg[s]=lg[i->x]+1;
        }
    }
}

int main()
{
    cin>>n>>k;
    int b=0,ns=1;
    for(int i=1; i<=n; ++i) {
        cin>>a[i];
        if(a[i]>b) {
            b=a[i];
            //ns=i;
        }
    }
    srand(time(NULL));
    ns=rand()%n+1;
    for(int i=1; i<=k; ++i) {
        int z,b,c;
        cin>>z>>b>>c;
        gr[z].push_back(make_pair(b,c+a[b]));
        gr[b].push_back(make_pair(z,c+a[z]));
    }
    dfs(ns,0);
    for(int i=ns;i!=0;i=nxt[i]) ns=i;
    for(int i=1; i<=n; ++i) nxt[i]=din[i]=lg[i]=0;
    dfs(ns,0);
    cout<<din[ns]+a[ns]<<'\n'<<lg[ns]+1<<'\n';
    for(int i=ns;i!=0;i=nxt[i]) cout<<i<<' ';

    return 0;
}
