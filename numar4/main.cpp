#include <cstdio>
#define DN 2005

int ni,nz,a[DN],b[DN];

void imp(int x[], int y) {
    int i,r=0;
    i=x[0];
    for(;i;) {
        r=r*10+x[i];
        x[i]=r/y;
        r=r%y;
        i--;
    }
    for(;!x[x[0]];--x[0]);
}

void afis(int x[]) {
    for(int i=x[0];i>0; --i) printf("%d",x[i]);
}

int main()
{
    freopen("numar4.in","r",stdin);
    freopen("numar4.out","w",stdout);
    scanf("%d %d",&ni,&nz);
    int i;
    a[0]=ni+nz;
    for(i=ni+nz; i>0; --i) scanf("%d",&a[i]);
    b[0]=nz+1; b[nz+1]=1;
    for(i=nz;i!=0 && a[1]%2==0;) {
        imp(a,2);
        imp(b,2);
        --i;
    }
    for(i=nz;i!=0 && a[1]%5==0;) {
        imp(a,5);
        imp(b,5);
        --i;
    }
    printf("%d\n",a[0]);
    afis(a);
    printf("\n%d\n",b[0]);
    afis(b);
    return 0;
}
