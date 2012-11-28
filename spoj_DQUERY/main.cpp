#include <cstdio>
#include <algorithm>
#include <iostream>
#define DN 30005
#define DK 1000005
#define DQ 200005
#define x first
#define y second
using namespace std;

typedef pair<int, int> per;
int n,nq,v[DN],ind[DQ],aib[DN],lst[DK],rez[DQ];
per q[DQ];

bool cmp(const int &a,const int &b) {
    return q[a].y<q[b].y;
}

inline int lsb(int a) {
    return a& -a;
}

inline void up(int x,int y) {
    if(0==x) return;
    for(;x<=n;x+=lsb(x)) aib[x]+=y;
}

inline int query(int x) {
    int r=0;
    for(;x;x-=lsb(x)) r+=aib[x];
    return r;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&v[i]);
    scanf("%d",&nq);
    for(int i=1; i<=nq; ++i) scanf("%d %d",&q[i].x,&q[i].y),ind[i]=i;
    sort(ind+1,ind+nq+1,cmp);
    for(int i=1,j=1; i<=nq; ++i) {
        for(;j<=q[ind[i]].y;++j) {
            up(lst[v[j]],-1);
            up(j,1);
            lst[v[j]]=j;
        }
        rez[ind[i]]=query(q[ind[i]].y)-query(q[ind[i]].x-1);
    }
    for(int i=1; i<=nq; ++i) printf("%d\n",rez[i]);
    return 0;
}
