#include <cstdio>
#define DN 100005
#define DV 1000005

int n,m,rez=-1,a[DN],b[DN],pre[DV],inc[DV];

int main()
{
    freopen("secvmin.in","r",stdin);
    freopen("secvmin.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; ++i) scanf("%d",&a[i]);
    for(int i=0; i<m; ++i) scanf("%d",&b[i]);
    for(int i=0; i<DV; ++i) inc[i]=pre[i]=-1;

    pre[b[0]]=0;
    for(int i=1; i<m; ++i) pre[b[i]]=b[i-1];
    for(int i=0; i<n; ++i) {
        inc[0]=i;
        if(pre[a[i]]>=0 && inc[pre[a[i]]]>=0)
            inc[a[i]]=inc[pre[a[i]]];
        if(a[i]==b[m-1]  && inc[a[i]]>=0) {
            int lgc=i-inc[a[i]]+1;
            if(0>rez || rez>lgc) rez=lgc;
        }
    }
    printf("%d",rez);
    return 0;
}
