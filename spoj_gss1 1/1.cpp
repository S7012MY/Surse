#include <cstdio>
#define DN 400005
#define LL long long

LL a[DN],b[DN],c[DN],d[DN],sum,rez;
int n,m,gls,gld,poz,el,v[DN];

static inline LL max(LL a,LL b) {
	if(a>=b) return a;
	return b;
}

static inline void build(int vn, int ls, int ld) {
    if(ls==ld) {
        a[vn]=b[vn]=c[vn]=v[ls];
        d[vn]=v[ls];
        return;
    }
    int m=(ls+ld)>>1,fs=vn<<1;
    build(fs,ls,m);
    build(fs+1,m+1,ld);
    a[vn]=max(a[fs],d[fs]+a[fs+1]);
    b[vn]=max(b[fs]+d[fs+1],b[fs+1]);
    c[vn]=max(max(c[fs],c[fs+1]),b[fs]+a[fs+1]);
    d[vn]=d[fs]+d[fs+1];
}

static inline void query(int vn, int ls, int ld) {
    if(gls<=ls && ld<=gld) {
       // if(0>sum) sum=0;
        rez=max(rez,max(sum+a[vn],c[vn]));
        sum=max(sum+d[vn],b[vn]);
        return;
    }
    int m=(ls+ld)>>1,fs=vn<<1;
    if(gls<=m) query(fs,ls,m);
    if(gld>m) query(fs+1,m+1,ld);
}

int main()
{
    scanf("%d",&n);
	int i;
    for(i=1; i<=n; ++i) {
        scanf("%d",&v[i]);
    }
	build(1,1,n);
	scanf("%d",&m);
    for(i=1; i<=m; ++i) {
        sum=rez=-9999999999LL;
        scanf("%d %d",&gls, &gld);
        query(1,1,n);
        printf("%lld\n",rez);
    }
    return 0;
}
