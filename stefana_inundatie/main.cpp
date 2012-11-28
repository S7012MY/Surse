#include <cstdio>
#include <algorithm>
#define BM 90005
using namespace std;

int sc[BM],dim,ns[BM];

int cb (int a){
    int ls=1,ld=dim,m;
    for(;ls<ld;){
        m=(ls+ld)/2;
        if(sc[m]>=a)ld=m;
        else ls=m+1;
    }
    for(;sc[ls]>=a;)--ls;
    return ls;
}
int main () {
    int i,j,n,q,m,e,c,mij,ls,ld;
    long long s=0;
    freopen("inundatie.in","r",stdin);
    freopen("inundatie.out","w",stdout);
    scanf("%d %d",&n,&m);

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            scanf("%d",&sc[++dim]);
    sort(sc+1,sc+1+dim);
	for(i=1;i<=dim;++i)ns[i]=sc[i]+ns[i-1];
    scanf("%d",&q);
    for(i=1;i<=q;++i){
        c=0;
        s=0;
        scanf("%d",&e);
        if(e==0){
            printf("0\n");
            ++c;
        }
        if(c==0){
            int indice=cb(e);

            printf("%d\n",ns[indice]+(dim-indice)*(e-1));
        }
    }
    return 0;
}
