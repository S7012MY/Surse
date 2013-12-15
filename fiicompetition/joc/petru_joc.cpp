#include <cstdio>
#define deb(n) fprintf(stderr,"%d ",(n));
#define debnl fprintf(stderr,"\n");
#define DN 20005
#define DV 105
#define MULT 9999999

int n,dp[DN][DV],d[DN],p[DN],rez=MULT;

inline int min(int a, int b) {
    if(a<b) return a;
    return b;
}

int main()
{
    freopen("joc.in","r",stdin);
    freopen("joc.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d %d",&d[i],&p[i]);
    for(int i=1; i<=n; ++i) for(int j=1; j<=100; ++j) dp[i][j]=MULT;
    dp[1][100]=1;
    if(p[1]<100) dp[1][100-p[1]]=0;
    for(int i=2; i<=n; ++i) for(int j=1; j<=100; ++j) {
        dp[i][min(100,j+d[i])]=min(dp[i-1][j]+1,dp[i][min(100,j+d[i])]);
        if(min(j+d[i],100)-p[i]>0)
            dp[i][min(j+d[i],100)-p[i]]=min(dp[i-1][j],dp[i][min(j+d[i],100)-p[i]]);
    }
    for(int i=1; i<=100; ++i) rez=min(rez,dp[n][i]);
    printf("%d",rez);
    return 0;
}
