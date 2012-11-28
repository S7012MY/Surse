#include <cstdio>
#define DN 50005

int n,k,nr[DN],bst[DN],folr[DN];

int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int main()
{
    freopen("progresii.in","r",stdin);
    freopen("progresii.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(int l=1;l<=n; ++l) {
        int s,r;
        scanf("%d %d",&s,&r);
        //fprintf(stderr,"%d %d\n",s,r);
        if(nr[s]&&folr[r]) continue;
        for(int i=s; i<=k; ++i) if(nr[i]){
                for(int j=i+i; j<=k; j+=r) {
                    ++nr[j];
                    bst[j]=max(bst[j],bst[j-i]+1);
                }
        }
        for(int j=s; j<=k; j+=r) {
            ++nr[j];
            bst[j]=max(bst[j],bst[j-r]+1);
        }
        folr[r]=1;
    }
    printf("%d %d",nr[k],bst[k]);
    return 0;
}
