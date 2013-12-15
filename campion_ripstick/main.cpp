#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#define MULT 2000000000
#define DN 100005
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

typedef set<int>::iterator is;

int n,v[DN],A,B,unde[DN],final[DN],bst[DN],qst,qdr;
set<int> s;
map<int, int> ct;

bool cmp(const int &a, const int &b) {
    return final[a]<final[b];
}

int mv[4*DN];

void insert(int p, int vl, int vn=1, int ls=1, int ld=n) {
    if(ls==ld) {
        mv[vn]=vl;
        return;
    }
    int m=(ls+ld)>>1,fs=vn<<1;
    if(p<=m) insert(p,vl,fs,ls,m);
    else insert(p,vl,fs+1,m+1,ld);
    mv[vn]=min(mv[fs],mv[fs+1]);
}

int query(int gls, int gld, int vn=1, int ls=1, int ld=n) {
    if(gls<=ls && ld<=gld) return mv[vn];
    int m=(ls+ld)>>1,fs=vn<<1,ret=MULT;
    if(gls<=m) ret=query(gls,gld,fs,ls,m);
    if(gld>m) ret=min(ret,query(gls,gld,fs+1,m+1,ld));
    return ret;
}

int main()
{
    freopen("ripstick.in","r",stdin);
    freopen("ripstick.out","w",stdout);
    scanf("%d %d %d",&n,&A,&B);
    for(int i=1; i<=4*n; ++i) mv[i]=MULT;
    for(int i=1; i<=n; ++i) {
        scanf("%d",&v[i]);
        unde[i]=i;
    }
    final[1]=bst[1]=v[1];
    int vins=0;
    for(int i=2; i<=n; ++i) {
        vins+=v[i];
        final[i]=v[i]-vins;
    }
    sort(unde+1,unde+n+1,cmp);
    for(int i=1; i<=n; ++i) ct[final[unde[i]]]=i;

    vins=0;
    insert(unde[1],0);
    s.insert(v[1]);
    int qst=A,qdr=B,gls,gld;
    is lb,ub;

    for(int i=2; i<=n; ++i) {
        qst-=v[i]; qdr-=v[i]; vins+=v[i];

        int vl=bst[i-1]+v[i];

        lb=s.lower_bound(qst);
        ub=s.upper_bound(qdr);
        if(ub==s.end() || *ub>qdr) --ub;
        if(lb==s.end() || *lb>qdr || *ub<qst) {
            bst[i]=vl;
            s.insert(final[i]);
            insert(unde[i],bst[i-1]);
            continue;
        }
        gls=ct[*lb],gld=ct[*ub];
        if(gls>gld) swap(gls,gld);
        bst[i]=min(vl,query(gls,gld)+A);

        insert(unde[i],bst[i-1]);
        s.insert(final[i]);
    }

    //for(int i=1; i<=n; ++i) deb(bst[i])
    printf("%d\n",bst[n]);
    return 0;
}
