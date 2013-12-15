#include <cstdio>
#define DN 1000005
#define LL unsigned long long
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,m,v[DN],s[DN],sz,st[DN],dr[DN];
LL rez[DN];

inline int min(int a, int b) {
    if(a<b) return a;
    return b;
}

inline int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int main()
{
    freopen("nrsubsecv.in","r",stdin);
    freopen("nrsubsecv.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; ++i) scanf("%d",&v[i]);
    v[0]=v[n+1]=-1;
    s[0]=n+1;
    for(int i=n; i>0; --i) {
        for(;sz && v[s[sz]]>=v[i];--sz);
        st[i]=s[sz]-1;
        s[++sz]=i;
    }
    s[0]=sz=0;
    for(int i=1; i<=n; ++i) {
        for(;sz && v[s[sz]]>v[i];--sz);
        dr[i]=s[sz]+1;
        s[++sz]=i;
    }
    //for(int i=1; i<=n; ++i) deb(st[i])
   // debnl
   // for(int i=1; i<=n; ++i) deb(dr[i])
   // debnl

    for(int i=1; i<=n; ++i) {
        int cs=dr[i],cd=st[i];
        //deb(cs) deb(cd) debnl
        rez[v[i]]+=((i-cs+1LL)*1LL*(cd-i+1LL));
    }
    for(int i=1; i<DN; ++i) rez[i]+=rez[i-1];
    for(int i=1; i<=m; ++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%llu\n",rez[b]-rez[a-1]);
    }

    return 0;
}
