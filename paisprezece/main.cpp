#include <cstdio>
#include <bitset>
using namespace std;

bitset<1000005> isp;
long long a,b,szp;
//bool isp[1000005];
int pr[100005];

long long lgput(long long x, long long y) {
    long long rez=1;
    for(;y;) {
        for(;0==y%2;) {
            y/=2LL;
            x*=x;
        }
        --y;
        rez*=x;
        if(rez>b) return -1;
    }
    return rez;
}

int main()
{
    freopen("paisprezece.in","r",stdin);
    freopen("paisprezece.out","w",stdout);
    scanf("%lld %lld",&a,&b);
    for(int i=2; i<=1000000; ++i) if(0==isp[i]){
        pr[++szp]=i;
        for(long long j=i*1LL*i; j<=1000000; j+=i) isp[j]=1;
    }
    //return 0;
    int rez=0;
    for(int i=1;pr[i]<=21 && i<=szp; ++i) {
        long long r=-1;
        if(pr[i]<4) r=lgput(pr[i],13);
        if(r>0 && a<=r && b>=r) ++rez;
        for(int j=1; j<=szp; ++j) if(i!=j){
            r=lgput(pr[i],6)*pr[j];
            if(r>0 && a<=r && b>=r) ++rez;
            if(r>b) break;
        }
    }
    printf("%d",rez);
    return 0;
}
