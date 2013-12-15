#include <cstdio>
#define DN 405

int t,n,m,h,w,rmq[2][9][DN][DN];

static inline int gcd(int u, int v){
    if(0==u)
        return v;
    if(0==v)
        return u;
    if(0==(u&1)){
        if(0==(v&1))
            return (gcd((u>>1), (v>>1))<<1);
        else
            return  gcd(u>>1, v);
    }
    else if(0==(v&1))
        return gcd(u, (v>>1));
    else{
        if(u>=v)
            return gcd(((u-v)>>1), v);
        else
            return gcd(((v-u)>>1), u);
    }
}

int gcd(int a,int b,int c,int d) {
    return gcd(gcd(a,b),gcd(c,d));
}

inline int max(int a,int b) {
    if(a>b) return a;
    return b;
}

int main()
{
    freopen("euclid.in","r",stdin);
	freopen("euclid.out","w",stdout);
	scanf("%d",&t);
	for(int T=1; T<=t; ++T) {
	    scanf("%d %d %d %d",&n,&m,&h,&w);
	    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) scanf("%d",&rmq[0][0][i][j]);
        for(int k=0; (1<<k)<=n; ++k) for(int l=0; (1<<l)<=m; ++l) {
            if(k+l==0) continue;
            for(int i=0; i+(1<<k)<=n; ++i) for(int j=0; j+(1<<l)<=m; ++j) {
                if(k) rmq[k&1][l][i][j]=gcd(rmq[(k&1)^1][l][i][j],rmq[(k&1)^1][l][i+(1<<(k-1))][j]);
                else  rmq[k&1][l][i][j]=gcd(rmq[k&1][l-1][i][j],rmq[k&1][l-1][i][j+(1<<(l-1))]);
            }
        }
        int rez=0,lgh,lgw;
        for(lgh=0;(1<<lgh)<=h; ++lgh); --lgh;
        for(lgw=0;(1<<lgw)<=w; ++lgw); --lgw;
        for(int i=0; i+h<=n; ++i) for(int j=0; j+w<=m; ++j) {
            int lh=(1<<lgh),lw=(1<<lgw);

            rez=max(rez,gcd(rmq[lgh&1][lgw][i][j],rmq[lgh&1][lgw][i+h-lh][j],
                            rmq[lgh&1][lgw][i][j+w-lw],rmq[lgh&1][lgw][i+h-lh][j+w-lw]));
        }
        printf("Case #%d: %d\n",T,rez);
	}
    return 0;
}
