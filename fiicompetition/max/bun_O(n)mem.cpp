#include <cstdio>
#define LL long long
#define DN 1000005
#define MULT -(1LL<<62)

int n;
LL dp[2][3][DN],rez,v;

inline LL max(LL a,LL b) {
    if(a>b)return a;
    return b;
}

int main()
{
    freopen("max.in","r",stdin);
    freopen("max.out","w",stdout);
    scanf("%d",&n);
    dp[0][0][0]=dp[0][1][0]=dp[0][2][0]=dp[1][0][0]=dp[1][1][0]=dp[1][2][0]=MULT;
    for(int i=1; i<=n; ++i) {
        scanf("%lld",&v);
        for(int s=0; s<2; ++s) for(int md=0; md<3; ++md) {
            dp[s][md][i]=MULT;
            if(md==0) dp[1][0][i]=max(dp[1][0][i],v);
            LL semn=1;
            if(!s) semn=-1;
            if(dp[s^1][(md-1+3)%3][i-1])
                dp[s][md][i]=max(dp[s][md][i],dp[s^1][(md-1+3)%3][i-1]+semn*(md+1)*v);

            dp[s][md][i]=max(dp[s][md][i],dp[s][md][i-1]);
            rez=max(rez,dp[s][md][i]);
           // cout<<s<<' '<<md<<' '<<i<<' '<<dp[s][md][i]<<'\n';
        }
    }
    printf("%lld",rez);
    return 0;
}
