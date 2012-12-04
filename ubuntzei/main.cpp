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

int n,m,k,snod[DK],unde[DK],dmin[DK][DK];
vector<per> gr[DN];
queue<int> c;

void dm(int s) {
    for(int i=1; i<=n; ++i) dmin[s][i]=(1<<30);
    for(c.push(snod[s]);c.size();c.pop()) {
        int fr=c.front();
        for
    }
}

int main()
{
    ifstream f("ubuntzei.in");
    ofstream g("ubuntzei.out");
    f>>n>>m>>k;
    for(int i=1; i<=k; ++i) {
        f>>snod[i];
        unde[snod[i]]=i;
    }
    snod[0]=1; snod[++k]=n;unde[n]=k;
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        gr[a].push_back(mp(b,c));
        gr[b].push_back(mp(a,c));
    }
    for(int i=0; i<=k; ++i) dm(i);
    return 0;
}
