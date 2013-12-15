#include<cstdio>
# define BM 3005
int a[3005];
int main () {
    int n,i,j,k,c=0;
    freopen("bete2.in","r",stdin);
    freopen("bete2.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",&a[i]);
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            for(k=1;k<=n;++k){
                if(a[i]==a[j]+a[k]&&i!=j&&j!=k&&i!=k)++c;
            }
    printf("%d",c/2);
    return 0;
}
