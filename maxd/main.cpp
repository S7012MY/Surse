#include <cstdio>
#include <bitset>
#define DN 50005
using namespace std;

int a,b,pr[DN],sz,bnrd,cate,mic;
bitset<DN> isp;

int main()
{
    freopen("maxd.in","r",stdin);
    freopen("maxd.out","w",stdout);
    scanf("%d %d",&a,&b);
    int dr=min(DN-1,b);
    for(int i=2; i*i<=dr; ++i) if(0==isp[i])
        for(int j=i*i; j<=dr; j+=i) isp[j]=1;
    for(int i=2; i<=dr; ++i) if(0==isp[i]) pr[++sz]=i;
    for(int i=a; i<=b; ++i) {
        int nr=i,nrd=1;
        for(int j=1;nr>1 && j<=sz && nr>=pr[j]*pr[j]; ++j) if(0==nr%pr[j]) {
            int put=0,div=pr[j];
            for(;0==nr%div;div*=pr[j],++put);
            div/=pr[j];
            nr/=div;
            nrd*=(put+1);
        }
        if(nr>1) nrd<<=1;
        if(nrd>bnrd) {
            bnrd=nrd;
            cate=1;
            mic=i;
        }else if(nrd==bnrd) ++cate;
    }
    printf("%d %d %d",mic,bnrd,cate);
    return 0;
}
