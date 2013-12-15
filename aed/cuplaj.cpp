#include <fstream>
#include <vector>
#include <bitset>
#define DN 20005
using namespace std;

typedef vector<int> graf[DN];
typedef vector<int>::iterator it;
graf gr;
int n,m,e,l[DN],r[DN],nrc,a,b;
bitset<DN> viz;

int cupleaza(int s) {
    if(viz[s]) return 0;
    viz[s]=1;
    for(it i=gr[s].begin(); i!=gr[s].end(); ++i) if(0==r[*i]||cupleaza(r[*i])) {
        l[s]=*i; r[*i]=s;
        return 1;
    }
    return 0;
}

int main()
{
    ifstream f("cuplaj.in");
    ofstream g("cuplaj.out");
    f>>n>>m>>e;
    for(int i=1; i<=e; ++i) {
        f>>a>>b;
        gr[a].push_back(b);
    }
    for(bool ok=1; ok;) {
        ok=0; viz&=0;
        for(int i=1; i<=n; ++i) if(0==l[i]) ok|=cupleaza(i);
    }
    for(int i=1; i<=n; ++i) nrc+=(0<l[i]);
    g<<nrc<<'\n';
    for(int i=1; i<=n; ++i) if(l[i]) g<<i<<' '<<l[i]<<'\n';
}

