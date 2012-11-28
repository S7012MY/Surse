#include <cstdio>
#define DN 100005
#define LL long long
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");

int n,m,v[DN],s[DN],sz,st[DN],dr[DN],ls[DN],ld[DN];
LL rez[DN],sp[DN];

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
    for(int i=n; i>0; --i) {
        st[i]=i;
        for(;sz && v[s[sz]]>=v[i];--sz);
        if(sz) st[i]=s[sz];
        s[++sz]=i;
    }
    sz=0;
    for(int i=1; i<=n; ++i) {
        dr[i]=i;
        for(;sz && v[s[sz]]>=v[i];--sz);
        if(sz) dr[i]=s[sz];
        s[++sz]=i;
    }
    //for(int i=1; i<=n; ++i) deb(st[i])
   // debnl
   // for(int i=1; i<=n; ++i) deb(dr[i])
   // debnl

    for(int i=1; i<=n; ++i) {
        int cs=dr[i],cd=st[i];
        if(v[cs]>=v[i]) cs=1;
        else ++cs;
        if(v[cd]>=v[i]) cd=n;
        else --cd;
        //deb(cs) deb(cd) debnl

        if(rez[v[i]]){
            int lcs=ls[v[i]],lcd=ld[v[i]];
            deb(lcs) deb(lcd) deb(cs) deb(cd) debnl
            if(lcd>=cs) {
                rez[v[i]]-=(i-lcs+1)*1LL*(lcd-i+1);
                cs=min(lcs,cs); cd=max(cd,lcd);
            }
        }
        rez[v[i]]+=(i-cs+1)*1LL*(cd-i+1);
        ls[v[i]]=cs; ld[v[i]]=cd;
    }
    for(int i=1; i<DN; ++i) sp[i]=sp[i-1]+rez[i];
    for(int i=1; i<=m; ++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%lld\n",sp[b]-sp[a-1]);
    }

    return 0;
}
