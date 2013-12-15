#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#define DN 1005
#define EPS 1e-10
#define VM 100000
using namespace std;

typedef vector<pair<int, int> > graf[DN];
typedef vector<pair<int, int> >::iterator it;
graf gr;
int n,m;

static int bf(double cst) {
    double a[DN];
    memset(a,0,sizeof(a));
    for(int s=0; s<n; ++s) for(int i=1; i<=n; ++i) for(it j=gr[i].begin(); j!=gr[i].end(); ++j)a[(*j).first]=min(a[(*j).first],a[i]+(*j).second-cst);
    for(int i=1; i<=n; ++i) for(it j=gr[i].begin(); j!=gr[i].end(); ++j) if (a[(*j).first]>a[i]+(*j).second-cst+EPS) return 1;
    return 0;
}
int main()
{
    ifstream f("ciclu.in");
    ofstream g("ciclu.out");
    f>>n>>m;
    for(int i=1; i<=m; ++i) {
        int a,b,c;
        f>>a>>b>>c;
        gr[a].push_back(make_pair(b,c));
    }
    double ls=-VM,ld=VM,m;
    for(;ls+1e-6<ld;)
        if (bf(m=0.5*(ls+ld))) ld=m;
        else ls=m;
    g<<fixed<<setprecision(2)<<0.5*(ls+ld);
    return 0;
}
