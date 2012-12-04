#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#define DN 2005
#define DK 20
#define MLT 2000000000
#define x first
#define y second
#define mp make_pair
using namespace std;

typedef pair<int,int> per;
typedef vector<per>::iterator it;

int n,m,k,snod[DK],unde[DN],dmin[DK][DK],dist[DN],bst[DK][1<<DK];
vector<per> gr[DN];
queue<int> c;
bitset<DN> inq;

void dm(int s) {
    for(int i=1; i<=n; ++i) dist[i]=MLT;
    dist[snod[s]]=0;
    for(c.push(snod[s]);c.size();c.pop()) {
        int fr=c.front();
        inq[fr]=0;
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i) if(dist[i->x]>dist[fr]+i->y) {
            dist[i->x]=dist[fr]+i->y;
            if(!inq[i->x]) {
                c.push(i->x);
                inq[i->x]=1;
            }
        }
    }
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
    snod[1]=unde[1]=1; snod[++k]=n; unde[n]=k;
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        gr[a].push_back(mp(b,c));
        gr[b].push_back(mp(a,c));
    }
    for(int i=0; i<=k; ++i) for(int j=0; j<=k; ++j) dmin[i][j]=MLT;

    for(int i=1; i<=k; ++i) {
        dm(i);
        for(int s=0; s<=(1<<k); ++s) bst[i-1][s]=MLT;
    }

    bst[0][1]=0;
    --k;
    for(int s=1; s<(1<<k); ++s) for(int i=0; i<k; ++i) if(s&(1<<i))
        for(int j=0; j<k; ++j) if(!(s&(1<<j))) {
            bst[j][s|(1<<j)]=min(bst[j][s|(1<<j)],bst[i][s]+dmin[i+1][j+1]);
        }
    int rez=MLT;
    for(int i=0; i<k; ++i) rez=min(rez,bst[i][(1<<k)-1]+dmin[i+1][k+1]);
    cout<<rez;
    g<<rez;
    return 0;
}
