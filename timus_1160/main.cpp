#include <iostream>
#include <algorithm>
#define DN 1005
using namespace std;

int n,m,a[DN*DN],b[DN*DN],c[DN*DN],ind[DN*DN],pre[DN],sa[DN],sb[DN],sz,mc;

bool cmp(const int &a,const int &b) {
    return c[a]<c[b];
}

int find(int a) {
    if(pre[a]==a) return a;
    pre[a]=find(pre[a]);
    return pre[a];
}

void unite(int a, int b) {
    pre[find(a)]=find(b);
}

int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i) pre[i]=i;
    for(int i=1; i<=m; ++i) {
        cin>>a[i]>>b[i]>>c[i];
        ind[i]=i;
    }
    sort(ind+1,ind+m+1,cmp);
    for(int i=1; i<=m; ++i) if(find(a[ind[i]])!=find(b[ind[i]])) {
        mc=c[ind[i]];
        unite(a[ind[i]],b[ind[i]]);
        sa[++sz]=a[ind[i]];
        sb[sz]=b[ind[i]];
    }
    cout<<mc<<'\n'<<sz<<'\n';
    for(int i=1; i<=sz;++i) cout<<sa[i]<<' '<<sb[i]<<'\n';
    return 0;
}
