#include <cstdio>
#define DN 2000001

int n,p[DN],s[DN],sz,szp,cc[DN];
long long K;

void trans() {
    for(sz=n;sz;sz>>=1) {
        for(int i=(sz>>1)+1;i<=sz; ++i) p[++szp]=i;
    }
}

void find(int su) {
    int i=su,nr,j,k,pr;
    sz=0;
    cc[sz++]=i;
    for(i=p[i];i!=su;i=p[i]) cc[sz++]=i;
    nr=K%sz;
    for(int i=0; i<sz; ++i) s[cc[i]]=cc[(i+nr)%sz];
}

int main()
{
    freopen("shuffle.in","r",stdin);
    freopen("shuffle.out","w",stdout);
    scanf("%d %lld",&n,&K);
    trans();
    for(int i=1; i<=n; ++i) if(!s[i]) find(i);
    int ret=0;
    for(int i=1; i<=n; i++) {
        //fprintf(stderr,"%d ",s[i]);
        ret=(ret*13+s[i])%1299827;
    }
    printf("%d",ret);
    return 0;
}
