#include <iostream>
#include <bitset>
#define DN 1000005
#define MOD 1000000007
#define LL long long
using namespace std;

bitset<DN> isp;
int f[DN];

int main()
{
    LL n,rez=1,i,j;
    cin>>n;
    f[0]=f[1]=1;
    for(int i=2; i<=n; ++i) {
        f[i]=f[i-1]+f[i-2];
        if(f[i]>MOD) f[i]-=MOD;
    }
    for(i=2; i+i<=n; ++i) if(0==isp[i]) {
        LL fc=0;
        for(j=i+i; j<=n; j+=i) {
            isp[j]=1;
            LL cj=j,put=0;
            for(;cj%i==0;cj/=i,++put);
            fc+=(f[n-j]*put);
        }
        fc+=f[n-i]+1;
        fc%=MOD;
        rez=(rez*fc)%MOD;
    }
    for(;i<=n; ++i) if(!isp[i]) rez=(rez*(f[n-i]+1))%MOD;
    cout<<rez;
    return 0;
}
