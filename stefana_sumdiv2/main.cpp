#include <cstdio>

long long sd[1000005],sdf[1000005];

int main () {
    int n,x,y,i,j;
    freopen("sumdiv2.in","r",stdin);
    freopen("sumdiv2.out","w",stdout);
    sd[1]=sdf[1]=1;
    for(i=2;i<=1000000;++i){
       ++sd[i];
       for(j=i;j<=1000000;j+=i)
            sd[j]+=i;
        sdf[i]=sdf[i-1]+sd[i];
    }
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d %d",&x,&y);
        printf("%lld\n",sdf[y]-sdf[x-1]);
    }
    return 0;
}
