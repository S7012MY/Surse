#include <cstdio>
#include <algorithm>
#define DN 9005
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
using namespace std;

struct vf {
    int mv,sum,ind;
} v[DN],cpv[DN];

bool cmp(const vf &a,const vf &b) {
    if(a.mv==b.mv) return a.sum>b.sum;
    return a.mv<b.mv;
}

bool cmp2(const vf &a, const vf &b) {
    return a.sum>b.sum;
}

int n,k,s,val[DN],sum[DN],maxval[DN],fol[DN];

inline void dfs(int s) {
    if(val[2*s]) dfs(2*s);
    if(val[2*s+1]) dfs(2*s+1);
    sum[s]=val[s]+sum[2*s]+sum[2*s+1];
    maxval[s]=max(val[s],max(maxval[2*s],maxval[2*s+1]));
}

inline void marc(int s) {
    fol[s]=1;
    if(val[2*s] && !fol[2*s]) marc(2*s);
    if(val[2*s+1] && !fol[2*s+1]) marc(2*s+1);
}

bool check(int poz) {
    for(int i=1; i<=n; ++i)  {
        fol[i]=0;
        cpv[i]=v[i];
    }
    sort(cpv+1,cpv+poz+1,cmp2);
    int st=0;
    //deb(poz)
    for(int i=1,sel=0; i<=poz && sel<k; ++i) if(!fol[cpv[i].ind]) {
        st+=cpv[i].sum;
        //deb(st)
        if(st>=s) return 1;
        marc(cpv[i].ind);
        ++sel;
    }
    return 0;
}

int main()
{
    freopen("recoltabin.in","r",stdin);
    freopen("recoltabin.out","w",stdout);
    scanf("%d %d %d",&n,&k,&s);
    for(int i=1; i<=n; ++i) scanf("%d",&val[i]);
    dfs(1);
    for(int i=1; i<=n; ++i) {
        v[i].mv=maxval[i];
        v[i].sum=sum[i];
        v[i].ind=i;
    }
    sort(v+1,v+n+1,cmp);
    int ls=1,ld=n,m,sol=1;
    for(;ls<ld;) {
        m=(ls+ld+1)>>1;
        //debnl
        if(check(m)) {
            sol=m;
            ld=m-1;
        }else ls=m;
    }
    for(;check(sol);--sol);
    //deb(sol)
    printf("%d",v[sol+1].mv);
    return 0;
}
