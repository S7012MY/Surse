#include <cstdio>
#include <map>
#include <algorithm>
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
#define x first
#define y second
#define DN 305
using namespace std;

typedef pair<int, int> per;
int n,nrd,v[2*DN],sz,ai[6000],r,gls,gld;
per p[DN];
map<int, int> nr;

bool cmp(const per &a, const per &b) {
    return (a.y-a.x)<(b.y-b.x);
}

int update(int vn, int ls, int ld) {
    if(gls<=ls && gld>=ld) {
        if(ai[vn]) return 0;
        ai[vn]=1;
        return 1;
    }
    if(gld<ls || gls>ld) return 0;
    int m=(ls+ld)>>1,fs=vn<<1,r=0;
    if(gls<=m) r|=update(fs,ls,m);
    if(gld>=m) r|=update(fs+1,m+1,ld);
    if(ai[fs] && ai[fs+1]) ai[vn]=1;
    return r;
}

int main()
{
    freopen("maxviz.in","r",stdin);
    freopen("maxviz.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        scanf("%d %d",&p[i].x,&p[i].y);
        v[++sz]=p[i].x; v[++sz]=p[i].y;
    }
    sort(v+1,v+sz+1);
    for(int i=1; i<=sz; ++i) if(nr.find(v[i])==nr.end()) nr[v[i]]=++nrd;
    for(int i=1; i<=n; ++i) {
        p[i].x=nr[p[i].x];
        p[i].y=nr[p[i].y];
    }
    sort(p+1,p+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        bool ok=1;
        gls=p[i].x; gld=p[i].y;
        for(int i=gls; i<gld; ++i) {
            if(ok && 0==ai[i]) ++r,ok=0;
            ai[i]=1;
        }
    }
    printf("%d\n",r);
   // deb(r);
    return 0;
}
