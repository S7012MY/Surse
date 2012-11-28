#include <cstdio>
#include <algorithm>
#define DN 4005
using namespace std;

int n,k,s,rmin=9999999,fol[DN];
struct vf {
    int mv,sum,ind,vl;
} v[DN];

bool cmp(const vf &a,const vf &b) {
    return a.ind<b.ind;
}

inline void dfs(int s) {
    if(v[2*s].vl) dfs(2*s);
    if(v[2*s+1].vl) dfs(2*s+1);
    v[s].sum=v[2*s].sum+v[2*s+1].sum+v[s].vl;
    v[s].mv=max(v[s].vl,max(v[2*s].mv,v[2*s+1].mv));
}

inline void marc(int s) {
    fol[s]=1;
    if(2*s<=n && !fol[2*s]) marc(2*s);
    if(2*s+1<=n && !fol[2*s+1]) marc(2*s+1);
}


int main()
{
    freopen("recoltabin.in","r",stdin);
    freopen("recoltabin.out","r",stdout);
    scanf("%d %d %d",&n,&k,&s);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&v[i].vl);
        v[i].ind=i;
    }
    dfs(1);
    do {
        int sc=0,vs=0,sel=0;
        for(int i=0; i<=n; ++i) fol[i]=0;
        for(int i=1; i<=n && sel<k; ++i) if(!fol[i]) {
            sc+=v[i].sum;
            vs=max(vs,v[i].mv);
            if(sc>=s) break;
            marc(v[i].ind);
            ++sel;
        }
        if(sc>=s) rmin=min(rmin,vs);
    }while(next_permutation(v+1,v+n+1,cmp));
    int rez;
    fscanf(stdout,"%d",&rez);
    if(rez!=rmin) {
        fprintf(stderr,"gresit: %d %d",rez,rmin);
        while(1);
    }else fprintf(stderr,"corect\n");
    return 0;
}
