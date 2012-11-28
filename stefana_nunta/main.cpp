#include <cstdio>

int a[10005],b[10005];

void add(int a[],int b[]){
    int c=0,i;
    for(i=1;i<=b[0]||c;++i){
        a[i]=c+a[i]+b[i];
        c=a[i]/10;
        a[i]%=10;
    }
    a[0]=i-1;
}
void afis(int a[]){
    for(int i=a[0];i;--i)printf("%d",a[i]);
    printf("\n");
}

int main () {
    int i,n;
    freopen("nunta.in","r",stdin);
    freopen("nunta.out","w",stdout);
    scanf("%d",&n);
    a[0]=b[0]=a[1]=1;
    b[1]=2;
    for(i=1;i<=n-2;++i){

        if(i&1) add(a,b);
        else add(b,a);

    }
   if(n&1) afis(a);
    else afis(b);
    return 0;
}
