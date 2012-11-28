//15:28
#include <iostream>
#include <fstream>
#include <algorithm>
#define DN 100005
#define MOD 666013
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
int n,k,m,v[DN],ind[DN],lst[DN],rez[DN];
long long aib[DN];
per q[DN];

bool cmp(const int &a, const int &b) {
    return q[a].y<q[b].y;
}

inline int lsb(int a) {
    return a & -a;
}

void up(int x, int y) {
    if(x==0) return;
    for(;x<=n;x+=lsb(x)) aib[x]+=y;
}

int query(int x) {
    long long r=0;
    for(;x;x-=lsb(x)) r+=aib[x];
    return r%MOD;
}

int main()
{
    ifstream f("distincte.in");
    ofstream g("distincte.out");
    f>>n>>k>>m;
    for(int i=1; i<=n; ++i) f>>v[i];
    for(int i=1; i<=m; ++i) f>>q[i].x>>q[i].y,ind[i]=i;
    sort(ind+1,ind+m+1,cmp);
    for(int i=1,j=1; i<=m; ++i) {
        for(;j<=q[ind[i]].y;++j) {
            up(lst[v[j]],-v[j]);//il scad pe v[j] din intervalul 1,lst[v[j]] ca sa-l adaug in intervalul 1,j
            up(j,v[j]);
            lst[v[j]]=j;
        }
        rez[ind[i]]=query(q[ind[i]].y)-query(q[ind[i]].x-1);
        if(rez[ind[i]]<0) rez[ind[i]]+=MOD;
    }
    for(int i=1; i<=m; ++i) g<<rez[i]<<'\n';
    return 0;
}
