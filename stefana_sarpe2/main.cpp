#include <cstdio>
int a[1005][1005],ma[1005][1005];
int n,m,s[100005],sx[];
int main () {
    int i,j;
    freopen("sarpe2.in","r",stdin);
    freopen("sarpe2.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;++i){
        scanf("%d",&j);
        s[j]=i;
    }
    for(i=1;i<=n;++i)for(j=1;j<=n;++j){
        scanf("%d",&a[i][j]);
        a[i][j]=s[a[i][j]];
        if(a[i][j]==1){

        }
    }



}
