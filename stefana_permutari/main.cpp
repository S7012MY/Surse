#include <cstdio>

int a[9];

int valid(int x,int n){
    int i,j;
    if(a[x]>n)return 0;
    for(i=1;i<x;++i)
    for(j=i+1;j<=x;++j)
    if(a[i]==a[j]) return 0;
    return 1;
}

int main () {
    int n,i,pc=1;
    freopen("permutari.in","r",stdin);
    freopen("permutari.out","w",stdout);
    scanf("%d",&n);
    for(;pc>0;){
        ++a[pc];
        if(valid(pc,n)){
            if(pc==n){
                for(i=1;i<=n;++i)printf("%d ",a[i]);
                printf("\n");
            }
            ++pc;
        }
        else
        if(a[pc]>n){
            a[pc]=0;
            --pc;
        }

    }
    return 0;
}
