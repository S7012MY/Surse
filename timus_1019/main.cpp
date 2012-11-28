#include <iostream>
#include <map>
#include <algorithm>
#define x first
#define y second.first
#define z second.second
#define DN 5005
using namespace std;

typedef pair<int,pair<int, char> > per;
int n,srt[2*DN],nre,gls,gld,cs,pcs=1,l[DN],r[DN],sz;//capat stanga;
per v[DN];
char ai[8*DN],tp;
map<int,int> norm;

void update(int vn, int ls, int ld) {
    if(gls<=ls && ld<=gld) {
        ai[vn]=tp;
        //st[vn]=dr[vn]=v[ls].x;
        return;
    }
    int m=(ls+ld)>>1,fs=vn<<1;
    if(gls<=m) update(fs,ls,m);
    if(m<gld) update(fs+1,m+1,ld);
    if(ai[fs]==ai[fs+1]) ai[vn]=ai[fs];
    else ai[vn]=0;
}

bool parc(int vn, int ls, int ld) {
    if(ai[vn]==tp) {
        return 1;
        cs=ld;
    }
    if(ls==ld) {
        cs=ld;
        return 1;
    }
    int m=(ls+ld)>>1,fs=vn<<1,ok=1;
    if(cs<=m) ok=parc(fs,ls,m);
    if(ok) ok=parc(fs+1,m+1,ld);
}

int main()
{
    ai[1]='w';
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>v[i].x>>v[i].y>>v[i].z;
        srt[2*i-1]=v[i].x;srt[2*i]=v[i].y;
    }
    sort(srt+1,srt+2*n+1);
    for(int i=1; i<=2*n; ++i) if(norm.find(srt[i])==norm.end()) norm[srt[i]]=++nre;
    for(int i=1; i<=n; ++i) {
        gls=norm[v[i].x];gld=norm[v[i].y];
        tp=v[i].z;
        update(1,1,n);
    }
    for(cs=1;cs<=2*n;) {
        tp='w';
        parc(1,1,n);
        l[++sz]=pcs;r[sz]=cs;
        tp='b';
        pcs=cs;
        if(cs>=n) break;
        parc(1,1,n);
    }
    for(int i=1; i<=sz; ++i) cout<<l[i]<<' '<<r[i]<<'\n';
    return 0;
}
