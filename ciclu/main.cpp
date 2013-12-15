#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <bitset>
#define DN 1005
#define EPS 1e-10
#define VM 2000000
#define x first
#define y second
using namespace std;

typedef vector<pair<int, int> > graf[DN];
typedef vector<pair<int, int> >::iterator it;
graf g;
int n,m;
bitset<DN> viz;

static int bf(int cst) {
    graf gr=g;
    int a[DN],dst[DN];
    viz&=0;
    for(int i=0; i<=n; ++i) {
        dst[i]=VM*100;
        a[i]=0;
        for(it j=gr[i].begin(); j!=gr[i].end(); ++j)
            j->y-=cst;
    }
    queue<int> c;
    dst[0]=0;
    for(c.push(0);c.size(); c.pop()) {
        int fr=c.front();
        viz[fr]=0;
        for(it i=gr[fr].begin(); i!=gr[fr].end(); ++i)
            if(dst[i->x]>dst[fr]+i->y) {
                dst[i->x]=dst[fr]+i->y;
                if(0==viz[i->x]) {
                    viz[i->x]=1;
                    if(a[i->x]>n) return 1;
                    ++a[i->x];
                    c.push(i->x);
                }
            }
    }
    return 0;
}
int main()
{
    ifstream f("ciclu.in");
    ofstream go("ciclu.out");
    f>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        g[a].push_back(make_pair(b,c*100));
    }
    for(int i=1; i<=n; ++i) g[0].push_back(make_pair(i,0));
    int ls=-VM,ld=VM,m;
    for(;ls<=ld;) {
        m=(ls+ld)/2;
        if(bf(m)) ld=m-1;
        else ls=m+1;
    }
    go<<fixed<<setprecision(2)<<0.01*m-0.01;
    return 0;
}
