#include <fstream>
#include <vector>
#define DN 100005
#define x first
#define y second
using namespace std;

typedef pair<int,int> per;

int d,dx,dy,n,scv[4*DN],smax[4*DN],bst[DN],rez,VM;
per p[DN];

inline int max(int a, int b) {
    if(a>b) return a;
    return b;
}

inline void update(int vn, int ls, int ld,int gls, int gld,int vl) {
    //cout<<vn<<' '<<ls<<' '<<ld<<' '<<gls<<' '<<gld<<' '<<vl<<'\n';
    if(ld<gls || ls>gld) return;
    if(gls<=ls && ld<=gld) {
        scv[vn]+=vl;
        smax[vn]+=vl;
        return;
    }
    int fs=(vn<<1),m=(ls+ld)>>1;
    if(gls<=m) update(fs,ls,m,gls,gld,vl);
    if(m<gld) update(fs+1,m+1,ld,gls,gld,vl);
    smax[vn]=max(smax[fs],smax[fs+1])+scv[vn];
}

void fa(int dx,int dy) {
    vector<int> poz[DN];
    for(int i=1; i<=n; ++i) poz[p[i].x].push_back(p[i].y);
    for(int i=0; i<=VM; ++i) {
        for(int j=0; j<poz[i].size(); ++j) update(1,1,VM,poz[i][j],poz[i][j]+dy-1,1);
        if(i-dx>=0)
            for(int j=0; j<poz[i-dx].size(); ++j) update(1,1,VM,poz[i-dx][j],poz[i-dx][j]+dy-1,-1);

        bst[i]=max(bst[i-1],smax[1]);
        //if(i<10) cout<<i<<' '<<bst[i]<<'\n';
    }
    for(int i=1; i<=4*VM; ++i) smax[i]=scv[i]=0;
    int rsus=0;
    for(int i=VM; i>=0; --i) {
        for(int j=0; j<poz[i].size(); ++j) update(1,1,VM,poz[i][j],poz[i][j]+dy-1,1);
        if(i+dx<=VM)
            for(int j=0; j<poz[i+dx].size(); ++j) update(1,1,VM,poz[i+dx][j],poz[i+dx][j]+dy-1,-1);
        rsus=max(rsus,smax[1]);
        rez=max(rez,bst[i-1]+rsus);
        bst[i]=0;
        //if(i<10) cout<<i<<' '<<smax[1]<<'\n';
    }
    for(int i=1; i<=4*VM; ++i) smax[i]=scv[i]=0;
}

int main()
{
    ifstream f("parcele.in");
    ofstream g("parcele.out");
    f>>dx>>dy>>n;
    ++dx; ++dy;
    for(int i=1; i<=n; ++i) {
        f>>p[i].x>>p[i].y;
        VM=max(VM,p[i].x);
        VM=max(VM,p[i].y);
    }
    fa(dx,dy);
    for(int i=1; i<=n; ++i) swap(p[i].x,p[i].y);
    fa(dy,dx);

    g<<rez;
    return 0;
}
