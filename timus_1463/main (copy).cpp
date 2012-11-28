#include <iostream>
#include <vector>
#include <bitset>
#define DN 50005
#define x first
#define y second
using namespace std;

typedef vector<pair<int,int> >::iterator it;
int n,k,a[DN],din[DN],nxt[DN],lg[DN];
vector<pair<int, int> > gr[DN];
bitset<DN> viz;

void dfs(int s) {
    viz[s]=1;
    //cout<<s<<' ';
    for(it i=gr[s].begin();i!=gr[s].end(); ++i) if(!viz[i->x]) {
        dfs(i->x);
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
        gr[0].push_back(make_pair(i,a[i]));
        if(a[i]>b) {
            b=a[i];
            ns=i;
        }
    }
    for(int i=1; i<=k; ++i) {
        int z,b,c;
        cin>>z>>b>>c;
        gr[z].push_back(make_pair(b,c+a[b]));
        gr[b].push_back(make_pair(z,c+a[z]));
    }
    dfs(0);
    cout<<din[0]<<'\n'<<lg[0]<<'\n';
    for(int i=0;nxt[i]!=0;i=nxt[i]) cout<<nxt[i]<<' ';

    return 0;
}
