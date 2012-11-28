#include <cstdio>
#include <cstring>
#define DL 1000005
#define DC 10005
using namespace std;

char tx[DL],c[DC];
int n,pi[DC],lg,lgc;

void p() {
    for(int i=2,q=0; i<=lgc; ++i) {
        for(;q!=0 && c[i]!=c[q+1];q=pi[q]);
        if(c[i]==c[q+1]) ++q;
        pi[i]=q;
    }
}

int main()
{
    freopen("ahocorasick.in","r",stdin);
    freopen("ahocorasick.out","w",stdout);
    scanf("%s %d",tx+1,&n);
    lg=strlen(tx+1);
    for(int k=1; k<=n; ++k) {
        scanf("%s",c+1);
        lgc=strlen(c+1);
        int pot=0;
        for(int i=0; i<=lgc; ++i) pi[i]=0;
        p();
        for(int i=1,q=0; i<=lg; ++i) {
            for(;q!=0 && tx[i]!=c[q+1]; q=pi[q]);
            if(tx[i]==c[q+1]) ++q;
            if(q==lgc) ++pot;
        }
        printf("%d\n",pot);
       // fprintf(stderr,"%d\n",pot);
    }
    return 0;
}
