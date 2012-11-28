#include <cstdio>
#include <algorithm>
#define DN 1005
#define MOD 666013
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,m,a,b,v[DN],rez,ind[DN],aib[DN][DN];

bool cmp(const int &a, const int &b) {
    if(v[a]==v[b]) return a<b;
    return v[a]<v[b];
}

inline int lsb(int a) {
    return (a^(a-1))&a;
}

void upd(int mod, int p,int vl) {
    for(int i=p; i<=n; i+=lsb(i)) {
        aib[mod][i]+=vl;
        if(aib[mod][i]>=MOD) aib[mod][i]-=MOD;
    }
}

int query(int mod, int p) {
    int r=0;
    for(int i=p; i>0; i-=lsb(i)) {
        r+=aib[mod][i];
        if(r>=MOD) r-=MOD;
    }
    return r;
}

int main()
{
    freopen("subsiruri.in","r",stdin);
    freopen("subsiruri.out","w",stdout);
    scanf("%d %d %d %d",&n,&m,&a,&b);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&v[i]);
        ind[i]=i;
    }
    std::sort(ind+1,ind+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        for(int mod=0; mod<m; ++mod) {
            int rq=query(mod,ind[i]-1);
            upd((mod+v[ind[i]])%m,ind[i],rq);
        }
        upd(v[ind[i]]%m,ind[i],1);
    }
    for(int mod=a; mod<=b; ++mod) {
        rez+=query(mod,n);
        if(rez>=MOD) rez-=MOD;
    }
    printf("%d",rez);
    //deb(rez)
    return 0;
}
