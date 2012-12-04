#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#define DN 2005
#define DK 20
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int n,m,k,snod[DK],unde[DK],dmin[DK][DK],dist[DN];
vector<per> gr[DN];
queue<int> c;
bitset<DN> inq;

void dm(int s) {
    for(int i=1; i<=n; ++i) dist[i]=(1<<30);
    dist[snod[s]]=0;
    for(c.push(snod[s]);c.size();c.pop()) {
        int fr=c.front();
        inq[fr]=0;
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(dist[i->x]>dist[s]+i->y) {
            dist[i->x]=dist[s]+i->y;
            if(!inq[i->x]) {
                c.push(i->x);
                inq[i->x]=1;
            }
        }
    }
    for(int i=1; i<=n; ++i) cout<<dist[i]<<' ';
    cout<<'\n';
    for(int i=1; i<=n; ++i) if(unde[i]) dmin[s][unde[i]]=dist[i];
}

int main()
{
    ifstream f("ubuntzei.in");
    ofstream g("ubuntzei.out");
    f>>n>>m>>k;
    ++k;
    for(int i=2; i<=k; ++i) {
        f>>snod[i];
        unde[snod[i]]=i;
    }
    snod[1]=unde[1]=1;unde[1]=1; snod[++k]=n;unde[n]=k;
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        gr[a].push_back(mp(b,c));
        gr[b].push_back(mp(a,c));
    }
    for(int i=1; i<=k; ++i) dm(i);
    /*for(int i=1; i<=k; ++i) {
        for(int j=1; j<=k; ++j) cout<<dmin[i][j]<<' ';
        cout<<'\n';
    }*/
    return 0;
}
