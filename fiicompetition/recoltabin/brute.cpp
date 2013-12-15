#include <cstdio>
#include <algorithm>
#define DN 9005
using namespace std;

int n,k,s,rmin=9999999,fol[DN],val[DN];
struct vf {
    int mv,sum,ind,vl;
} v[DN];

bool cmp(const vf &a,const vf &b) {
    return a.ind<b.ind;
}

inline void dfs(int s) {
    if(2*s<=n) dfs(2*s);
    if(2*s+1<=n) dfs(2*s+1);
    v[s].sum=v[2*s].sum+v[2*s+1].sum+v[s].vl;
    v[s].mv=max(v[s].vl,max(v[2*s].mv,v[2*s+1].mv));
}

inline int compute(int s) {
	int ret=0;
	fol[s]=1;
	if(2*s<=n && !fol[2*s]) ret+=compute(2*s);
	if(2*s+1<=n && !fol[2*s+1]) ret+=compute(2*s+1);
	return ret+val[s];
}

int main()
{
    freopen("recoltabin.in","r",stdin);
    freopen("recoltabin.out","r",stdout);
    scanf("%d %d %d",&n,&k,&s);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&v[i].vl);
	val[i]=v[i].vl;
        v[i].ind=i;
    }
    dfs(1);
    do {
        int sc=0,vs=0,sel=0;
        for(int i=0; i<=n; ++i) fol[i]=0;
        for(int i=1; i<=n && sel<k; ++i) if(!fol[v[i].ind]) {
            sc+=compute(v[i].ind);
            vs=max(vs,v[i].mv);
            if(sc>=s) break;
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
