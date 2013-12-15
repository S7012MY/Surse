#include <cstdio>

int a[19];

int valid(int x,int n){

    if(a[x]>n)return 0;
    if(a[x]<=a[x-1])return 0;
    return 1;
}

int main () {
    int n,k,i,pc=1;
    freopen ("combinari.in","r",stdin);
    freopen ("combinari.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(;pc>0;){
        ++a[pc];
        if(valid(pc,n)){
            if(pc==k){
                for(i=1;i<=k;++i)printf("%d ",a[i]);
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
