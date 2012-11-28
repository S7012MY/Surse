#include <cstdio>
#include <bitset>
using namespace std;

bitset <30005>a;
int n,m,dim,prim[30005],pt[30005];

int main () {
    int i,j,x;
    freopen("exp.in","r",stdin);
    freopen("exp.out","w",stdout);
    for(i=2;i*i<=30000;++i){
        if(a[i]==0)
            for(j=i*i;j<=30000;j+=i)
                a[j]=1;
    }
    for(i=2;i<=30000;++i)if(a[i]==0)prim[++dim]=i;
    scanf("%d %d",&m,&n);

    for(i=1;i<=n;++i){
        scanf("%d",&x);
        if(x==1) continue;
        for(j=1;j<=dim&&prim[j]<=x;++j){
            for(;x%prim[j]==0;){
                //fprintf(stderr,"%d %d\n",prim[j],x);
                pt[j]++;
                x/=prim[j];
            }
        }
    }
   // fprintf(stderr,"%d",pt[2]);
    for(i=1;i<=dim;++i)
        if(pt[i]%m!=0){
            printf("0");
            return 0;
        }
    printf("1\n");
    for(i=1;i<=dim;++i)if(pt[i]!=0){
        printf("%d %d\n",prim[i],pt[i]/m);
    }
    return 0;
}

